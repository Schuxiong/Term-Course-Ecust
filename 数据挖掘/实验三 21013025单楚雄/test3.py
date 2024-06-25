from sklearn.cluster import KMeans
import numpy as np
import matplotlib.pyplot as plt

def load_data(filename):
    """加载data.txt文件中的数据"""
    data = []
    with open(filename, 'r') as file:
        for line in file:
            # 假设数据点中的每个维度用空格分隔
            data.append(list(map(float, line.strip().split())))
    return np.array(data)

filename = "data.txt"

# 加载数据
data = load_data(filename)

# 实现k均值聚类算法并测试不同k值的聚类结果
k_values = [5, 10, 20]
results = {}

for k in k_values:
    # 运行k均值算法
    kmeans = KMeans(n_clusters=k, random_state=0)
    kmeans.fit(data)
    results[k] = kmeans.inertia_  # 记录每个k值下的聚类结果（惯性，即内部距离和）

# 绘制结果
plt.rcParams['font.sans-serif'] = ['SimHei']  # 用来正常显示中文标签
plt.rcParams['axes.unicode_minus'] = False  # 用来正常显示负号
plt.figure(figsize=(10, 6))
plt.plot(results.keys(), results.values(), marker='o')
plt.title('k均值聚类 - 不同k值的内部距离和')
plt.xlabel('k值')
plt.ylabel('内部距离和')
plt.grid(True)
plt.show()
