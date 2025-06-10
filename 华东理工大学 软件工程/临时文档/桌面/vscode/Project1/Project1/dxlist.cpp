#include <stdio.h>
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
		printf("%d\t", pMove->data);
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

//�����ɾ��
void deleteNode_By_Appoint(struct Node* headNode, int posData)
{
	struct Node* posNode = headNode->next;
	struct Node* posNodeFront = headNode;
	if (posNode == NULL)
		printf("�޷�ɾ��������Ϊ��");
	else {
		while (posNode->data != posData) {
			posNodeFront = posNode;
			posNode = posNodeFront->next;
			if (posNode == NULL)
			{
				printf("û���ҵ������Ϣ���޷�ɾ��");                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
				break;
			}
		}
		posNodeFront->next = posNode->next;//�ҵ��ˣ���ʼ�滻ɾ��
		free(posNode);
	}
	
}


int main()
{
	struct Node* list = createList();
	insertNode_By_Head(list, 1);
	insertNode_By_Head(list, 2);
	insertNode_By_Head(list, 3);
	printList(list);
	deleteNode_By_Appoint(list, 2);
	printList(list);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
	system("pause");
	return 0;
}
/*struct Node Node1 = {1,NULL};
	struct Node Node2 = { 2,NULL };
	struct Node Node3 = { 3,NULL };
	Node1.next = &Node2;
	Node2.next = &Node3;
	*/