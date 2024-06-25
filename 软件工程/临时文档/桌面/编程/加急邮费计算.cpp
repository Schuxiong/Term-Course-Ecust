#include <stdio.h>
int main ()
{
	int m,fee;
	char ch;
	scanf ("%d %c",&m,&ch);
	if (m<1000)
	{
		fee=8;
	}
	else 
	{
		fee=8+((m-1000)/500+1)*4;
	}
	switch (ch)
	{
	case 'y': fee=fee+5;break;
	case 'n' : fee=fee;break;
    }
    printf ("%d",fee);
    return 0;
}
