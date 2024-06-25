# TodoList

#### 介绍
软件架构实验

#### 软件架构

软件架构说明



# 建议查看word版运行教程

**注：**实验中遇到任何问题请在

[**https://github.com/ChoCoo1/TodoList/issues**](https://github.com/ChoCoo1/TodoList/issues)

**https://gitee.com/ChoCool/todo-list/issues**

点击NewIssue，在title中描述在哪一步时遇到的问题，在decription中描述遇到的报错信息，并提出Issue ，我会在在issue中帮忙解答，也可以翻阅以前所提出的issue中寻找解决方案，若确实没有再提出报错信息。



## Node.js安装

**（如果电脑上已有可以跳过 ，cmd输入node -v可查看是否有）**

参考网址https://nodejs.org/en/



点击download，可以看到已经下载

 

点开msi文件，进行正常的安装（记得记下这个路径，其他一路点Next就可以）

 

安装完成后，在cmd输入node -v 

如能输出版本号，即表示安装成功，可以进行下一步

若未能输出版本号，而是提示报错，可以将上一步中的文件夹地址添加到环境变量中

 

## **安装Django及其所需的其他安装包**

```cmd
 pip install django
 pip install djangorestframework
 pip install django-filter
 pip install django-cors-headers
 pip install pymysql
 pip install cryptography
```

## 安装mysql及其相应的DBMS数据库管理系统

如果之前就使用过mysql，请直接跳过

这一段安装比较繁琐，https://blog.csdn.net/weixin_39289696/article/details/128850498

请参考这个csdn教程进行安装

 

安装DBMS数据库管理系统 一切DBMS系统均可以，只是方便查看数据，如果你知道自己的数据库的端口号和密码并且知道怎么通过mysql创建数据库的话，不用DBMS系统也可以，这里以navicat为例，如果之前安装过的，不建议重新安装，安装教程参考

https://blog.csdn.net/qq_43715354/article/details/109716564

 

运行前准备

打开DBMS系统创建一个数据库名字任意，我这里创建的数据库名称是TodoMVC

打开backend/django/路径下的setting.py文件，找到以下代码

```python

# Database
# https://docs.djangoproject.com/en/5.0/ref/settings/#databases
DATABASES = {

  'default': {
  'ENGINE': 'django.db.backends.mysql', # 默认
  'NAME': 'TodoMVC', # 连接的数据库 #刚创建的数据库名
  'HOST': '127.0.0.1', # mysql的ip地址
  'PORT': ****, # 填入你的mysql的端口号 ，一般是3306
  'USER': 'root', # 填入你的mysql的用户名，一般是root
  'PASSWORD': '******' # 填入你的mysql的密码
  }
}
```

 

**经典报错**

django.db.utils.OperationalError: (1045, "Access denied for user 'root'@'localhost' (using password: YES)")  数据库密码错误或信息不对

 



进入backend目录

```
cd backend
python manage.py makemigrations
python manage.py migrate 
python manage.py createsuperuser 注：邮箱随便填，碰到y/n选y
python manage.py runserver 即可启动后端
```



再进入todo文件夹

若当前还在backend下记得cd ..



```
cd todo
npm install –no-fund
npm run serve
```



 
