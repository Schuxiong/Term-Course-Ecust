#include <stdio.h>
#include <math.h>
double dis(double x1,double y1,double x2,double y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int main ()
{
	double x[3],y[3],c;
	int i;
	for (i=0;i<3;i++)
	scanf ("%lf %lf",&x[i],&y[i]);
	c = dis(x[0],y[0],x[1],y[1])+dis(x[2],y[2],x[1],y[1])+dis(x[0],y[0],x[2],y[2]);
	printf ("%.2lf",c);
	return 0;
}
