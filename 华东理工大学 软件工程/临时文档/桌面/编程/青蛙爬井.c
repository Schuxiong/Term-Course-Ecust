#include <stdio.h>
int main ()
{
    int high,up,down;
    scanf ("%d%d%d",&high,&up,&down);
    int day=1 ,sum=0;
    while (1)
    {
        sum += up;
        if(sum>=high)
            break;
        sum -=down;
        day ++;
    }
    printf ("%d\n",day);
    return 0;
}
