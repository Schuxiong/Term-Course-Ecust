#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	
	int data;
	
	node *next;
	
}node;

node *create(){//尾插法创建链表 
	
	node *p,*q,*head;//定义三个指针，其中p类似一个辅助指针吧，用来存放所输入的链表数据 
	
	int n;//表示想要输入的链表数据个数 
	
	int i = 0;//表示已经输入的链表数据个数
	
	head = (node*)malloc(sizeof(node));//创建头节点
	
	head->next = NULL;//可以理解为初始化链表，让它为空表 
	
	q = head;//q始终指向尾节点，开始时头节点和尾节点时同一个
	
	printf("你想要输入多少个数据：");
	
    scanf("%d",&n);
	
	printf("请输入数字：");
	
	for(i = 0;i < n;i++){
		
		p = (node*)malloc(sizeof(node));//创建数据节点，让输入的数据先存放在p里面 
		
		scanf("%d",&p->data);// 输入链表数据 
		
		p->next = q->next;
	
	    q->next = p;
	
	    q = p;
	}
	
	return head;

}

void print(node *head){//输出链表 
	
	node *p; 
	
	p = (node*)malloc(sizeof(node));//给p分配内存空间，使它可以存放数据 

	p = head->next;//让p指向开始节点 

	printf("输出单链表里的所有元素："); 
	
	while(p != NULL){//当p不是空表时执行下面语句 
		
		printf("%d ",p->data);
		
		p = p->next;
	}
	
}

int ListLength(node *head){//计算单链表的长度 

    printf("\n"); 
	
	node *p = head;//让p指向头节点 
	
	int i = 0;
	
	while(p->next != NULL){//当p的后继节点不为空时执行下面语句 
		
		p = p->next;
		
		i++;//执行一次循环加1，直到p的后继节点为空时跳出循环 
		
	}
	
	printf("单链表的长度：%d",i);

	return 0;
}

int LoacteElem(node *head){//按元素值查找 

    printf("\n"); 
	
	node *p = head;//让p指向头节点 
	
	int j = 0,e;
	
	printf("输入要查找的数据值：");
	
	scanf("%d",&e);
	
	while(p->next != NULL && p->data != e){
		
		p = p->next;
		
		j++;
		
	}
	
	printf("查找的数据的位置：%d",j);
	
	return 0;
}

int GetElem(node *head){//查找元素 
	
	printf("\n");
	
	int i,e,m;//i的作用相当于指针遍历到第几个节点、e表示想要查找第几个位置的元素、m表示找到想要查找的数据的值） 
	
	node *p = head;//同样的套路 
	
	printf("请输入要查找数据的位置："); 
	
	scanf("%d",&e);
	
	for(i=0;i<e;i++){
	
		p = p->next;

	}
	
	m = p->data;
	
	printf("位置为%d的数据是%d",e,m);

	return 0;
}

node *Insert(node *head){//插入元素 

    printf("\n");
	
	node *p = head;
	
	node *q;
	
	int j = 0,i,e;//同样，j表示指针p遍历到链表数据的位置，i、e表示要在第i个位置插入数据e） 
	
	printf("输入要插入的元素的位置：");
	
	scanf("%d",&i);
	
	printf("输入要插入的元素的值：");
	
	scanf("%d",&e); 
	
	for(j = 0;j < i-1;j++){
		
		p = p->next;
		
	} 
	
	q = (node*)malloc(sizeof(node));
	
	q->data = e;//最后几步大家如果理解不了可以试着画图，多画几次，搞清楚数据域和指针域到底指的是什么就变得很简单了 
	
	q->next = p->next;
	
	p->next = q;
	
	return head;

}

node *Delete(node *head){//删除元素 

    printf("\n");
	
	node *p = head;//老套路 
	
	node *q,*r;
	
	int j = 0,i;//j表示指针p遍历到链表的第几个数据，i表示删除第i个位置的数据 
	
	printf("请输入删除数据的位置：");
	
	scanf("%d",&i);
	
	for(j = 0;j < i-1;j++){
		
		p = p->next;
		
	}
	
	q = (node *)malloc(sizeof(node));

	q = p;
	
	r=q->next;
	
	p->next=r->next;

	return head;
}

if（p == NULL）{

    return 0;

}


