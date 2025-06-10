import matplotlib.pyplot as plt

# 数据1: Cache容量为64KB时的不同相联度下不命中率
associativity_64KB = [1, 2, 4, 8, 16, 32]
miss_rate_64KB = [0.89, 0.53, 0.47, 0.45, 0.44, 0.44]

# 数据2: Cache容量为256KB时的不同相联度下不命中率
associativity_256KB = [1, 2, 4, 8, 16, 32]
miss_rate_256KB = [0.49, 0.38, 0.36, 0.36, 0.35, 0.35]

# 绘制曲线
plt.plot(associativity_64KB, miss_rate_64KB, marker='o', linestyle='-', label='Cache容量：64KB')
plt.plot(associativity_256KB, miss_rate_256KB, marker='o', linestyle='-', label='Cache容量：256KB')

# 添加标签和标题
plt.xlabel('associativity')
plt.ylabel('miss rate (%)')
plt.title('miss rate change')

# 添加图例
plt.legend()

# 显示图形
plt.show()
