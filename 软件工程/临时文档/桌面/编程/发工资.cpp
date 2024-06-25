#include <stdio.h>
int main ()
{
	int x1,x2,x3,x4,x5,x6,x,i,j,k,n,m,sum;
    while(scanf("%d\n",&n)!=EOF)
    {
        x=0;
        if(n==0)
            break;
        if(n!=0)
        {
            for(i=1;i<=n;i++)
            {
                scanf("%d",&m);
                x1=m/100;
                j=m%100;
                x2=j/50;
                x3=(j%50)/10;
                k=m%10;
                x4=k/5;
                x5=(k%5)/2;
                x6=(k%5)%2;
                sum=x1+x2+x3+x4+x5+x6;
                x=x+sum;
            }
            printf("%d\n",x);
        }
    }
    return 0;	
}
