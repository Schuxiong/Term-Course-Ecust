#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
struct usr // 用户结构体
{
  char username[8], password[8];
};

struct fnode // 文件或目录结构
{
  char filename[10], content[1024], address[10], protect[10];
  int isdir, isopen, leng;
  fnode *parent, *child, *prev, *next;
};

usr users[4] = {"user1", "user1", "user2", "user2", "user3", "user3", "user4", "user4"}; // 预先给定的4个用户（用户名，密码）
char para[100];                                                                          // 路径
fnode *root, *recent;                                                                    // 根目录；指向路径的当前目录
int m = 0, n = 0;                                                                        // 目录（文件）物理地址里的数字（例如：file0、file1、dir0...)

int login(char *username, char *password)                                                // 登录
{
  for (int i = 0; i < 4; i++)
    if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0)
    {
      cout << "登陆成功！请输入命令" << endl;
      return 1;
    }
  return 0;
}

fnode *initfile(char *filename, int isdir) // 初始化文件或目录结构
{
  fnode *t;
  t = new fnode;
  strcpy(t->filename, filename);
  t->isdir = isdir;
  t->isopen = 0;
  t->parent = t->child = t->prev = t->next = NULL;
  t->leng = 0;
  return t;
}

void creatroot() // 建立根目录
{
  char filename[8] = "/"; // 定义根目录名为"/"
  root = initfile(filename, 1);
  recent = root;     // 当前指针指向根目录
  strcpy(para, "/"); // 初始路径即为根目录
}

int mkdir() // 建立目录
{
  fnode *t, *p;
  char filename[8];
  cin >> filename;
  t = initfile(filename, 1);
  if (recent->child == NULL) // 找出空的位置建立目录
  {
    recent->child = t;
    t->parent = recent;
    sprintf(t->address, "%s%d", "dir", m);
    m++;
    cout << "目录创建成功！" << endl;
  }
  else
  {
    p = recent->child;
    do
    {
      if (strcmp(p->filename, t->filename) == 0 && p->isdir) // 目录名相同
      {
        cout << "目录已存在" << endl;
        return 1;
      }
      else if (p->next) // 继续往右边查找
        p = p->next;
      else
        break; // 不存在相同目录名的目录，并且找到了空位置，跳出循环建立目录
    } while (1);
    p->next = t;
    t->prev = p;
    sprintf(t->address, "%s%d", "dir", m);
    m++;
    cout << "目录创建成功！" << endl;
  }
}

int create() // 建立文件（同mkdir()类似）
{
  int flag = 0; // 检查文件保护码是否正确
  fnode *t, *p;
  char filename[8];
  cin >> filename;
  t = initfile(filename, 0);
  if (recent->child == NULL) // 查找空的位置
  {
    recent->child = t;
    t->parent = recent;
    sprintf(t->address, "%s%d", "file", n);
    n++;
    while (!flag) // 设置文件保护码
    {
      cout << "请设置4位文件保护码：";
      cin >> t->protect;
      if (strlen(t->protect) == 4) // 文件保护码为4位就设置成功
        flag = 1;
      else
        cout << "请重新设置" << endl;
    }
    cout << "文件创建成功！" << endl;
  }
  else
  {
    p = recent->child;
    do
    {
      if (strcmp(p->filename, t->filename) == 0 && !p->isdir) // 文件名相同
      {
        cout << "文件已存在" << endl;
        return 1;
      }
      else if (p->next) // 继续往右查找
        p = p->next;
      else
        break; // 不存在相同文件名的文件，并且找到了空位置，跳出循环建立文件
    } while (1);
    p->next = t;
    t->prev = p;
    sprintf(t->address, "%s%d", "file", n);
    n++;
    while (!flag) // 设置文件保护码
    {
      cout << "请设置4位文件保护码：";
      cin >> t->protect;
      if (strlen(t->protect) == 4) // 文件保护码为4位就设置成功
        flag = 1;
      else
        cout << "请重新设置" << endl;
    }
    cout << "文件创建成功！" << endl;
  }
}

void dir() // 列出当前目录中的文件和目录
{
  int i = 0, j = 0; // 目录数；文件数
  fnode *t;
  if (recent->child == NULL) // 该目录下没有文件或目录
    cout << "Total:" << "     directors     " << i << "     files     " << j << endl;
  else
  {
    t = recent->child;
    do
    {
      if (t->isdir) // 找到目录
      {
        printf("%s  %s\n", t->filename, t->address);
        i++;
      }
      else
      { // 找到文件
        printf("%s  %s  %s%5d\n", t->filename, t->address, t->protect, t->leng);
        j++;
      }
      if (t->next) // 继续往右查找
        t = t->next;
      else
        break; // 该目录下已经没有文件或目录
    } while (1);
    cout << "Total:" << "     directors     " << i << "     files     " << j << endl;
  }
}

int write() // 写入文件
{
  fnode *t;
  char filename[8], cinpro[10];
  cin >> filename;
  if (recent->child == NULL) // 该目录下没有文件
  {
    cout << "文件不存在" << endl;
    return 1;
  }
  else
  {
    t = recent->child;
    do
    {
      if (strcmp(t->filename, filename) == 0 && t->isdir == 0) // 找到文件
      {
        cout << "请输入4位文件保护码：";
        cin >> cinpro;
        if (strcmp(cinpro, t->protect) == 0) // 文件保护码正确，写入文件内容
        {
          cout << "请输入文件内容：" << endl;
          cin >> t->content;
          t->leng = strlen(t->content);
          cout << "写入成功！" << endl;
          return 1;
        }
        else
        {
          cout << "输入有误，无法进行写入操作" << endl;
          return 1;
        }
      }
      else if (t->next)
        t = t->next;
      else
      {
        cout << "文件不存在" << endl;
        return 1;
      }
    } while (1);
  }
}

int read() // 读取文件（同write()类似）
{
  fnode *t;
  char filename[8], cinpro[10];
  cin >> filename;
  if (recent->child == NULL)
  {
    cout << "文件不存在" << endl;
    return 1;
  }
  else
  {
    t = recent->child;
    do
    {
      if (strcmp(t->filename, filename) == 0 && t->isdir == 0)
      {
        cout << "请输入4位文件保护码：";
        cin >> cinpro;
        if (strcmp(cinpro, t->protect) == 0)
        {
          cout << "文件内容：" << endl;
          cout << t->content << endl;
          return 1;
        }
        else
        {
          cout << "输入有误，无法进行读取操作" << endl;
          return 1;
        }
      }
      else if (t->next)
        t = t->next;
      else
      {
        cout << "文件不存在" << endl;
        return 1;
      }
    } while (1);
  }
}

int cd() // 打开目录
{
  char topara[30];
  cin >> topara;
  if (strcmp(topara, "..") == 0) // 返回上级目录
  {
    int i;
    while (recent->prev) // 如果有prev指针，不断往左挪动
      recent = recent->prev;
    if (recent->parent) // 找到上级目录
      recent = recent->parent;
    i = strlen(para) - 1; // 更新路径
    while (para[i] != '/' && i >= 0)
      i--;
    if (i != 0)
      para[i] = '\0'; // 去掉路径中的"/"，并且置一位'\0'
    else
      para[i + 1] = '\0'; // 上级目录为根目录
  }
  else if (strcmp(topara, "/") == 0) // 打开根目录
  {
    recent = root;
    strcpy(para, "/");
  }
  else if (topara[0] == '/') // 打开路径以'/'开头，就从根目录开始查找路径
  {
    fnode *saver;
    char savep[100];
    int leng = strlen(topara), i = 1;
    saver = recent;      // 保存当前指向的目录
    strcpy(savep, para); // 保存当前路径
    recent = root;
    strcpy(para, "/");
    while (i < leng) // topara需要打开的路径头从开始查找
    {
      fnode *t;
      int j = 0;
      char recentpara[8]; // 查找的当前目录
      if (topara[i] != '/')
      {
        while (topara[i] != '/' && i < leng) // 读取出当前目录
        {
          recentpara[j] = topara[i];
          i++, j++;
        }
        recentpara[j] = '\0';
        if (recent->child == NULL) // 查找路径中的当前目录下没有目录
        {
          cout << "路径错误" << endl;
          recent = saver;      // 还原当前目录
          stpcpy(para, savep); // 还原路径
          return 1;
        }
        else
        { // 继续查找
          t = recent->child;
          do
          {
            if (strcmp(t->filename, recentpara) == 0 && t->isdir) // 找到需要打开的目录
            {
              recent = t;
              strcat(para, recentpara); // 更新路径
              break;
            }
            else if (t->next)
              t = t->next;
            else
            { // 找不到目录
              cout << "路径错误" << endl;
              ;
              recent = saver;
              stpcpy(para, savep);
              return 1;
            }
          } while (1);
        }
      }
      else
      { // 读取到需要打开的目录中的'/'，更新路径
        strcat(para, "/");
        i++; // 继续读取下一位
      }
    }
  }
  else
  { // 需要打开的目录不以'/'开头（与上面类似）
    int i = 0, leng = strlen(topara), flag = 0;
    fnode *saver;
    char savep[100];
    saver = recent;
    strcpy(savep, para);
    while (i < leng)
    {
      int j = 0;
      char recentpara[8];
      fnode *t;
      if (topara[i] != '/')
      {
        while (topara[i] != '/' && i < leng)
        {
          recentpara[j] = topara[i];
          i++, j++;
        }
        recentpara[j] = '\0';
        if (recent->child == NULL)
        {
          cout << "路径错误" << endl;
          recent = saver;
          stpcpy(para, savep);
          return 1;
        }
        else
        {
          t = recent->child;
          do
          {
            if (strcmp(t->filename, recentpara) == 0 && t->isdir)
            {
              if (!flag && recent != root)
                strcat(para, "/");
              flag++;
              recent = t;
              strcat(para, recentpara);
              break;
            }
            else if (t->next)
              t = t->next;
            else
            {
              cout << "路径错误" << endl;
              recent = saver;
              stpcpy(para, savep);
              return 1;
            }
          } while (1);
        }
      }
      else
      {
        strcat(para, "/");
        i++;
      }
    }
  }
}

int del() // 删除文件或目录
{
  fnode *t;
  char filename[8];
  cin >> filename;
  if (recent->child == NULL)
    cout << "文件或目录不存在" << endl;
  else
  {
    t = recent->child;
    do
    {
      if (strcmp(t->filename, filename) == 0) // 找到该文件或目录，分文件储存结构进行删除
      {
        if (t->parent)
        {
          if (t->next)
            t->next->parent = t->parent;
          t->parent->child = t->next;
          delete t;
          cout << "文件或目录删除成功" << endl;
          return 1;
        }
        else
        {
          if (t->next)
            t->next->prev = t->prev;
          t->prev->next = t->next;
          delete t;
          cout << "文件或目录删除成功" << endl;
          return 1;
        }
      }
      else if (t->next)
        t = t->next;
      else
      {
        cout << "文件或目录不存在" << endl;
        return 1;
      }
    } while (1);
  }
}

int open() // 打开文件
{
  fnode *t;
  char filename[8];
  cin >> filename;
  if (recent->child == NULL)
    cout << "文件不存在" << endl;
  else
  {
    t = recent->child;
    do
    {
      if (strcmp(t->filename, filename) == 0 && !t->isdir)
      {
        t->isopen = 1; // 文件打开标记
        cout << "文件打开成功！" << endl;
        return 1;
      }
      else if (t->next)
        t = t->next;
      else
      {
        cout << "文件不存在" << endl;
        return 1;
      }
    } while (1);
  }
}

int close() // 关闭文件（与open()类似）
{
  fnode *t;
  char filename[8];
  cin >> filename;
  if (recent->child == NULL)
    cout << "文件不存在" << endl;
  else
  {
    t = recent->child;
    do
    {
      if (strcmp(t->filename, filename) == 0 && !t->isdir)
      {
        t->isopen = 0;
        cout << "文件关闭成功！" << endl;
        return 1;
      }
      else if (t->next)
        t = t->next;
      else
      {
        cout << "文件不存在" << endl;
        return 1;
      }
    } while (1);
  }
}

void help() // 命令浏览
{
  cout << endl
       << "                命令一览                " << endl;
  cout << "     ---------------------------------    " << endl;
  cout << "         mkdir  :  新建目录         " << endl;
  cout << "         create :  新建文件         " << endl;
  cout << "         write  :  写入文件         " << endl;
  cout << "         read   :  读出文件         " << endl;
  cout << "         cd     :  列文件目录         " << endl;
  cout << "         open   :  打开文件         " << endl;
  cout << "         close  :  打开文件         " << endl;
  cout << "         del    :  删除文件或目录         " << endl;
  cout << "         dir    :  列文件目录         " << endl;
  cout << "         quit   :  退出系统         " << endl
       << endl;
}

int run() // 运行文件系统
{
  char command[10];
  cout << "Linux:" << para << ">"; // 显示路径
  cin >> command;                  // 输入命令
  if (strcmp(command, "help") == 0)
    help();
  else if (strcmp(command, "mkdir") == 0)
    mkdir();
  else if (strcmp(command, "create") == 0)
    create();
  else if (strcmp(command, "dir") == 0)
    dir();
  else if (strcmp(command, "write") == 0)
    write();
  else if (strcmp(command, "read") == 0)
    read();
  else if (strcmp(command, "cd") == 0)
    cd();
  else if (strcmp(command, "del") == 0)
    del();
  else if (strcmp(command, "open") == 0)
    open();
  else if (strcmp(command, "close") == 0)
    close();
  else if (strcmp(command, "quit") == 0)
    return 0;
  else
    cout << "请参考help提供的命令列表" << endl;
}

int main()
{
  int flag; // 标记用户名密码是否正确
  char username[8], password[8];
  cout << "              -----------------------------------------------             " << endl;
  cout << "                           +++Linux文件系统+++                      " << endl;
  cout << "                   账号：user1-user4   密码：user1-user4                   " << endl;
  cout << "                                mkdir  目录名                                 " << endl;
  cout << "                                create 文件名                                 " << endl;
  cout << "                                write  文件名                                 " << endl;
  cout << "                                read   文件名                                 " << endl;
  cout << "                                cd     目录名                                 " << endl;
  cout << "                                open   文件名                                 " << endl;
  cout << "                                close  文件名                                 " << endl;
  cout << "                                del    文件名或目录名                     " << endl;
  cout << "                                dir                                 " << endl;
  cout << "                                quit                                 " << endl;
  cout << "                             输入help可获得帮助                             " << endl;
  cout << "              -----------------------------------------------             " << endl;
  cout << "请输入您的用户名：";
  cin >> username;
  cout << "请输入您的密码：";
  cin >> password;
  flag = login(username, password); // 检验用户输入用户名密码是否正确
  while (!flag)
  {
    cout << "用户名或密码错误，请重新输入" << endl;
    cout << "请输入您的用户名：";
    cin >> username;
    cout << "请输入您的密码：";
    cin >> password;
    flag = login(username, password);
  }
  if (flag) // 登录成功就会建立一个根目录
    creatroot();
  while (flag)
  {
    if (!run()) // 退出系统
      break;
  }
}
