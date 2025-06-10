import tensorflow as tf

from tensorflow.keras.datasets import mnist
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense, Dropout, Flatten, Input
from tensorflow.keras.utils import to_categorical
import matplotlib.pyplot as plt

# 加载MNIST数据集
(x_train, y_train), (x_test, y_test) = mnist.load_data()

# 预处理数据，将像素值缩放到0到1之间
x_train = x_train / 255.0
x_test = x_test / 255.0

# 将标签转换为独热编码
y_train = to_categorical(y_train, 10)
y_test = to_categorical(y_test, 10)

# 创建模型
model = Sequential([
    Input(shape=(28, 28)),
    Flatten(),
    Dense(500, activation='relu'),
    Dense(1000, activation='relu'),
    Dense(300, activation='relu'),
    Dense(10, activation='softmax')
])

# 编译模型
model.compile(optimizer='adam',
              loss='categorical_crossentropy',
              metrics=['accuracy'])

# 自定义训练循环
batch_size = 100
epochs = 5
num_batches = x_train.shape[0] // batch_size

# 保存训练和验证的损失和准确性
history = {'loss': [], 'val_loss': [], 'accuracy': [], 'val_accuracy': []}

@tf.function
def train_step(x_batch, y_batch):
    with tf.GradientTape() as tape:
        predictions = model(x_batch, training=True)
        loss = model.compute_loss(x_batch, y_batch, predictions)
    gradients = tape.gradient(loss, model.trainable_variables)
    model.optimizer.apply_gradients(zip(gradients, model.trainable_variables))
    return loss

@tf.function
def test_step(x_batch, y_batch):
    predictions = model(x_batch, training=False)
    loss = model.compute_loss(x_batch, y_batch, predictions)
    accuracy = tf.reduce_mean(tf.cast(tf.equal(tf.argmax(predictions, axis=1), tf.argmax(y_batch, axis=1)), tf.float32))
    return loss, accuracy


for epoch in range(epochs):
    print(f"Epoch {epoch + 1}/{epochs}")
    for i in range(num_batches):
        batch_start = i * batch_size
        batch_end = batch_start + batch_size
        x_batch = x_train[batch_start:batch_end]
        y_batch = y_train[batch_start:batch_end]

        train_loss = train_step(x_batch, y_batch)

        if i % 50 == 0:
            test_loss, test_acc = test_step(x_test, y_test)
            print(f"Batch {i}, 训练loss: {train_loss:.4f}, 测试loss: {test_loss:.4f}, 测试准确率: {test_acc:.4f}")

            history['loss'].append(train_loss)
            history['val_loss'].append(test_loss)
            history['accuracy'].append(model.evaluate(x_batch, y_batch, verbose=0)[1])
            history['val_accuracy'].append(test_acc)

# 评估模型
test_loss, test_acc = model.evaluate(x_test, y_test)
print(f'Test accuracy: {test_acc:.4f}')

# 保存模型
# model.save('my_model.keras')

# 绘制训练和验证的损失曲线
plt.figure(figsize=(10, 6))
plt.plot(history['loss'], label='Training Loss')
plt.plot(history['val_loss'], label='Validation Loss')
plt.title('Training and Validation Loss')
plt.xlabel('Epochs')
plt.ylabel('Loss')
plt.legend()
plt.show()
