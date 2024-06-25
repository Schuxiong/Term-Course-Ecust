#include <stdio.h>

struct node
{
	int id;
	double sc1,sc2;
	int score;
	double  finalscore; 
}a[1000];

int main()
{
	int n;
	scanf("%d",&n);

	for (int i=0;i<n;i++)
	{
		scanf("%d%lf%lf",&a[i].id,&a[i].sc1,&a[i].sc2 );
		a[i].score=a[i].sc1+a[i].sc2; 
		a[i].finalscore=a[i].sc1*0.7+a[i].sc2*0.3;
	}
	for (int i=0;i<n;i++)
	{
		if (a[i].score>140 && a[i].finalscore>=80)
		{
			printf("Excellent\n");
		}
		else
		{
			printf("Not excellent\n"); 
		}
	}
	return 0;
}
