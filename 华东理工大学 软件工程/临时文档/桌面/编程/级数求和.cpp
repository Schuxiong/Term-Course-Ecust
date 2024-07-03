#include <stdio.h>
 main()
{ int i,j;
for(i=1;i<=3;i++)
{for(j=1;j<=21-i;j++)
putchar (' ');
for(j=1;j<=2*i-1;j++)putchar ('1');putchar ('\n');
}
return 0;
}
//for(i=2;i>=for(j=1;j<=21-i;j++)putc('');for(j=1;j<=2*i-1;j++)putc('$');fputc('\n');}
