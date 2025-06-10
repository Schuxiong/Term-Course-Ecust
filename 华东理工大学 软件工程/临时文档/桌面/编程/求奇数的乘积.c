#include <stdio.h>
int main ()
{
    int n,a,p;
    while (scanf("%d",&n)!=EOF)
    {
        p=1;
        while (n--)
        {
            scanf ("%d",&a);
            if (a & 1)
                p*=a;
        }
        printf("%d\n",p);
    }
    return 0;
}
