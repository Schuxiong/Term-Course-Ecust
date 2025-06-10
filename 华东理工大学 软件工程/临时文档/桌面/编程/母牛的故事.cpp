#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int main ()
{
	int num[100]={0};
	int n,i;
	num[1]=1,num[2]=2,num[3]=3;
	for(i=4;i<56;i++)
	{
		num[i]=num[i-1]+num[i-3];
	}
	while (scanf("%d",&n),n)
	{
		printf("%d\n",num[n]);
	}
	return 0;
}
