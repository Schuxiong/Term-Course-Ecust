#include <stdio.h> 
#define N 5
int main ()
{
	int a[N],i,temp;  //�������
	for (i=0;i<N;i++)
	 scanf("%d",&a[i]); //������� 
	for(i=0;i<N/2;i++)   //���Գ�Ԫ�ؽ��� 
	{
		temp=a[i];
		a[i]=a[N-1-i];
		a[N-1-i]=temp;
		//�����Ľ��������ķ��� 
	}
	for (i=0;i<N;i++)
	  printf ("%2d",a[i]);  //���µ�˳�����
	  printf ("\n") ;
	  return 0;
}
