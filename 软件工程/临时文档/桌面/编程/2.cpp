#include <stdio.h>
#include <math.h>
int main ()
{
	int L,R,num=0,i;
	scanf ("%d %d",&L,&R);
	for (i=L;i<=R;i++)
	if 
	(int sum=0;
    int n,x,y;
    int s=0;
    scanf("%d",&n);
    y=x=n;
    do
    {
        n=n/10;
        s++;
    }while(n!=0);
    printf("%d 是 %d 位数\n",x,s);
    int num[s];
    for(int i=s-1;i>=0;i--)
    {
        num[i]=x%10;
        x=x/10;
    }
    for(int i=0;i<s;i++)
    {
        sum+=pow(num[i],s);
    }
    if(sum==y)
    {
        printf("%d 是阿姆斯壮数",y);
    }else
    {
        printf("%d 不是阿姆斯壮数",y);
    })
}
