#include <stdio.h>
int main()
{
    int fac(int n);
    int y,n;
    scanf("%d",&n);
    y=fac(n);
    printf("%d!=%d\n",n,y);
    return 0;
}
int fac (int n)
{
    int f;
    if (n<0)
        printf("n<0,error!");
    else if(n==0||n==1) f=1;
    else f =n*fac(n-1);
    return (f);
}
