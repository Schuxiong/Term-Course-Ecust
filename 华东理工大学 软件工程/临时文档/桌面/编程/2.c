#include<stdio.h>
#include<math.h>
int main()
{
	int n,x;
	float m;
	scanf("%d%f",&n,&m);
	x=(int)((m*n)/10);
	if(x%10<5)
	x=(x/10)*10;
	else
	x=(x/10+1)*10;
	printf("%d",x);
	return 0;
}
