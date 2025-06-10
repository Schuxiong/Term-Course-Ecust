#include <stdio.h>
#include <stdlib.h>
//β�巨  
typedef struct listnode 
{
    int val;
    struct listnode* next;
}listnode;

void ListInit(listnode* l)
{
    //ͷ�ڵ�
    l->next = NULL;
}

void ListCreate(listnode* l)
{
    //��������
    int i = 1;
    int j;
    while (i)
    {
        scanf("%d", &j);
        if (j == '\n')   //���Ӽ��̶�ȡ��������Ϊ-1ʱ����ֹ����
            i = 0;
        else
        {
            listnode* New = (listnode*)malloc(sizeof(listnode));//Ϊ�µĽ������ڴ�
            New->val = j;//����
            l->next = New;
            New->next = NULL;
            l = l->next;
        }
    }
}

listnode* MergeTwoLists(listnode*l1, listnode* l2)
{
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;
    //����l1 l2Ϊ��
    listnode* head, * tail = NULL;
    listnode* L = l1;  //ͷ���
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
        //ȡСβ��������
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
