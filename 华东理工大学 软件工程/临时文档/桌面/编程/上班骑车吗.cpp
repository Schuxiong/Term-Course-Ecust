#include <stdio.h>
int main ()
{
	double  d,t1,t2;
	scanf ("%lf",&d);
	t1=50+d/3;
	t2=d/1.2;
	if (t1<t2)
	{
		printf ("Bike");
	}
	else if (t1==t2)
	{
		printf ("All");
	
	}
	else printf ("Walk");
	return 0;
 } 
