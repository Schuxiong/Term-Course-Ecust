#include <stdio.h>
#include <string.h>
int main ()
{
    char card[20];
	int i,t;
	while (scanf("%s",card)!=EOF)
	{
		int odd=0,even=0;
		for (i=strlen(card);i>=0;i--) 
		{
			if (i%2!=0)
			 odd+=card[i];
			 else if (i%2==0)
			 {
			 	t=2*(card[i]);
			 	if(t>9) 
			 	  t=t-9;
			 	  even+=t;
			 }
		}
		if ((odd+even)%10==0)
		    printf("Pass\n");
		else
		    printf("Fail\n");
	}
	return 0;
}
