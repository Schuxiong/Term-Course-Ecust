#include <stdio.h>
int main()
{
	int s,hour,min,sec;
	scanf("%d",&s);
	hour=s/3600;
	min=(s%3600)/60;
	sec=(s%3600)%60;
	printf("%d:%d:%d",hour,min,sec);
	return 0;
}

