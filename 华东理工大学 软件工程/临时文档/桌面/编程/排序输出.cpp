#include <stdio.h>

int a[4],t;
char ch;

int main()
{
	for(int i=1;i<=3;i++)
	 scanf("%d",&a[i]);
  //���н���һ�� 
	
	//���� 
	 if(a[2]<a[1]) t=a[2],a[2]=a[1],a[1]=t;
	 if(a[3]<a[2]) t=a[3],a[3]=a[2],a[2]=t;
	 if(a[2]<a[1]) t=a[2],a[2]=a[1],a[1]=t;
	 
	 //ƥ��ABC��˳�����
	 for (int i=1;i<=3;i++)
	 {
	 	scanf("%c",&ch);
	 	printf("%d",a[ch-'A'+1]);
	  } 
	  return 0;
}
