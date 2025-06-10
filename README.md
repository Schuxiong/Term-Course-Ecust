## 📚 华东理工大学课程作业互助仓库
### 🎯 仓库简介
本仓库是华东理工大学各专业课程的作业、实验报告、课程设计等学习资料的共享平台，旨在为同学们提供学习参考和互助交流。

### 📁 目录结构
```
├── 华东理工大学 
JAVA/           # Java程序设计
课程
├── 华东理工大学 人工智
能/        # 人工智能课程
├── 华东理工大学 嵌入
式/          # 嵌入式系统课程
├── 华东理工大学 操作系
统/        # 操作系统课程
├── 华东理工大学 数据
库/          # 数据库原理课程
├── 华东理工大学 算法与数据结
构/   # 算法与数据结构课程
├── 华东理工大学 计算机网
络/      # 计算机网络课程
├── 华东理工大学 软件工
程/        # 软件工程课程
└── 毕业设
计/                    # 毕业
设计相关
```
### 🚀 如何贡献你的作业 方法一：直接推送（推荐新手）
1. 克隆仓库
```
git clone https://github.com/
Schuxiong/Term-Course-Ecust.
git
cd Term-Course-Ecust
```
2. 添加你的文件
```
# 将你的作业文件放入对应的课程文件
夹
# 例如：将Java作业放入"华东理工大
学 JAVA/"文件夹
```
3. 提交更改
```
git add .
git commit -m "添加[课程名称]作
业 - [你的姓名/学号]"
```
4. 推送到远程仓库
```
git push origin master
``` 
方法二：处理大文件（文件>50MB）
如果你的文件较大，需要使用Git LFS：

1. 安装并初始化Git LFS
```
git lfs install
```
2. 配置要追踪的大文件类型
```
git lfs track "*.zip"
git lfs track "*.rar"
git lfs track "*.pdf"
git lfs track "*.docx"
git lfs track "*.pptx"
git lfs track "*.mp4"
git lfs track "*.exe"
```
3. 提交.gitattributes文件
```
git add .gitattributes
git commit -m "配置Git LFS追踪
大文件"
```
4. 正常添加和提交文件
```
git add .
git commit -m "添加[课程名称]作
业 - [你的姓名/学号]"
git push origin master
``` 
方法三：超大仓库推送（>2GB）
如果推送失败提示超过2GB限制，使用本仓库提供的批量推送脚本：

```
# 在PowerShell中运行
.\BatchPush.ps1 -Remote 
"origin" -Branch "master" 
-BatchSize 5
```
### 📋 提交规范
- 提交信息格式 ： 添加[课程名称]作业 - [你的姓名/学号]
- 文件命名 ：建议包含课程名称、作业类型、姓名/学号
- 文件夹结构 ：请将文件放入对应的课程文件夹中
### ⚠️ 注意事项
1. 学术诚信 ：本仓库仅供学习参考，请勿直接抄袭
2. 版权声明 ：请确保上传的内容不侵犯他人版权
3. 文件大小 ：单个文件建议不超过100MB
4. 敏感信息 ：请勿上传包含个人敏感信息的文件
### 🔧 常见问题解决 推送失败："pack exceeds maximum allowed size"
```
# 使用批量推送脚本
.\BatchPush.ps1 -Remote 
"origin" -Branch "master" 
-BatchSize 3
``` 
大文件警告
```
# 配置Git LFS追踪大文件
git lfs track "*.大文件扩展名"
git add .gitattributes
git commit -m "配置LFS追踪"
``` 
网络连接问题
```
# 禁用LFS锁定（如果遇到lfs.
github.com连接问题）
git config lfs.locksverify 
false
```
### 🤝 贡献指南
欢迎所有华东理工大学的同学贡献你们的学习资料！你的分享将帮助更多的同学学习进步。

Happy Coding! 🎓

如有问题，请提交Issue或联系仓库维护者