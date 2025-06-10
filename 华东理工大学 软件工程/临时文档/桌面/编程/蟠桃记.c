#include <stdio.h>
int main ()
{
    int n,sum,p;
    while (scanf("%d",&n)!=EOF)
    {
        sum =0;
        p=1;
        for (int i=0;i<n-1;i++)
        {
            sum +=(p+1)*2;
            p=sum;
            sum =0;
        }
        printf ("%d\n",p);
    }
}
