#include<cstdio>
#include<stack>
#include<cstdlib>
#include <cstring>
#include <cctype>
 
using namespace std;
int pre(char c)//���ȼ�
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
 
    stack<double> num;//����
    stack<char> op;//������
    char s[100];
    while(1)//����ʽ��
    {
 
        scanf("%s",s);//��ȡ
        if(!strcmp(s,"="))
            break;
        for(int i=0;s[i]!='\0';i++)
        {
 
            if(isdigit(s[i]))//�ж��Ƿ�Ϊ����
            {
 
                double temp=atof(s + i);
                num.push(temp);
                while(isdigit(s[i])||s[i]=='.')
                    i++;
                i--;//ǰŲһλ
            }
            else//�ַ��ǲ�����
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
                    op.push(s[i]);//��ջ
                }
            }
        }
        printf("%.2lf\n",num.top());//������
        num.pop();
        op.pop();//���ջ
    }
    return 0;
}
