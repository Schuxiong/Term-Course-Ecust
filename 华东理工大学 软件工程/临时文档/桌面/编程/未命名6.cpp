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
 		InOrderTraverse(T->lchild);//�ȷ�����ڵ�
		 printf ("%c",T->data);//����м�ڵ�
		 InOrderTraverse (T->rchild);//�������ҽڵ� 
	 }
 }
 
 
 //������
 void CreateBiTree (BiTree&T){
 	char ch;
 	scanf ("%c",&ch);
 	if(ch=='#') //#��ʾ����Ϊ��
	  T=NULL;
	  else{
	  	T=new BiTNode;
	  	T->data=ch;
	  	CreateBiTree (T->)
	  } 
 } 
