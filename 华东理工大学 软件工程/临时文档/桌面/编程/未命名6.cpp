#include<stdio.h>
#define MAXSIZE 100
typedef char TElemtype;
typedef struct BiTNode
{
	TElemtype data;
	struct BiTNode* lchild,rchild;
 } BiTNode ,*BiTree;
 
 void InOrderTraverse(BiTree T){
 	if(T){
 		InOrderTraverse(T->lchild);//先访问左节点
		 printf ("%c",T->data);//输出中间节点
		 InOrderTraverse (T->rchild);//最后访问右节点 
	 }
 }
 
 
 //创建树
 void CreateBiTree (BiTree&T){
 	char ch;
 	scanf ("%c",&ch);
 	if(ch=='#') //#表示子树为空
	  T=NULL;
	  else{
	  	T=new BiTNode;
	  	T->data=ch;
	  	CreateBiTree (T->)
	  } 
 } 
