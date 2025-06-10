#include<stdio.h>
#define MAXSIZE 100
typedef char TElemType;
typedef struct BiTNode{
	TElemType data;
	struct BiTNode* lchild,*rchild;
}BiTNode,*BiTree;

//����������� 
void InOrderTraverse(BiTree T){
	if(T){
		InOrderTraverse(T->lchild );//�ȷ�����ڵ� 
		printf("%c",T->data);//�����м�ڵ� 
		InOrderTraverse(T->rchild ); //�������ҽڵ� 
	}
}

//�������������˳�򴴽��� 
void CreateBiTree(BiTree&T){
	char ch;
	scanf("%c",&ch);
	if(ch=='#')//��#��ʾ����Ϊ�� 
		T=NULL;
	else{
		T=new BiTNode;//��̬�������� 
		T->data=ch;//����ָ��������� 
		CreateBiTree(T->lchild);//���������� 
		CreateBiTree(T->rchild);//���������� 
	}
} 

//��ȡ��������ĵ�k����� 
int i = 0;//��ֵi 
void getNode(BiTree T, int k) {
	if (T==NULL)//����TΪ�յĻ���������һ�� 
		return ;
	
	getNode(T->lchild,k);//���������� 

	i++;
	if (i == k) {// Ѱ�ҵ���k�����֮������ýڵ� 
		printf("%c\n",T->data);
	}
		
	getNode(T->rchild,k);//���������� 
}

int main(){
	BiTree T;
	printf("�������������Ԫ�أ�\n");
	CreateBiTree(T);
	printf("�����������Ϊ��\n");
	InOrderTraverse(T);
	int k;
	printf("\n����k:");
	scanf("%d",&k);
	printf("����������еĵ�%d�����Ϊ��",k);
	getNode(T, k);
	return 0;
}

