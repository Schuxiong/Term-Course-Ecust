#include <stdio.h>
#include <stdlib.h>
 
int main()
{
    int n, x;
    int high = 10, low = 1;
    int flag1,flag2;
    int result = 0;
    int zero;
    scanf("%d %d", &n, &x); 
    if(x == 0)
    {
        zero = 10;
    }
    else
    {
        zero = 1;
    }
    while(n/low/zero)   //数的最高位不能为0
    {
        if((n%high)/low < x) 
        {
            flag1 = 0;
            flag2 = 0;
        }
        if((n%high)/low == x)
        {
            flag1 = 0;
            flag2 = 1;
        }
        if((n%high)/low > x)
        {
            flag1 = 1;
            flag2 = 0;
        }
        result += (n/high+flag1-zero/10)*low+(n%low+1)*flag2;  //高位和低位的数之和
        high *= 10;
        low *= 10;
    }
    printf("%d\n", result);
    return 0;
}


