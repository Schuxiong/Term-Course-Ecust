#include<stdio.h>
#include<string.h>

//使用了全局变量
char string[500];	//代表输入的字符串
int flag_have=0;	//用来控制第一个输出字符不是换行而是输出回文串。

void scan_huistring(int printf_long,int scanf_long);
void printf_huistring(int printf_strat,int printf_last);

int main()
{
	int string_long,scan_long=0,i;  //string_long代表输入的字符串的字符串长度; scan_long代表当前扫描字符串数组的位置 
	scanf("%s",string);
	string_long=strlen(string);
	
	for(i=2;i <= string_long;++i)	//这个循环代表从回文串长度为2开始循环 
	{
		for(scan_long=0;(scan_long+i-1) < string_long;scan_long++)		scan_huistring(i,scan_long);
	}
	return 0;
} 

void scan_huistring(int printf_long,int scan_long)
{
	int j=scan_long,i=scan_long+printf_long-1,flag_huistring=1;	//j~i为表示将字符串分为各个待检测的回文串的开始位置~结尾位置
	for(;j < i;j++,i--)		//从开始位置和结尾位置开始对比字符是否相同
	{
		if(string[j] != string[i])
		{
			flag_huistring=0;	//0代表不是回文串，1代表是回文串
			break;
		}
		else continue;;
	}
	
	if(flag_huistring==1)	//如果是回文串
	{
		if(flag_have == 1)	printf("\n");  //这里控制第一行不输出换行
		flag_have=1;                       //这里控制往后输出回文串前输出换行
		printf_huistring(scan_long,scan_long+printf_long-1);	//回文串输出函数
	}	
}


void printf_huistring(int printf_strat,int printf_last)
{
	for(;printf_strat <= printf_last;++printf_strat) printf("%c",string[printf_strat]);
}
