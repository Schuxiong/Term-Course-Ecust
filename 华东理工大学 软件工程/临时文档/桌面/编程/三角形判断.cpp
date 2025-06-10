#include <stdio.h>
int main ()
{
	float a,b,c;
	int n;
	while (scanf("%d",&n)!=EOF)
	{
	while (n--)
	{
		scanf ("%f %f %f",&a,&b,&c);
	if (a+b>c && a+c>b && b+c>a)
	printf("YES\n");
	else
	printf("NO\n");
	} 
	}
	return 0;
}
