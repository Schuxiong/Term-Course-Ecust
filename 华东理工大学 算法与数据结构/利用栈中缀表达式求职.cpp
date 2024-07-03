#include<cstdio>
#include<stack>
#include<cstdlib>
#include <cstring>
#include <cctype>
 
using namespace std;
int pre(char c)//优先级
{
 
    if(c=='=') return 0;
    else if(c=='+'||c=='-')
        return 1;
    else if(c=='*'||c=='/')
        return 2;
    else return 0;
}
void calculate(stack<double> &num,stack<char> &op)
{
 
    double b=num.top();
    num.pop();
    double a=num.top();
    num.pop();
    switch(op.top())
    {
 
        case '+':num.push(a+b);
            break;
        case '-':num.push(a-b);
            break;
        case '*':num.push(a*b);
            break;
        case '/':num.push(a/b);
            break;
    }
    op.pop();
}
int main()
{
 
    stack<double> num;//数字
    stack<char> op;//操作符
    char s[100];
    while(1)//输入式子
    {
 
        scanf("%s",s);//读取
        if(!strcmp(s,"="))
            break;
        for(int i=0;s[i]!='\0';i++)
        {
 
            if(isdigit(s[i]))//判断是否为数字
            {
 
                double temp=atof(s + i);
                num.push(temp);
                while(isdigit(s[i])||s[i]=='.')
                    i++;
                i--;//前挪一位
            }
            else//字符是操作符
            {
 
                if(s[i]=='(')
                    op.push(s[i]);
                else if(s[i]==')')
                {
 
                    while(op.top()!='(')
                        calculate(num,op);
                    op.pop();
                }
                else if(op.empty()||pre(s[i])>pre(op.top()))
                    op.push(s[i]);
                else if(!op.empty()&&pre(s[i])<=pre(op.top()))
                {
 
                    while(!op.empty()&&pre(s[i])<=pre(op.top()))
                        calculate(num,op);
                    op.push(s[i]);//进栈
                }
            }
        }
        printf("%.2lf\n",num.top());//输出结果
        num.pop();
        op.pop();//清空栈
    }
    return 0;
}
