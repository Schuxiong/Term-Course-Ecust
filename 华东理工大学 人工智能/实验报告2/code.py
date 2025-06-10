#!/usr/bin/python
# -*- coding: UTF-8 -*-
import numpy as np
import skfuzzy as fuzz
import matplotlib
matplotlib.use('TkAgg')
import matplotlib.pyplot as plt
from skfuzzy import control as ctrl

# Define input and output ranges
# Sludge and grease ranges are [0, 100]
# Washing time range is [0, 120]
x_stain = np.arange(0, 101, 1)
x_oil = np.arange(0, 101, 1)
x_time = np.arange(0, 121, 1)
# Define fuzzy control variables
stain = ctrl.Antecedent(x_stain, 'stain')
oil = ctrl.Antecedent(x_oil, 'oil')
time = ctrl.Consequent(x_time, 'time')
# Generate fuzzy membership functions
stain['SD'] = fuzz.trimf(x_stain, [0, 0, 50])  
stain['MD'] = fuzz.trimf(x_stain, [0, 50, 100])
stain['LD'] = fuzz.trimf(x_stain, [50, 100, 100])
oil['NG'] = fuzz.trimf(x_oil, [0, 0, 50]) 
oil['MG'] = fuzz.trimf(x_oil, [0, 50, 100])
oil['LG'] = fuzz.trimf(x_oil, [50, 100, 100])
time['VS'] = fuzz.trimf(x_time, [0, 0, 20]) 
time['S'] = fuzz.trimf(x_time, [0, 20, 50])
time['M'] = fuzz.trimf(x_time, [20, 50, 80])
time['L'] = fuzz.trimf(x_time, [50, 80, 120])
time['VL'] = fuzz.trimf(x_time, [80, 120, 120])

# Use centroid defuzzification method
time.defuzzify_method = 'centroid'

# Rules
rule1 = ctrl.Rule(antecedent=((stain['SD'] & oil['NG'])), consequent=time['VS'], label='time=VS')
rule2 = ctrl.Rule(antecedent=((stain['SD'] & oil['MG'])|(stain['MD'] & oil['MG'])|(stain['LD'] & oil['NG'])), consequent=time['M'], label='time=M')
rule3 = ctrl.Rule(antecedent=((stain['SD'] & oil['LG'])|(stain['MD'] & oil['LG'])|(stain['LD'] & oil['MG'])), consequent=time['L'], label='time=L')
rule4 = ctrl.Rule(antecedent=((stain['MD'] & oil['NG'])), consequent=time['S'], label='time=S')
rule5 = ctrl.Rule(antecedent=((stain['LD'] & oil['LG'])), consequent=time['VL'], label='time=VL')

# System and runtime environment initialization
rule = [rule1, rule2, rule3, rule4, rule5]
time_ctrl = ctrl.ControlSystem(rule)
wash_time = ctrl.ControlSystemSimulation(time_ctrl)
# Handle some strange characters in the rules and output
for i in range(len(rule)):
    print("rule",i,end=":")
    for item in str(rule[i]):
        if(item!='\n'):
            print(item,end="")
        else:
            break
    print('\t')
# Plot
stain.view()
oil.view()
time.view()
plt.show()
# Plot 3D graph
upsampled = np.linspace(0, 101, 21)
x, y = np.meshgrid(upsampled, upsampled)
z = np.zeros_like(x)
pp = []
for i in range(0, 21):
    for j in range(0, 21):
        wash_time.input['stain'] = x[i, j]
        wash_time.input['oil'] = y[i, j]
        wash_time.compute()
        z[i, j] = wash_time.output['time']
        pp.append(z[i, j])
print('max:', max(pp))
print('min:', min(pp))
from mpl_toolkits.mplot3d import Axes3D
fig = plt.figure(figsize=(8, 8))
ax = fig.add_subplot(111, projection='3d')
surf = ax.plot_surface(x, y, z, rstride=1, cstride=1, cmap='PiYG_r', linewidth=0.1, antialiased=True)
ax.view_init(20, 270)
plt.title('3D results')
ax.set_xlabel('stain')
ax.set_ylabel('oil')
ax.set_zlabel('time')
plt.show()

import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

# Import NumPy for mathematical operations
import numpy as np

# Add input value checking in the Sludge and Grease functions
def Sludge(a):
    sludge = [0, 0, 0]  
    if a < 0:
        a = 0
    elif a > 100:
        a = 100
    if 0 <= a <= 50:
        sludge[0] = (50 - a) / 50
        sludge[1] = a / 50
    elif 50 < a <= 100:
        sludge[1] = (100 - a) / 50
        sludge[2] = (a - 50) / 50
    return sludge

def Grease(a):
    grease = [0, 0, 0]  
    if a < 0:
        a = 0
    elif a > 100:
        a = 100
    if 0 <= a <= 50:
        grease[0] = (50 - a) / 50
        grease[1] = a / 50
    elif 50 < a <= 100:
        grease[1] = (100 - a) / 50
        grease[2] = (a - 50) / 50
    return grease


# Rule premise reasoning and taking the minimum value
def Rules(a, b):  
    rules_value = [0, 0, 0, 0, 0, 0, 0, 0, 0]  
    if a[0] != 0 and b[0] != 0:
        rules_value[0] = min(a[0], b[0])
    if a[0] != 0 and b[1] != 0:
        rules_value[1] = min(a[0], b[1])
    if a[0] != 0 and b[2] != 0:
        rules_value[2] = min(a[0], b[2])
    if a[1] != 0 and b[0] != 0:
        rules_value[3] = min(a[1], b[0])
    if a[1] != 0 and b[1] != 0:
        rules_value[4] = min(a[1], b[1])
    if a[1] != 0 and b[2] != 0:
        rules_value[5] = min(a[1], b[2])
    if a[2] != 0 and b[0] != 0:
        rules_value[6] = min(a[2], b[0])
    if a[2] != 0 and b[1] != 0:
        rules_value[7] = min(a[2], b[1])
    if a[2] != 0 and b[2] != 0:
        rules_value[8] = min(a[2], b[2])
    return rules_value


# Create a list of time steps
time_steps = np.arange(0, 100, 1)

# List to store fuzzy output values
output_values = []

# Create an initial sensor input
x0 = 60  
y0 = 70  

# Simulate fuzzy inference process
for t in time_steps:
    x = x0
    y = y0
    sludge_membership = Sludge(x)
    grease_membership = Grease(y)
    rule_results = Rules(sludge_membership, grease_membership)
    final_output = max(rule_results)
    output_values.append(final_output)
    x0 += 1
    y0 += 1

# Create a graph window
fig, ax = plt.subplots()

# Set initial graph
line, = ax.plot([], [])
ax.set_xlim(0, len(time_steps))
ax.set_ylim(0, 1)
ax.set_xlabel("Time Step")
ax.set_ylabel("Fuzzy Output")
ax.set_title("Fuzzy Logic Control Simulation")


# Update function
def update(frame):
    line.set_data(time_steps[:frame + 1], output_values[:frame + 1])
    return line,


# Create animation
ani = FuncAnimation(fig, update, frames=len(time_steps), blit=True, repeat=False)
plt.show()



# 1. Sludge membership calculation
def Sludge(a):
    sludge = [0, 0, 0]  
    if a < 0 or a > 100:
        return (print("Input value error"))
    elif 0 <= a <= 50:
        sludge[0] = (50 - a) / 50
        sludge[1] = a / 50
    elif 50 < a <= 100:
        sludge[1] = (100 - a) / 50    
        sludge[2] = (a - 50) / 50      
    return sludge

# 2. Grease membership calculation
def Grease(a):
    grease = [0, 0, 0]  
    if a < 0 or a > 100:
        return (print("Input value error"))
    elif 0 <= a <= 50:
        grease[0] = (50 - a) / 50
        grease[1] = a / 50
    elif 50 < a <= 100:
        grease[1] = (100 - a) / 50   
        grease[2] = (a - 50) / 50   
    return grease

# 3. Rule premise reasoning and taking the minimum value
def Rules(a, b):  
    rules_value = [0, 0, 0, 0, 0, 0, 0, 0, 0]  
    if a[0] != 0 and b[0] != 0:
        rules_value[0] = min(a[0], b[0])  
    if a[0] != 0 and b[1] != 0:
        rules_value[1] = min(a[0], b[1])
    if a[0] != 0 and b[2] != 0:
        rules_value[2] = min(a[0], b[2])
    if a[1] != 0 and b[0] != 0:
        rules_value[3] = min(a[1], b[0])
    if a[1] != 0 and b[1] != 0:
        rules_value[4] = min(a[1], b[1])
    if a[1] != 0 and b[2] != 0:
        rules_value[5] = min(a[1], b[2])
    if a[2] != 0 and b[0] != 0:
        rules_value[6] = min(a[2], b[0])
    if a[2] != 0 and b[1] != 0:
        rules_value[7] = min(a[2], b[1])
    if a[2] != 0 and b[2] != 0:
        rules_value[8] = min(a[2], b[2])
    return rules_value

# 4. Inference of each rule output
def Inference(a):  
    time_level = [0, 0, 0, 0, 0]  
    time_level[0] = a[0]    
    time_level[1] = a[3]    
    if (a[1] != 0 or a[4] != 0 or a[6] != 0):  
        list_1 = [a[1], a[4], a[6]]
        for i in range(len(list_1) - 1, -1, -1):
            if list_1[i] == 0:
                list_1.remove(0)
        time_level[2] = min(list_1)
    if (a[2] != 0 or a[5] != 0 or a[7] != 0):
        list_2 = [a[2], a[5], a[7]]
        for i in range(len(list_2) - 1, -1, -1):
            if list_2[i] == 0:
                list_2.remove(0)
        time_level[3] = min(list_2)
    time_level[4] = a[8]
    return time_level

# 5. According to the weighted average decision method, use the corresponding membership degree to obtain the corresponding value in the time domain according to the inverse function of the washing time membership function
def Max_membership(a):  
    time = [0, 0, 0, 0, 0, 0, 0, 0]  
    time[0] = 30 - 30 * a[0]
    time[1] = 30 * a[1]
    time[2] = 60 - 30 * a[1]
    time[3] = 30 * a[2] + 30
    time[4] = 90 - 30 * a[2]
    time[5] = 30 * a[3] + 60
    time[6] = 120 - 30 * a[3]
    time[7] = 30 * a[4] + 90
    sum_1 = time[0] * a[0] + time[1] * a[1] + time[2] * a[1] + time[3] * a[2] + time[4] * a[2] + time[5] * a[3] + time[
        6] * a[3] + time[7] * a[4]
    sum_2 = a[0] + 2 * a[1] + 2 * a[2] + 2 * a[3] + a[4]
    result = sum_1 / sum_2
    return result

# Washing time membership function
def WashTime(a):  
    if 0 <= a <= 30:
        u1 = (30 - a) / 30
        u2 = a / 30
        if (u1 > u2):
            time_level = 'VS'
        else:
            time_level = 'S'
    if 30 < a <= 60:
        u3 = (60 - a) / 30
        u4 = (a - 30) / 30
        if (u3 > u4):
            time_level = 'S'
        else:
            time_level = 'M'
    if 60 < a <= 90:
        u5 = (90 - a) / 30
        u6 = (a - 60) / 30
        if (u5 > u6):
            time_level = 'M'
        else:
            time_level = 'L'
    if 90 < a <= 120:
        u7 = (120 - a) / 30
        u8 = (a - 90) / 30
        if (u7 > u8):
            time_level = 'L'
        else:
            time_level = 'VL'
    return time_level

if __name__ == '__main__':
    sludge = int(input("Input sludge index:"))
    grease = int(input("Input grease index:"))
    rules_value = Rules(Sludge(sludge), Grease(grease))
    time_level = Inference(rules_value)  
    time_pre = Max_membership(time_level)  
    time_sign = WashTime(time_pre)  
    flag = {'VS': 'Very Short', 'S': 'Short', 'M': 'Medium', 'L': 'Long', 'VL': 'Very Long'}
    print("Fuzzy inference system predicted washing time:{}{}, Estimated washing time:{}".format(time_sign,flag[time_sign], time_pre))
