#include <stdio.h> 
double avg_score(int s[],int m)
{
	int i,max,min,sum;
	max=min=sum=s[0];
	for (i=1;i<m;i++)
	 {
	 	sum+=s[i];            //�����ܺ� 
	 	if (s[i]>max)
	 	   max=s[i];          //ɸѡ���ֵ 
	 	else if (s[i]<min)
	 	   min=s[i];          //ɸѡ��Сֵ 
 	 }
 	sum=sum-max-min;          //��ȥ�����Сֵ 
 	return (double)sum/(double)(m-2) ;
}
int main ()
{
	int score[20],n,m,i,j;  
	double avg[100],first=0;
	scanf ("%d%d",&n,&m);  //n��ѡ��m������ 
	for (i=0;i<n;i++)         //һ��һ��ѡ�ֵ������� 
	{
		for (j=0;j<m;j++)     //һ��һ�������ۼ�ɸѡ��� 
		{
		 scanf("%d",&score[j]);
	    }
	avg[i]=avg_score(score,m); //�����ճɼ� 
	if (avg[i]>first)
	first=avg[i];              //�жϳ���һ�� 
	}
	printf("%.2lf",first);    
	return 0;
 } 
