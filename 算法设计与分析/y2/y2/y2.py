import pygame
import os

# 初始化 pygame
pygame.init()

# 设置窗口大小和标题
screen_width = 600
screen_height = 600
screen = pygame.display.set_mode((screen_width, screen_height))
pygame.display.set_caption("Y2Kgame")

# 加载背景图片并设置其初始大小
background1 = pygame.image.load("bg1.jpg").convert()
background1 = pygame.transform.scale(background1, (screen_width, screen_height))
background2 = pygame.image.load("bg2.jpg").convert()
background2 = pygame.transform.scale(background2, (screen_width, screen_height))
current_background = background1

# 加载图片的文件夹路径
image_folder = "images"

# 加载人物图片
character = pygame.image.load(os.path.join(image_folder, "character.png")).convert_alpha()

# 加载每种装饰品的图片列表
jewelry_list = [pygame.image.load(os.path.join(image_folder, filename)).convert_alpha() for filename in ["J1.png", "J2.png"]]
hair_list = [pygame.image.load(os.path.join(image_folder, filename)).convert_alpha() for filename in ["H1.png", "H2.png"]]
makeup_list = [pygame.image.load(os.path.join(image_folder, filename)).convert_alpha() for filename in ["F1.png", "F2.png"]]
clothing_list = [pygame.image.load(os.path.join(image_folder, filename)).convert_alpha() for filename in ["C1.png", "C2.png", "C3.png", "C4.png", "C5.png"]]
pants_list = [pygame.image.load(os.path.join(image_folder, filename)).convert_alpha() for filename in ["P1.png", "P2.png"]]
shoes_list = [pygame.image.load(os.path.join(image_folder, filename)).convert_alpha() for filename in ["S1.png", "S2.png", "S3.png"]]
socks_list = [pygame.image.load(os.path.join(image_folder, filename)).convert_alpha() for filename in ["sock1.png"]]
border_list = [pygame.image.load(os.path.join(image_folder, filename)).convert_alpha() for filename in ["B1.png"]]
sbackground_list = [pygame.image.load(os.path.join(image_folder, filename)).convert_alpha() for filename in ["BG.png"]]

# 设置当前的头饰、头发、妆容、衣服、裤装、鞋子、袜子、边框索引
indices = {
    "jewelry": 0,
    "hair": 0,
    "makeup": 0,
    "clothing": 0,
    "pants": 0,
    "shoes": 0,
    "socks": 0,
    "border": 0,
    "sbackground":0
}

# 设置装饰品的位置和大小
image_size = (500, 500)
positions = {
    "character": (0, 80),
    "jewelry": (-50, 80),
    "hair": (-50, 80),
    "makeup": (-50, 80),
    "clothing": (-50, 80),
    "pants": (-50, 80),
    "shoes":(-50, 80),
    "socks": (-50, 80),
    "border": (0, 0) , # 单独设置边框位置
    "sbackground":(0,0)
}

# 设置边框的宽度和高度
border_width = 413.4
border_height = 600

sbackground_width = 413.4
sbackground_height = 600

# 设置按钮位置和大小
button_width = 50
button_height = 25
button_margin = 20
button_x = screen_width - button_width - button_margin
button_y_start = button_margin

# 设置按钮颜色
button_color = (128, 128, 128)  # 灰色
hover_color = (100, 100, 100)  # 深灰色

# 设置字体
font = pygame.font.Font(None, 25)

# 设置按钮点击间隔时间
click_delay = 200  # 毫秒
last_click_time = pygame.time.get_ticks()

# 定义变量来控制是否显示按钮
show_buttons = True

# 绘制按钮
def draw_button(text, x, y, width, height, active):
    pygame.draw.rect(screen, button_color if active else hover_color, (x, y, width, height))
    text_surface = font.render(text, True, (255, 255, 255))
    text_rect = text_surface.get_rect(center=(x + width / 2, y + height / 2))
    screen.blit(text_surface, text_rect)

# 创建按钮
buttons = []
for i, category in enumerate(indices):
    button_y = button_y_start + i * (button_height + button_margin)
    buttons.append((category, button_x, button_y))

# 创建隐藏按钮
hide_buttons = []
for i, category in enumerate(indices):
    button_y = button_y_start + i * (button_height + button_margin)
    hide_buttons.append(("Hide " + category.capitalize(), button_x - 2 * button_margin - button_width, button_y))

# 创建切换背景按钮
bg_button = ("Switch Background", button_x, button_y_start + len(indices) * (button_height + button_margin))

# 创建隐藏所有按钮的按钮
hide_all_button = ("Hide All", button_x - 2 * button_margin - button_width, button_y_start + len(indices) * (button_height + button_margin))

# 创建一个循环，直到用户点击关闭按钮
running = True
while running:
    # 处理事件
    for event in pygame.event.get():
        # 如果用户点击关闭按钮，退出循环
        if event.type == pygame.QUIT:
            running = False

    # 绘制背景
    screen.blit(current_background, (0, 0))

    # 绘制人物
    

    # 按照优先级绘制装饰品
    priority_order = ["sbackground","hair", "jewelry", "makeup", "clothing", "pants", "shoes", "socks", "border"]
    for category in priority_order:
        if category != "character" and indices[category] >= 0 and indices[category] < len(eval(category + "_list")):
            # 如果是边框，使用原始的宽度和高度参数
            if (category == "border" ) :
                screen.blit(pygame.transform.scale(border_list[indices[category]], (border_width, border_height)), positions[category])
            elif (category == "sbackground" ):
                 screen.blit(pygame.transform.scale(sbackground_list[indices[category]], (sbackground_width, sbackground_height)), positions[category])
                 screen.blit(character, positions["character"])
            else:
                screen.blit(character, positions["character"])
                screen.blit(pygame.transform.scale(eval(category + "_list")[indices[category]], image_size), positions[category])

    # 绘制按钮
    if show_buttons:
        for button in buttons:
            draw_button(button[0].capitalize(), button[1], button[2], button_width, button_height, True)

        # 绘制隐藏按钮
        for hide_button in hide_buttons:
            draw_button(hide_button[0], hide_button[1], hide_button[2], button_width, button_height, True)

        # 绘制切换背景按钮
        draw_button(bg_button[0], bg_button[1], bg_button[2], button_width, button_height, True)

    # 绘制隐藏所有按钮的按钮
    draw_button(hide_all_button[0], hide_all_button[1], hide_all_button[2], button_width, button_height, True)

    # 检查按钮点击间隔时间
    current_time = pygame.time.get_ticks()
    if current_time - last_click_time < click_delay:
        continue

    # 切换装饰品或隐藏/显示装饰品
    for hide_button in hide_buttons:
        if pygame.mouse.get_pressed()[0] and hide_button[1] <= pygame.mouse.get_pos()[0] <= hide_button[1] + button_width and hide_button[2] <= pygame.mouse.get_pos()[1] <= hide_button[2] + button_height:
            category = hide_button[0][5:].lower()
            if indices[category] == -1:
                indices[category] = 0
            else:
                indices[category] = -1
            last_click_time = current_time
            break  # 退出循环以防止同时按下多个按钮

    # 切换装饰品
    for button in buttons:
        if pygame.mouse.get_pressed()[0] and button[1] <= pygame.mouse.get_pos()[0] <= button[1] + button_width and button[2] <= pygame.mouse.get_pos()[1] <= button[2] + button_height:
            indices[button[0]] = (indices[button[0]] + 1) % (len(eval(button[0] + "_list")))
            last_click_time = current_time
            break  # 退出循环以防止同时按下多个按钮

    # 切换背景
    if pygame.mouse.get_pressed()[0] and bg_button[1] <= pygame.mouse.get_pos()[0] <= bg_button[1] + button_width and bg_button[2] <= pygame.mouse.get_pos()[1] <= bg_button[2] + button_height:
        current_background = background1 if current_background == background2 else background2
        last_click_time = current_time

    # 隐藏/显示所有按钮
    if pygame.mouse.get_pressed()[0] and hide_all_button[1] <= pygame.mouse.get_pos()[0] <= hide_all_button[1] + button_width and hide_all_button[2] <= pygame.mouse.get_pos()[1] <= hide_all_button[2] + button_height:
        show_buttons = not show_buttons
        last_click_time = current_time

     
    # 更新屏幕
    pygame.display.flip()

# 退出 pygame
pygame.quit()
