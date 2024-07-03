#include <stdio.h>
int main ()
{
    long long n,m,p,q;
    scanf ("%lld%lld%lld%lld",&n,&m,&p,&q);
    long long ans = (n/p)*(m/q);
    printf ("%lld\n",ans);
    return 0;
}
