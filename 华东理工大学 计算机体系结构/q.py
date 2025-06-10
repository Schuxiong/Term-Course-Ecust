import matplotlib.pyplot as plt

# 定义数据
associativity = [1, 2, 4, 8, 16, 32]
miss_rate = [0.89, 0.53, 0.47, 0.45, 0.44, 0.44]

# 绘制曲线
plt.plot(associativity, miss_rate, marker='o', linestyle='-', color='b')

# 添加标签和标题
plt.xlabel('Associativity')
plt.ylabel('miss rate (%)')
plt.title('missrate change（Cache容量：64KB）')

# 显示图形
plt.show()
