import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score, recall_score
from sklearn.svm import SVC

# 读取训练集数据
with open('train_sample.txt') as f:
    # 移除每一行的尾随空字符串
    lines = [line.rstrip() for line in f]
    X_train = np.loadtxt(lines, delimiter=' ')
with open('train_sample_label.txt') as f:
    y_train = np.loadtxt(f, dtype=int)

# 读取测试集数据
with open('test_sample.txt') as f:
    # 移除每一行的尾随空字符串
    lines = [line.rstrip() for line in f]
    X_test = np.loadtxt(lines, delimiter=' ')
with open('test_sample_label.txt') as f:
    y_test = np.loadtxt(f, dtype=int)

# 创建SVM模型
svm = SVC(kernel='linear', probability=True)

# 训练模型
svm.fit(X_train, y_train)

# 测试模型
y_pred = svm.predict(X_test)

# 计算准确率和查全率
accuracy = accuracy_score(y_test, y_pred)
recall = recall_score(y_test, y_pred)

print("准确率：", accuracy)
print("查全率：", recall)
