
#include <stdio.h> 
#include <math.h>
int a[100]; 
int prime (int n)   //��д���ú��� 
{
	int i,flag=1;
	if (n<2)
	   flag=0;      //С��2�������� 
	for (i=2;i<=sqrt(n);i++) 
	if  (n%i==0)
	 {
	 	flag=0;
	 	break;
	 }              //�ж�������һ��ѭ��
    return flag;
}

int main ()
{
	int n,i;
	scanf ("%d",&n);  //���� 
	for (i=0;i<n;i++)
	{
	  scanf ("%d",&a[i]);  //ɨ������ 
	  if (prime (a[i]))	
	     printf("%d ",a[i]);//���ú����ж� 
	}
	return 0; 
}
