/*void deleteItoJ(SqlList &list,int i,int j,int n) {
	int t=j-i+1;
	for(int k=i; k<i+n-j; k++) {
		list.a[k]=list.a[k+t]; 
	}
	list.length=n-t;
}

#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int cnt=0,a[MAX];
typedef struct LNode{
	int data;		
	struct LNode *next;	 
}LNode,* LinkList;

//创建单链表 
void CreateList(LinkList &L,int n){//注意要使用C++编译器，C语言中不允许使用"&"
	L=(LinkList)malloc(sizeof(LNode));
	L->next=NULL;
	for(int i=0;i<n;i++){
		LinkList p=(LinkList)malloc(sizeof(LNode));
		scanf("%d",&p->data);
		p->next=L->next;
		L->next=p; 
	} 
}

//寻找公共结点 
void findCommonNodes(LinkList l1,LinkList l2){
	LinkList p=l1->next;
	while(p){
		LinkList q=l2->next;
		while(q){
			if(p->data==q->data){
				a[cnt++]=p->data;
			}
			q=q->next;
		}
		p=p->next;
	}
}
//打印公共结点 
void PrintCommonNodes(int n){
	if(n==0){
		printf("%d\n",0);
		printf("没有公共元素");
	}
	
	else{
		printf("%d\n",n);
		for(int i=n-1;i>=0;i--){
			printf("%d ",a[i]);
		}
	}
}
//销毁单链表 
void DestroyList(LinkList L)
{
    LinkList q,p=L;
    while(p!=0){
        q=p->next;
        free(p);
        p=q;
    }
    L=NULL;
}

int main(){
	int m,n;
	LinkList l1,l2; 
	scanf("%d",&m);
	CreateList(l1,m);
	scanf("%d",&n);
	CreateList(l2,n);
	findCommonNodes(l1,l2);
	DestroyList(l1);
	DestroyList(l2);
	PrintCommonNodes(cnt);
	return 0;
	
} 

void sort(LinkList &L){
	Lnode *p, *pre;
	Lnode *s;
	p = L->next;
	s = p->next;    
	p->next = NULL; 
	while (s!=NULL)
	{
		p = s;   
		s = s->next; 
		pre = L;
		while (pre->next != NULL && pre->next->data > p->data)
		{
			pre = pre->next;      
		}
		p->next = pre->next;
		pre->next = p;		
	}
}

void Change(SqStack *S,Elemtype str[])
{
	int i=0;
	Elemtype e;
	InitStack(S);
	while(str[i]!='\0')
	{
		while(isdigit(str[i])) 
			printf("%c",str[i++]);
			if(!isdigit(str[i]))
			{
				printf(" ");
			}
		}
		if(str[i]=='+'||str[i]=='-')
		{
			if(!StackLength(S))
			{
				PushStack(S,str[i]);
			}
			else
			{
				do
				{
					PopStack(S,&e);
					if(e=='(')
					{
						PushStack(S,e);
					}
					else
					{
						printf("%c ",e);
					}
				}while( StackLength(S) && e != '(' );
				
				PushStack(S,str[i]);
			}
		}
		else if(str[i]==')')
		{
			PopStack(S,&e);
			while(e!='(')
			{
				printf("%c ",e);
				PopStack(S,&e);
			}
		}
		else if(str[i]=='*'||str[i]=='/'||str[i]=='(')
		{
			PushStack(S,str[i]);
		}
		
		else if(str[i]=='\0')
		{
			break;
		}
		
		else
		{
			printf("\n输入格式错误！\n");
			return ;
		}
		i++;
	}
	while(StackLength(S))
	{
		PopStack(S,&e);
		printf("%c ",e);
	}
}

#include <stdio.h>
int main ()
{
	union key
	{
		int k;
		char ch[2];
	} u;
	u.k=258;
	printf("%d%d",u.ch[0],u.ch[1]);
	
	return 0;
}*/







