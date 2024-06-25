#include <stdio.h>
#include <math.h>
void main()
{
    int sign=1;
    double pi=0,n=1,term=1;
    while (fabs(term)>=1e-6)
    {
        pi=pi+term;
        n=n+2;
        sign=-sign;
        term=sign/n;

    }
    printf("pi=%10.8f\n",pi*4);
}
