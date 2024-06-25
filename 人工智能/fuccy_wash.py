import numpy as np

sludge = [0, 0.5, 1]
grease = [0, 0.5, 1]
time = [0, 0.25, 0.5, 0.75, 1]
sludgeandgrease = np.zeros((len(sludge), len(grease)))

##########隶属度规则###########
for i in range(len(sludge)):
    for j in range(len(grease)):
        sludgeandgrease[i, j] = max(sludge[i], grease[j])
sludgeandgrease = sludgeandgrease.reshape(9, 1)
R = np.zeros((len(sludgeandgrease), len(time)))
for i in range(len(sludgeandgrease)):
    for j in range(len(time)):
        R[i, j] = min(sludgeandgrease[i], time[j])

###############################

x1 = [0, 0.83, 0.6]
y1 = [0, 0.71, 0.7]
x1y1 = np.zeros((len(x1), len(y1)))

for i in range(len(x1)):
    for j in range(len(y1)):
        x1y1[i, j] = max(x1[i], y1[j])
x1y12 = x1y1.reshape(9)

result = np.zeros(5)
a = np.zeros(9)
for i in range(5):
    for j in range(9):
        a[j] = x1y12[j] * R[j, i]
    result[i] = max(a)

print(result)
