#include<stdio.h>
#include<string.h>

//ʹ����ȫ�ֱ���
char string[500];	//����������ַ���
int flag_have=0;	//�������Ƶ�һ������ַ����ǻ��ж���������Ĵ���

void scan_huistring(int printf_long,int scanf_long);
void printf_huistring(int printf_strat,int printf_last);

int main()
{
	int string_long,scan_long=0,i;  //string_long����������ַ������ַ�������; scan_long����ǰɨ���ַ��������λ�� 
	scanf("%s",string);
	string_long=strlen(string);
	
	for(i=2;i <= string_long;++i)	//���ѭ������ӻ��Ĵ�����Ϊ2��ʼѭ�� 
	{
		for(scan_long=0;(scan_long+i-1) < string_long;scan_long++)		scan_huistring(i,scan_long);
	}
	return 0;
} 

void scan_huistring(int printf_long,int scan_long)
{
	int j=scan_long,i=scan_long+printf_long-1,flag_huistring=1;	//j~iΪ��ʾ���ַ�����Ϊ���������Ļ��Ĵ��Ŀ�ʼλ��~��βλ��
	for(;j < i;j++,i--)		//�ӿ�ʼλ�úͽ�βλ�ÿ�ʼ�Ա��ַ��Ƿ���ͬ
	{
		if(string[j] != string[i])
		{
			flag_huistring=0;	//0�����ǻ��Ĵ���1�����ǻ��Ĵ�
			break;
		}
		else continue;;
	}
	
	if(flag_huistring==1)	//����ǻ��Ĵ�
	{
		if(flag_have == 1)	printf("\n");  //������Ƶ�һ�в��������
		flag_have=1;                       //�����������������Ĵ�ǰ�������
		printf_huistring(scan_long,scan_long+printf_long-1);	//���Ĵ��������
	}	
}


void printf_huistring(int printf_strat,int printf_last)
{
	for(;printf_strat <= printf_last;++printf_strat) printf("%c",string[printf_strat]);
}
