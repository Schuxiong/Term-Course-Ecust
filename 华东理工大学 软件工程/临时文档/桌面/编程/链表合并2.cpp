#include <stdio.h>
#include <stdlib.h>

//ȡС�Ľ�㣬β�嵽������������ȡ��ע�⣺��һ�������������β�壬ֻ�Ǹ���head��tail�����Բ�Ӧ����ѭ�������濪ʼ����
//��һ��tail ʼ��ָ���������β��l1 l2�������� ��һ��Ϊ���ˣ���һ��ʣ�µ�ȫ��һ�����ӵ��µĺ���
//���ǿ�ʼ ���� ���������

typedef struct listnode 
{
    int val;
    struct listnode* next;
}listnode;

void ListInit(listnode* l)
{
    //��ʼ��ͷ�ڵ�
    l->next = NULL;
}

void ListCreate(listnode *l)
{
    //��������
    int j = 1;
    do
    {
    	scanf("%d",&j);
        listnode *New = (listnode*)malloc(sizeof(listnode));//Ϊ�µĽ������ڴ�
        New->val = j;//��������
        /*
        ��������next��ָ���½��new
        ���½���next����Ϊ��
        */
        l->next = New;
        New->next = NULL;
        l = l->next;
        }while(getchar() !='\n');
    }

listnode* MergeTwoLists(listnode*l1, listnode* l2)
{
    //����l1 l2Ϊ�յ����
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;

    listnode* head, * tail = NULL;
    listnode* L = l1;  //��¼��ͷ���

    //��ȡһ��С��ȥ����һ����㣬�������β��
    if (l1->val < l2->val)
    {
        head = tail = l1;
        l1 = l1->next;
    }
    else
    {
        head = tail = l2;
        l2 = l2->next;
    }

    while (l1 && l2)
    {
        //ȡС��β��������
        if (l1->val < l2->val)
        {
            tail->next = l1;
            l1 = l1->next;
        }
    else
    {
        tail->next = l2;
        l2 = l2->next;
    }
    tail = tail->next;
    }

    if (l1)
    {
        tail->next = l1;
    }
    if (l2)
    {
        tail->next = l2;
    }
    return L;
}


void ListPrint(listnode* l)  //������� 
{                         
    while (l->next) 
	{
        printf("%d ", l->next->val);
        l = l->next;
    }
	printf("\n");
}


int main()
{
    //Ϊ�������ڴ�
    listnode* l1 = (listnode*)malloc(sizeof(listnode));
    listnode* l2 = (listnode*)malloc(sizeof(listnode));

    //��ʼ�����
    ListInit(l1);
    ListInit(l2);

    //��������
    ListCreate(l1);
    ListCreate(l2);

    //����ϲ�����±�
    listnode* l3 = MergeTwoLists(l1, l2);
    ListPrint(l3);
    return 0;
}
