#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
struct eee
{
	int Chinese,Math,English,Sum;
	char s[50];
}a[1001];

int main ()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%s%d%d%d",a[i].s,&a[i].Chinese,&a[i].Math,&a[i].English);
		a[i].Sum=a[i].Chinese+a[i].English+a[i].Math;
	}
	for ( int i=1;i<n;++i)
	 for (int j=i+1; j<=n;++j)
	  {
	  	if(a[i].s>a[j].s)
	  	{
	  		swap(a[i].s,a[j].s);
	  		swap(a[i].Chinese,a[j].Chinese);
	  		swap(a[i].English,a[j].English);
	  		swap(a[i].Math,a[j].Math);
		  }
	  }
	  for(int i=1;i<n;++i)
	   for (int j=i+1;j<=n;++j)
	   {
	   	if (abs(a[i].Chinese-a[j].Chinese)<=5 && abs(a[i].English-a[j].English)<=5 && abs(a[i].Math-a[j].Math)<=5 && abs(a[i].Sum-a[j].Sum)<=10)
	   	{
	   		printf ("%s %s\n",a[i].s,a[j].s);
		   }
	   }
	   return 0;
	 }

