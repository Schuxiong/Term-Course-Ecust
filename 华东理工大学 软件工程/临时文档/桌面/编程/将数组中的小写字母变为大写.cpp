#include <stdio.h>
#include <string.h>
void change(char s[])
{
	int i;
	for (i=0;i<strlen(s);i++)
	 if (s[i]>='a'&&s[i]<='z') 
	 s[i]=s[i]-'a'+'A';    // ��Сд��ĸ��Ϊ��д 
}
int main ()
{
	int n,i;
	char s[100];
	scanf ("%s",&s);
	change (s);          //���ú��� 
	printf ("%s",s);
	return 0; 
}
