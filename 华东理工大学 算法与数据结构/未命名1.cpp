#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	
	int data;
	
	node *next;
	
}node;

node *create(){//β�巨�������� 
	
	node *p,*q,*head;//��������ָ�룬����p����һ������ָ��ɣ����������������������� 
	
	int n;//��ʾ��Ҫ������������ݸ��� 
	
	int i = 0;//��ʾ�Ѿ�������������ݸ���
	
	head = (node*)malloc(sizeof(node));//����ͷ�ڵ�
	
	head->next = NULL;//�������Ϊ��ʼ����������Ϊ�ձ� 
	
	q = head;//qʼ��ָ��β�ڵ㣬��ʼʱͷ�ڵ��β�ڵ�ʱͬһ��
	
	printf("����Ҫ������ٸ����ݣ�");
	
    scanf("%d",&n);
	
	printf("���������֣�");
	
	for(i = 0;i < n;i++){
		
		p = (node*)malloc(sizeof(node));//�������ݽڵ㣬������������ȴ����p���� 
		
		scanf("%d",&p->data);// ������������ 
		
		p->next = q->next;
	
	    q->next = p;
	
	    q = p;
	}
	
	return head;

}

void print(node *head){//������� 
	
	node *p; 
	
	p = (node*)malloc(sizeof(node));//��p�����ڴ�ռ䣬ʹ�����Դ������ 

	p = head->next;//��pָ��ʼ�ڵ� 

	printf("����������������Ԫ�أ�"); 
	
	while(p != NULL){//��p���ǿձ�ʱִ��������� 
		
		printf("%d ",p->data);
		
		p = p->next;
	}
	
}

int ListLength(node *head){//���㵥����ĳ��� 

    printf("\n"); 
	
	node *p = head;//��pָ��ͷ�ڵ� 
	
	int i = 0;
	
	while(p->next != NULL){//��p�ĺ�̽ڵ㲻Ϊ��ʱִ��������� 
		
		p = p->next;
		
		i++;//ִ��һ��ѭ����1��ֱ��p�ĺ�̽ڵ�Ϊ��ʱ����ѭ�� 
		
	}
	
	printf("������ĳ��ȣ�%d",i);

	return 0;
}

int LoacteElem(node *head){//��Ԫ��ֵ���� 

    printf("\n"); 
	
	node *p = head;//��pָ��ͷ�ڵ� 
	
	int j = 0,e;
	
	printf("����Ҫ���ҵ�����ֵ��");
	
	scanf("%d",&e);
	
	while(p->next != NULL && p->data != e){
		
		p = p->next;
		
		j++;
		
	}
	
	printf("���ҵ����ݵ�λ�ã�%d",j);
	
	return 0;
}

int GetElem(node *head){//����Ԫ�� 
	
	printf("\n");
	
	int i,e,m;//i�������൱��ָ��������ڼ����ڵ㡢e��ʾ��Ҫ���ҵڼ���λ�õ�Ԫ�ء�m��ʾ�ҵ���Ҫ���ҵ����ݵ�ֵ�� 
	
	node *p = head;//ͬ������· 
	
	printf("������Ҫ�������ݵ�λ�ã�"); 
	
	scanf("%d",&e);
	
	for(i=0;i<e;i++){
	
		p = p->next;

	}
	
	m = p->data;
	
	printf("λ��Ϊ%d��������%d",e,m);

	return 0;
}

node *Insert(node *head){//����Ԫ�� 

    printf("\n");
	
	node *p = head;
	
	node *q;
	
	int j = 0,i,e;//ͬ����j��ʾָ��p�������������ݵ�λ�ã�i��e��ʾҪ�ڵ�i��λ�ò�������e�� 
	
	printf("����Ҫ�����Ԫ�ص�λ�ã�");
	
	scanf("%d",&i);
	
	printf("����Ҫ�����Ԫ�ص�ֵ��");
	
	scanf("%d",&e); 
	
	for(j = 0;j < i-1;j++){
		
		p = p->next;
		
	} 
	
	q = (node*)malloc(sizeof(node));
	
	q->data = e;//��󼸲���������ⲻ�˿������Ż�ͼ���໭���Σ�������������ָ���򵽵�ָ����ʲô�ͱ�úܼ��� 
	
	q->next = p->next;
	
	p->next = q;
	
	return head;

}

node *Delete(node *head){//ɾ��Ԫ�� 

    printf("\n");
	
	node *p = head;//����· 
	
	node *q,*r;
	
	int j = 0,i;//j��ʾָ��p����������ĵڼ������ݣ�i��ʾɾ����i��λ�õ����� 
	
	printf("������ɾ�����ݵ�λ�ã�");
	
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

if��p == NULL��{

    return 0;

}


