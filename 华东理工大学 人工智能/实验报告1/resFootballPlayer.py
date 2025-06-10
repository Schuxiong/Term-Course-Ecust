# 自定义函数，对输入的球员名字进行反推
def reverse_engineering(player_name):
    if player_name == "Lionel Messi":
        return {'1': "Paris Saint-Germain", '2': "1", '3': "前锋", '4': "30"}
    elif player_name == "Cristiano Ronaldo":
        return {'1': "Al Nassr", '2': "2", '3': "前锋", '4': "7"}
    elif player_name == "Neymar Jr.":
        return {'1': "Paris Saint-Germain", '2': "3", '3': "前锋", '4': "10"}
    elif player_name == "Robert Lewandowski":
        return {'1': "Bayern Munich", '2': "4", '3': "前锋", '4': "9"}
    elif player_name == "Kylian Mbappé":
        return {'1': "Paris Saint-Germain", '2': "5", '3': "前锋", '4': "7"}
    elif player_name == "Kevin De Bruyne":
        return {'1': "Manchester City", '2': "6", '3': "中场", '4': "17"}
    elif player_name == "Mohamed Salah":
        return {'1': "Liverpool", '2': "7", '3': "前锋", '4': "11"}
    elif player_name == "Erling Haaland":
        return {'1': "Borussia Dortmund", '2': "8", '3': "前锋", '4': "9"}
    else:
        return None

# 输入球员名字
player_name = input("请输入球员名字: ")

# 反推属性
attributes = reverse_engineering(player_name)

# 输出反推结果
if attributes:
    print("球队: ", attributes['1'])
    print("欧冠排名: ", attributes['2'])
    print("场上位置: ", attributes['3'])
    print("球衣号码: ", attributes['4'])
else:
    print("无法识别球员名字或输入错误。")
