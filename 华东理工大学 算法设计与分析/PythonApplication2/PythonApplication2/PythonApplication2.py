import numpy as np
import matplotlib.pyplot as plt

# 定义输入变量的隶属函数
sludge = np.array([0, 0.5, 1])
sludge_membership = {'LD': [1, 0, 0], 'MD': [0, 1, 0], 'SD': [0, 0, 1]}

grease = np.array([0, 0.5, 1])
grease_membership = {'LG': [1, 0, 0], 'MG': [0, 1, 0], 'NG': [0, 0, 1]}

# 定义输出变量的隶属函数
time = np.array([0, 0.25, 0.5, 0.75, 1])
time_membership = {'WL': [1, 0, 0, 0, 0], 'L': [0, 1, 0, 0, 0], 'M': [0, 0, 1, 0, 0], 'S': [0, 0, 0, 1, 0], 'VS': [0, 0, 0, 0, 1]}

# 绘制输入变量的隶属函数图
plt.figure(figsize=(10, 5))

plt.subplot(1, 2, 1)
plt.plot(sludge, sludge_membership['LD'], label='LD')
plt.plot(sludge, sludge_membership['MD'], label='MD')
plt.plot(sludge, sludge_membership['SD'], label='SD')
plt.title('Sludge Membership')
plt.xlabel('Sludge')
plt.ylabel('Membership')
plt.legend()

plt.subplot(1, 2, 2)
plt.plot(grease, grease_membership['LG'], label='LG')
plt.plot(grease, grease_membership['MG'], label='MG')
plt.plot(grease, grease_membership['NG'], label='NG')
plt.title('Grease Membership')
plt.xlabel('Grease')
plt.ylabel('Membership')
plt.legend()

plt.tight_layout()
plt.show()

# 绘制输出变量的隶属函数图
plt.figure(figsize=(10, 5))

plt.plot(time, time_membership['WL'], label='WL')
plt.plot(time, time_membership['L'], label='L')
plt.plot(time, time_membership['M'], label='M')
plt.plot(time, time_membership['S'], label='S')
plt.plot(time, time_membership['VS'], label='VS')
plt.title('Time Membership')
plt.xlabel('Time')
plt.ylabel('Membership')
plt.legend()

plt.show()

# 定义模糊控制规则
rules = {
    ('SD', 'NG'): 'VS',
    ('MD', 'MG'): 'M',
    ('LD', 'LG'): 'S'
}

# 模糊推理
def fuzzy_inference(sludge_level, grease_level):
    result = np.zeros(len(time))
    for sludge_key, grease_key in rules.keys():
        sludge_mem = sludge_membership[sludge_key]
        grease_mem = grease_membership[grease_key]
        output_mem = time_membership[rules[(sludge_key, grease_key)]]
        min_membership = min(sludge_mem[sludge_level], grease_mem[grease_level])
        result = np.maximum(result, np.minimum(min_membership, output_mem))
    return result

# 自己假定的传感器测量结果
current_sludge = 0.2  # 假定污泥量为中等
current_grease = 0.7  # 假定油脂量为多

# 模糊推理得到洗涤时间
inferred_time = fuzzy_inference(1, 0)

# 打印推理结果
print("Inferred Time Memberships:")
print(inferred_time)

# 绘制推理结果
plt.plot(time, inferred_time)
plt.title('Inferred Time Memberships')
plt.xlabel('Time')
plt.ylabel('Membership')
plt.show()
from mpl_toolkits.mplot3d import Axes3D

# 模糊推理结果的三维表示
fig = plt.figure(figsize=(8, 6))
ax = fig.add_subplot(111, projection='3d')

# 生成网格点
X, Y = np.meshgrid(sludge, grease)
Z = np.zeros_like(X)

# 计算每个网格点的洗涤时间隶属度
for i in range(len(sludge)):
    for j in range(len(grease)):
        inferred_time = fuzzy_inference(i, j)
        Z[i, j] = np.argmax(inferred_time)

# 绘制立体图
ax.plot_surface(X, Y, Z, cmap='viridis')

# 设置坐标轴标签
ax.set_xlabel('Sludge')
ax.set_ylabel('Grease')
ax.set_zlabel('Time')

# 设置标题
ax.set_title('Fuzzy Inference Result')

plt.show()




# Define fuzzy decision function
def fuzzy_decision(inferred_time):
    max_index = np.argmax(inferred_time)
    return time[max_index]

# 用户输入油脂和污泥的量
user_grease = float(input("grease:"))
user_sludge = float(input("stain:"))

# 将用户输入的浮点数转换为对应的整数索引
grease_index = int(user_grease * (len(grease) - 1))
sludge_index = int(user_sludge * (len(sludge) - 1))

# 模糊推理得到洗涤时间
inferred_time = fuzzy_inference(sludge_index, grease_index)


# Perform fuzzy decision
decision = fuzzy_decision(inferred_time)

# Print the fuzzy decision result
print("Based on the input grease and sludge levels, the inferred washing time is:", decision)
