#include <stdio.h>
int main ()
{
	float x,y;
	scanf ("%f",&x);
	if (x<0)
	return 0;
	else if (x<5)
	{
		y=-x+2.5;
	}
	else if (x<10)
	{
		y=2-1.5*(x-3)*(x-3);
	}
	else if (x<20)
	{
		y=x/2-1.5;
	}
	else return 0;
	printf ("%.3f",y);
	return 0;
}
