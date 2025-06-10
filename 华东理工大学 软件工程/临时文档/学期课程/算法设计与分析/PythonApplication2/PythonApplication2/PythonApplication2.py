import numpy as np
import matplotlib.pyplot as plt

# ���������������������
sludge = np.array([0, 0.5, 1])
sludge_membership = {'LD': [1, 0, 0], 'MD': [0, 1, 0], 'SD': [0, 0, 1]}

grease = np.array([0, 0.5, 1])
grease_membership = {'LG': [1, 0, 0], 'MG': [0, 1, 0], 'NG': [0, 0, 1]}

# ���������������������
time = np.array([0, 0.25, 0.5, 0.75, 1])
time_membership = {'WL': [1, 0, 0, 0, 0], 'L': [0, 1, 0, 0, 0], 'M': [0, 0, 1, 0, 0], 'S': [0, 0, 0, 1, 0], 'VS': [0, 0, 0, 0, 1]}

# ���������������������ͼ
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

# ���������������������ͼ
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

# ����ģ�����ƹ���
rules = {
    ('SD', 'NG'): 'VS',
    ('MD', 'MG'): 'M',
    ('LD', 'LG'): 'S'
}

# ģ������
def fuzzy_inference(sludge_level, grease_level):
    result = np.zeros(len(time))
    for sludge_key, grease_key in rules.keys():
        sludge_mem = sludge_membership[sludge_key]
        grease_mem = grease_membership[grease_key]
        output_mem = time_membership[rules[(sludge_key, grease_key)]]
        min_membership = min(sludge_mem[sludge_level], grease_mem[grease_level])
        result = np.maximum(result, np.minimum(min_membership, output_mem))
    return result

# �Լ��ٶ��Ĵ������������
current_sludge = 0.2  # �ٶ�������Ϊ�е�
current_grease = 0.7  # �ٶ���֬��Ϊ��

# ģ������õ�ϴ��ʱ��
inferred_time = fuzzy_inference(1, 0)

# ��ӡ������
print("Inferred Time Memberships:")
print(inferred_time)

# ����������
plt.plot(time, inferred_time)
plt.title('Inferred Time Memberships')
plt.xlabel('Time')
plt.ylabel('Membership')
plt.show()
from mpl_toolkits.mplot3d import Axes3D

# ģ������������ά��ʾ
fig = plt.figure(figsize=(8, 6))
ax = fig.add_subplot(111, projection='3d')

# ���������
X, Y = np.meshgrid(sludge, grease)
Z = np.zeros_like(X)

# ����ÿ��������ϴ��ʱ��������
for i in range(len(sludge)):
    for j in range(len(grease)):
        inferred_time = fuzzy_inference(i, j)
        Z[i, j] = np.argmax(inferred_time)

# ��������ͼ
ax.plot_surface(X, Y, Z, cmap='viridis')

# �����������ǩ
ax.set_xlabel('Sludge')
ax.set_ylabel('Grease')
ax.set_zlabel('Time')

# ���ñ���
ax.set_title('Fuzzy Inference Result')

plt.show()




# Define fuzzy decision function
def fuzzy_decision(inferred_time):
    max_index = np.argmax(inferred_time)
    return time[max_index]

# �û�������֬���������
user_grease = float(input("grease:"))
user_sludge = float(input("stain:"))

# ���û�����ĸ�����ת��Ϊ��Ӧ����������
grease_index = int(user_grease * (len(grease) - 1))
sludge_index = int(user_sludge * (len(sludge) - 1))

# ģ������õ�ϴ��ʱ��
inferred_time = fuzzy_inference(sludge_index, grease_index)


# Perform fuzzy decision
decision = fuzzy_decision(inferred_time)

# Print the fuzzy decision result
print("Based on the input grease and sludge levels, the inferred washing time is:", decision)
