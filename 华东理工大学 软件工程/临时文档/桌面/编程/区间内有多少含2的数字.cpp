#include <stdio.h>
int main ()
{
	int L,R,num=0,i;
	scanf ("%d %d",&L,&R);
	for (i=L;i<=R;i++)
	{
		if (i%10==2)
		num++;
		if (i/10%10==2)
		num++;
		if (i/100%10==2)
		num++;
	}
	printf ("%d",num);
	return 0; 
 } 
