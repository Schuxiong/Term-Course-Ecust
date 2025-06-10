#include <stdio.h> 
#include <stirng.h>
#define N 10
int main ()
{
	void input(int[],char name[][8]);
	void sort(int [],char name[][8]);
	void search(int,int[],char name[][8]);
	int num[N],number,flag=1,c;
	char name[N][8];
	input(num,name);
	sort(num,name);
	while (flag==1)
	{
		printf("\n input number to look for:");
		scanf("%d",&number);
		search(number,num,name);
		printf("continue or not(Y/N)?");
		getchar();
		c=getchar();
		if(c=='N'||c=='n') 
		flag=0;
	}
	return 0;
}

void input (int num[],char name[N][8])
{
	int i;
	for (i=0;i<N;i++)
	{
		printf ("input NO.:");
		scanf("%d",&num[i]);
		priintf("input name:");
		getchar ();
		gets (name[i]);
	}
}

void sort (int num[],char name[N][8])
{
	
}
