
#include <stdio.h> 
#include <math.h>
int a[100]; 
int prime (int n)   //先写调用函数 
{
	int i,flag=1;
	if (n<2)
	   flag=0;      //小于2不是质数 
	for (i=2;i<=sqrt(n);i++) 
	if  (n%i==0)
	 {
	 	flag=0;
	 	break;
	 }              //判断质数的一个循环
    return flag;
}

int main ()
{
	int n,i;
	scanf ("%d",&n);  //输入 
	for (i=0;i<n;i++)
	{
	  scanf ("%d",&a[i]);  //扫描数字 
	  if (prime (a[i]))	
	     printf("%d ",a[i]);//调用函数判断 
	}
	return 0; 
}
