项目名：iDB    作者：SATAT
简介：使用RandomAccessFile实现一个简单的数据库管理系统，并在GUI中展示
1.系统启动：  右键运行iDB/src/view/Start.java'
2.用户登录：  账号密码在iDB/config/user 中，格式为  用户名-密码-是否为管理员（1是0否）-权限
3.系统使用：  参考视频https://www.bilibili.com/video/BV1Vq4y177N8/
4.使用流程：  登录→输入sql语句（新建库、新建表、对表进行增删改查，目前只支持视频展示的sql语句）
5.修改代码：  简单改：可改logo、账号密码权限、MainView里的自定义内容（GUI样式，包括尺寸、背景色等）
                                       修改数据库默认路径（修改sql文件下每个demo里的D:\\iDBLib）
6.演示：①创建数据库111：create database 111
       ②使用新数据库111：use 111
       ③创建表stu1的表结构：create table stu1 ( sname String(9), age int(4), class String(4), grade double(8));	  
       ④查询表stu1：select * from stu1;
       ⑤新增数据：
			Insert INTO stu1 (sname,age,class,grade) values ('张11',16,'2019',95);       //没有赋值的设为默认值
			Insert INTO stu1 (sname,class,grade) values ('张12','2019',85);                  //整形默认值0
			Insert INTO stu1 (sname,age,class) values ('张13',17,'2019');                     //double默认 0.0
			Insert INTO stu1 (sname,age,grade) values ('张14',18,65);                         //字符串默认“”
			Insert INTO stu1 (sname,age,class,grade) values ('张15',15,'2020',65);
       ⑥查询表：		
			select * from stu1 where age < 18;      //可判断①字符串相等、       ②整形/浮点型大于、小于、等于、不等于
			select  sname, age, grade from stu1 where class = '2019';
       ⑦删除数据并查询：
			DELETE FROM stu1 WHERE sname = '张11';
			select * from stu1;
	   ⑧更新数据并查询：
	   		UPDATE stu1 SET class = '2000' WHERE grade > 75;
			select * from stu1;
7.总结：①独立完成    ②系统可运行    ③复现磁盘操作、缓冲区管理内容 ；  
       ④能建立数据库数据表    ⑤能插入多种类型的数据    ⑥能实现增删改查；   
       ⑦其他功能有：登录功能（分管理员和非管理员），日志功能（每次使用一个库会重新创建一个日志，日志命名为：当前时间+UUID后段)
