#include <stdio.h> 
#define N 5
int main ()
{
	int a[N],i,temp;  //定义变量
	for (i=0;i<N;i++)
	 scanf("%d",&a[i]); //输入变量 
	for(i=0;i<N/2;i++)   //将对称元素交换 
	{
		temp=a[i];
		a[i]=a[N-1-i];
		a[N-1-i]=temp;
		//常见的交换变量的方法 
	}
	for (i=0;i<N;i++)
	  printf ("%2d",a[i]);  //按新的顺序输出
	  printf ("\n") ;
	  return 0;
}
