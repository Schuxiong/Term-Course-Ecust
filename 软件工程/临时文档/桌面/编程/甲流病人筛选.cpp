#include <stdio.h>
int main ()
{
	int n,i,sum=0;
	char name[9] ;
	double temperature;
	int cough;
	scanf ("%d",&n);
	for (i=1;i<=n;i++)
	{
	scanf ("%s%lf%d",name,&temperature,&cough);
	  if(temperature>=37.5 && cough==1)
	  {
	  	printf ("%s\n",name);
	  	sum++;
	  }
}
	printf ("%d",sum);
	return 0;
}
