#include <stdio.h>
int main ()
{
	int i,j,a[]={1,3,5,7,9,11,13,15};
	i=5;
	switch(i)
	{
		default:printf("%d\n",a[i]);break;
		case 1: printf("%d\n",a[3]);break;
		case 2:printf("%d\n",a[++i]);break;
		case 3:printf("%d\n",a[--i]);
		
	}
	return 0;
}
