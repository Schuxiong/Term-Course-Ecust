#include <stdio.h>
int main ()
{
    int m,k;
    scanf("%d%d",&m,&k);
    int day=0;
    while (1)
    {
        if(m/k==0)
        {
            day +=m%k;
            break;
        }
        else {
            day +=(m/k)*k;
            m=m/k+m%k;
        }
    }
    printf ("%d\n",day);
    return 0;
}
