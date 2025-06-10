#include <stdio.h> 
double avg_score(int s[],int m)
{
	int i,max,min,sum;
	max=min=sum=s[0];
	for (i=1;i<m;i++)
	 {
	 	sum+=s[i];            //先求总和 
	 	if (s[i]>max)
	 	   max=s[i];          //筛选最大值 
	 	else if (s[i]<min)
	 	   min=s[i];          //筛选最小值 
 	 }
 	sum=sum-max-min;          //减去最大最小值 
 	return (double)sum/(double)(m-2) ;
}
int main ()
{
	int score[20],n,m,i,j;  
	double avg[100],first=0;
	scanf ("%d%d",&n,&m);  //n个选手m个评分 
	for (i=0;i<n;i++)         //一个一个选手地来计算 
	{
		for (j=0;j<m;j++)     //一个一个评分累加筛选求和 
		{
		 scanf("%d",&score[j]);
	    }
	avg[i]=avg_score(score,m); //求最终成绩 
	if (avg[i]>first)
	first=avg[i];              //判断出第一名 
	}
	printf("%.2lf",first);    
	return 0;
 } 
