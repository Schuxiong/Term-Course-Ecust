#                                        include <stdio.h>
#include <stdlib.h>
struct Node {
	int data;               //������
	struct Node* next;      //ָ����
};

struct Node* createList()
{
	struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
	//headNode�ͳ�Ϊ�˽ṹ�����
	//����ʹ��ǰ��ʼ��
	headNode->next = NULL;
	return headNode;
}

//�����ڵ�
struct Node* createNode(int data) 
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

//��ӡ�ڵ�
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
//����ڵ㣬��������������
void insertNode_By_Head(struct Node* headNode, int data)
{
	//����һ���µĽڵ�
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
