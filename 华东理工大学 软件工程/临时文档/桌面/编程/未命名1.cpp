#                                        include <stdio.h>
#include <stdlib.h>
struct Node {
	int data;               //数据域
	struct Node* next;      //指针域
};

struct Node* createList()
{
	struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
	//headNode就成为了结构体变量
	//变量使用前初始化
	headNode->next = NULL;
	return headNode;
}

//创建节点
struct Node* createNode(int data) 
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

//打印节点
void printList(struct Node* headNode)
{
	struct Node* pMove = headNode->next;
	while (pMove)
	{
		printf("%d", pMove->data);
		pMove = pMove->next;
	}
	printf("\n");
}
//插入节点，参数，链表数据
void insertNode_By_Head(struct Node* headNode, int data)
{
	//创建一个新的节点
	struct Node* newNode = createNode(data);
	newNode->next = headNode->next;
	headNode->next = newNode;
}


int main()
{
	struct Node* list = createList();
	insertNode_By_Head(list, 1);
	insertNode_By_Head(list, 2);
	insertNode_By_Head(list, 3);
	printList(list);
	system("pause");
	return 0;
}
