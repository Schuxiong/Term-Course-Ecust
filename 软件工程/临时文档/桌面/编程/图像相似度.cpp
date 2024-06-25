#include <stdio.h>
#include <stdlib.h>
#define Max 101
int main()
{
    int m,n;
    int i,j;
    int sum=0;
    int matrix[Max][Max];
    int point;
    scanf("%d%d",&m,&n);
    for (i=1;i<=m;i++)
        for (j=1;j<=n;j++)
            scanf("%d", &matrix[i][j]);
    for (i=1;i<=m;i++)
        for (j=1;j<=n;j++)
        {
            scanf("%d", &point);
            if (point==matrix[i][j])
                sum++;
        }
    printf("%.2f",(float)(sum*100)/(m*n));

    return 0;
}



