#include <stdio.h>

struct student
{
	char name[50];
	int age ,score;
}   a[100000];

int main ()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s%d%d",a[i].name,&a[i].age,&a[i].score);
		a[i].age++,a[i].score=a[i].score/5*6;
		if (a[i].score>600)
		a[i].score=600;
		printf("%s %d %d\n",a[i].name,a[i].age,a[i].score);
	}
	return 0;
}
