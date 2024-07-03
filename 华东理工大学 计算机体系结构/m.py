import matplotlib.pyplot as plt

# 定义数据
capacity = [2, 4, 8, 16, 32, 64, 128, 256]
miss_rate = [9.87, 7.19, 4.48, 2.65, 1.42, 0.89, 0.60, 0.49]

# 绘制曲线
plt.plot(capacity, miss_rate, marker='o', linestyle='-', color='b')

# 添加标签和标题
plt.xlabel('Cachecapacity (KB)')
plt.ylabel(' miss rate(%)')
plt.title('Cachecapacity change curve')

# 显示图形
plt.show()
