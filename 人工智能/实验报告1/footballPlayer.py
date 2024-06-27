# 自定义函数，判断有无重复元素
def judge_repeat(value, list=[]):
    for i in range(0, len(list)):
        if (list[i] == value):
            return 1
        else:
            if (i != len(list) - 1):
                continue
            else:
                return 0

# 自定义函数，对已经整理好的综合数据库real_list进行最终的结果判断
def judge_last(list):
    if '1' in list and '2' in list and '3' in list and '4' in list:
        if list['1'] == "Paris Saint-Germain" and list['2'] == "1" and list['3'] == "前锋" and list['4'] == "30":
            print("\n所识别的人员为 Lionel Messi")
        elif list['1'] == "Al Nassr" and list['2'] == "2" and list['3'] == "前锋" and list['4'] == "7":
            print("\n所识别的人员为 Cristiano Ronaldo")
        elif list['1'] == "Paris Saint-Germain" and list['2'] == "3" and list['3'] == "前锋" and list['4'] == "10":
            print("\n所识别的人员为 Neymar Jr.")
        elif list['1'] == "Bayern Munich" and list['2'] == "4" and list['3'] == "前锋" and list['4'] == "9":
            print("\n所识别的人员为 Robert Lewandowski")
        elif list['1'] == "Paris Saint-Germain" and list['2'] == "5" and list['3'] == "前锋" and list['4'] == "7":
            print("\n所识别的人员为 Kylian Mbappé")
        elif list['1'] == "Manchester City" and list['2'] == "6" and list['3'] == "中场" and list['4'] == "17":
            print("\n所识别的人员为 Kevin De Bruyne")
        elif list['1'] == "Liverpool" and list['2'] == "7" and list['3'] == "前锋" and list['4'] == "11":
            print("\n所识别的人员为 Mohamed Salah")
        elif list['1'] == "Borussia Dortmund" and list['2'] == "8" and list['3'] == "前锋" and list['4'] == "9":
            print("\n所识别的人员为 Erling Haaland")
        else:
            print("\n根据所给条件无法判断为何种人员")
    else:
        print("\n根据所给条件无法判断为何种人员")

# 综合数据库
list_real = {}
print("球队列表：")
print("1. Paris Saint-Germain")
print("2. Al Nassr")
print("3. Bayern Munich")
print("4. Manchester City")
print("5. Liverpool")
print("6. Borussia Dortmund")

team_code = input("请输入球队编号: ")
if team_code == '1':
    list_real['1'] = "Paris Saint-Germain"
elif team_code == '2':
    list_real['1'] = "Al Nassr"
elif team_code == '3':
    list_real['1'] = "Bayern Munich"
elif team_code == '4':
    list_real['1'] = "Manchester City"
elif team_code == '5':
    list_real['1'] = "Liverpool"
elif team_code == '6':
    list_real['1'] = "Borussia Dortmund"

print("\n欧冠排名列表：")
print("1. 1")
print("2. 2")
print("3. 3")
print("4. 4")
print("5. 5")
print("6. 6")
print("7. 7")
print("8. 8")

rank_code = input("请输入欧冠排名编号: ")
if rank_code in ['1', '2', '3', '4', '5', '6', '7', '8']:
    list_real['2'] = rank_code

print("\n场上位置列表：")
print("1. 前锋")
print("2. 中场")
print("3. 后卫")
print("4. 守门员")

position_code = input("请输入场上位置编号: ")
if position_code == '1':
    list_real['3'] = "前锋"
elif position_code == '2':
    list_real['3'] = "中场"
elif position_code == '3':
    list_real['3'] = "后卫"
elif position_code == '4':
    list_real['3'] = "守门员"

print("\n球衣号码列表：")
print("1. 7")
print("2. 9")
print("3. 10")
print("4. 11")
print("5. 17")
print("6. 30")


number_code = input("请输入球衣号码编号: ")
if number_code == '1':
    list_real['4'] = "7"
elif number_code == '2':
    list_real['4'] = "9"
elif number_code == '3':
    list_real['4'] = "10"
elif number_code == '4':
    list_real['4'] = "11"
elif number_code == '5':
    list_real['4'] = "17"
elif number_code == '6':
    list_real['4'] = "30"

print("\n")
print("推理过程如下：")
# 遍历综合数据库list_real中的前提条件
for key, value in list_real.items():
    if key == '1' and value != '':
        print("球队: ", value)
    elif key == '2' and value != '':
        print("欧冠排名: ", value)
    elif key == '3' and value != '':
        print("场上位置: ", value)
    elif key == '4' and value != '':
        print("球衣号码: ", value)

judge_last(list_real)
