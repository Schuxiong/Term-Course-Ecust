#include <stdio.h>
#include <string.h>
void change(char s[])
{
	int i;
	for (i=0;i<strlen(s);i++)
	 if (s[i]>='a'&&s[i]<='z') 
	 s[i]=s[i]-'a'+'A';    // 将小写字母变为大写 
}
int main ()
{
	int n,i;
	char s[100];
	scanf ("%s",&s);
	change (s);          //调用函数 
	printf ("%s",s);
	return 0; 
}
