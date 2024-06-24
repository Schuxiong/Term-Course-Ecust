import re

def remove_numbers(code):
    # 使用正则表达式替换每行开头的数字为空字符串
    cleaned_code = re.sub(r'^\d+\.\s*', '', code, flags=re.MULTILINE)
    return cleaned_code

# 读取代码文件，使用 utf-8 编码
with open('fileManagement.cpp', 'r', encoding='utf-8') as file:
    code = file.read()

# 调用函数删除数字
cleaned_code = remove_numbers(code)

# 将处理后的代码写入新文件
with open('cleaned_code.cpp', 'w', encoding='utf-8') as file:
    file.write(cleaned_code)

print("数字已成功删除并保存到 cleaned_code.cpp 文件中。")
