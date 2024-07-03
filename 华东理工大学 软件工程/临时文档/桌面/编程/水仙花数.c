#include <stdio.h>
int main()
{
    int m,n,count,i,t;
    while (scanf("%d%d",&m,&n)!=EOF)
    {
        count=0;
        for (i=m;i<=n;i++)
        {
            int sum=0;
            t=i;
            while(t)
            {
                int t2=t%10;
                sum +=t2*t2*t2;
                t/=10;
            }
            if(sum==i)
            {
                if(count>0) printf(" ");
                printf ("%d",i);
                count++;
            }
        }
        if (count==0) printf("no");
        printf("\n");
}
return 0;
}
