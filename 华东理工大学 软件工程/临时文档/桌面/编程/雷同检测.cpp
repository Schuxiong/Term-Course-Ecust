#include <stdio.h> 
#include <string.h>
int main ()
{
	char s1[201],s2[201];
	int i;
	gets (s1);
	gets (s2);
	for (i=0;i<strlen(s1)&&strlen(s2);i++)
	{
		if (s1[i]==s2[i])
		 printf ("%d ",i+1);
	}
	return 0;
}
