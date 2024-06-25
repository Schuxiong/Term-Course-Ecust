#include<stdio.h>
int main(){
    int n,i,a,sum;
    scanf("%d",&n);
    while(n--)
    {
        sum=3;
        scanf("%d",&a);
        for(i=0;i<a;i++)
            sum=(sum-1)*2;
        printf("%d\n",sum);
    }
    return 0;
}

