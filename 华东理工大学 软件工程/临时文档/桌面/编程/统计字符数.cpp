#include <stdio.h>
int main ()
{
	char s[1000];
	int num[26]={0};
	int i,max;
	scanf ("%s",s);
	for (i=0;s[i]!='\0';i++)
	 num[s[i]-'a']++;
	for (max=0,i=1;i<26;i++) 
	 {
	 	if (num[i]>num[max])
	 	max=i;
	  } 
	  printf ("%c %d",'a'+max,num[max]);
	  return 0;
}
