from PySide2.QtWidgets import QApplication, QMainWindow, QPushButton
from PySide2.QtWidgets import QPlainTextEdit
from PySide2.QtWidgets import QMessageBox

Plants = []
Feature = []
Rules = []
dy_data = []
tested_1 = []
tested_2 = []
num = []
mid_result = []
weici1 = '1'
weici2 = '2'


class GUI():
    def __init__(self):

        self.window = QMainWindow()
        self.window.resize(600, 500)
        self.window.move(300, 310)

        self.textEdit = QPlainTextEdit(self.window)
        self.textEdit.setPlaceholderText("请输入已有特征信息的序号(以空格分隔)")
        self.textEdit.move(220, 50)
        self.textEdit.resize(100, 300)

        info = []
        for i in range(len(Feature)):
            s = "%d: %s " % (i + 1, Feature[i])
            info.append(s)
        self.textEdit2 = QPlainTextEdit(self.window)
        self.textEdit2.setPlainText(str(info))
        self.textEdit2.move(10, 50)
        self.textEdit2.resize(200, 300)

        self.textEdit3 = QPlainTextEdit(self.window)
        self.textEdit3.setPlainText('所有特征')
        self.textEdit3.move(10, 15)
        self.textEdit3.resize(120, 30)

        self.textEdit4 = QPlainTextEdit(self.window)
        self.textEdit4.move(430, 50)
        self.textEdit4.resize(150, 300)

        self.button1 = QPushButton('正向推理', self.window)
        self.button1.move(330, 130)
        self.button1.clicked.connect(self.handle)

        self.button3 = QPushButton('展示所有规则', self.window)
        self.button3.resize(150, 100)
        self.button3.move(10, 380)
        self.button3.clicked.connect(self.display_rules)

        self.textEdit5 = QPlainTextEdit(self.window)
        self.textEdit5.setPlaceholderText("请输入要添加的规则")
        self.textEdit5.move(180, 360)
        self.textEdit5.resize(250, 50)

        self.button4 = QPushButton('添加规则', self.window)
        self.button4.resize(100, 50)
        self.button4.move(460, 360)
        self.button4.clicked.connect(self.add_rules)

    def display_rules(self):
        Rules = []
        with open("D:/桌面/大三上/人工智能/大作业/20002221-产生式系统 源代码/Rule.txt", 'r', encoding='utf8') as f3:
            for line in f3:
                line = line.split()
                Rules.append(line)
            f3.close()
        info = []
        for i in range(len(Rules)):  # 使输出有序
            s = "%d: %s " % (i + 1, Rules[i])
            info.append(s)
        QMessageBox.about(self.window, '所有规则', f'''如下：\n\n{'       '.join(info)}''')

    def add_rules(self):
        info = self.textEdit5.toPlainText()
        file = open('D:/桌面/大三上/人工智能/大作业/20002221-产生式系统 源代码/Rule.txt', 'a', encoding='utf8')
        file.write('\n' + info)
        file.close()


        # self.textEdit4.setPlainText(f'''您初始输入的特征信息有：\n{' '.join(init_info)}
        #     {'            '.join(mid_result)}\n\n您得到的答案是：\n{infer}''')

    def handle2(self):
        global num
        init_info = []
        info = self.textEdit.toPlainText()
        num = list(map(int, info.split()))
        for i in num:
            dy_data.append(Feature[i - 1])
            init_info.append(Feature[i - 1])
        infer = inference2()

        self.textEdit4.setPlainText(f'''您初始输入的特征信息有：\n{' '.join(init_info)}
            {'            '.join(mid_result)}\n\n您得到的答案是：\n{infer}''')


    def handle(self):
        global num
        init_info = []
        info = self.textEdit.toPlainText()
        num = list(map(int, info.split()))
        for i in num:
            dy_data.append(Feature[i - 1])
            init_info.append(Feature[i - 1])
        infer = inference()
        self.textEdit4.setPlainText(f'''您初始输入的特征信息有：\n{' '.join(init_info)}
                    {'            '.join(mid_result)}\n\n您得到的答案是：\n{infer}''')


def Database(file1, file2, file3):
    with open(file1, 'r', encoding='utf8') as f1:
        for line in f1.readlines():
            line = str(line).split()
            Plants.extend(line)
        f1.close()
    with open(file2, 'r', encoding='utf8') as f2:
        for line in f2.readlines():
            line = str(line).split()
            Feature.extend(line)
        f2.close()
    with open(file3, 'r', encoding='utf8') as f3:
        for line in f3:
            line = line.split()
            Rules.append(line)
        f3.close()


def inference():
    flag = 1
    while (flag):
        for i in range(len(dy_data)):
            if (dy_data[i] in Plants):
                return dy_data[i]
        tested_1 = []
        for i in range(len(Rules)):
            if (Rules[i] in tested_2):  # 防止规则重复匹配
                pass
            else:
                sub = Rules[i][:-1]
                for j in sub:
                    if (j not in dy_data):
                        break
                    if (j == sub[-1]):
                        if (Rules[i][-1] not in dy_data):  # 避免匹配到的规则后件重复加入
                            dy_data.append(Rules[i][-1])
                        s = "\n匹配的规则："
                        s += weici1
                        for g in Rules[i]:
                            if (g == Rules[i][-2]):
                                s += g
                                s += '--->'
                                s += weici2
                            else:
                                s += g
                                s += '、'
                        mid_result.append(s)
                        ss = "\n目前综合数据库信息："
                        for g in dy_data:
                            ss += g
                            ss += '、'
                        mid_result.append(ss)
                        tested_1.append(Rules[i])
                        tested_2.append(Rules[i])
        if (tested_1 == []):
            flag = 0  # 匹配失败，查找不到
    return False


def inference2():
    for i in range(len(Rules)):
        if (Rules[i][0] in dy_data):
            s = "\n匹配的规则："
            for g in Rules[i]:
                if (g == Rules[i][0]):
                    s += weici2
                    s += g
                    s += '--->'
                    s += weici1
                else:
                    s += g
                    s += '、'
            mid_result.append(s)

            for j in range(len(Rules[i])):
                if (j != 0): dy_data.append(Rules[i][j])

            ss = "\n目前综合数据库信息："
            for g in dy_data:
                ss += str(g)
                ss += '、'
            mid_result.append(ss)
            return dy_data


file1_path = "D:/桌面/大三上/人工智能/大作业/20002221-产生式系统 源代码/Plants.txt"
file2_path = "D:/桌面/大三上/人工智能/大作业/20002221-产生式系统 源代码/Feature.txt"
file3_path = "D:/桌面/大三上/人工智能/大作业/20002221-产生式系统 源代码/Rule.txt"
Database(file1_path, file2_path, file3_path)
app = QApplication([])
gg = GUI()
gg.window.show()
app.exec_()
