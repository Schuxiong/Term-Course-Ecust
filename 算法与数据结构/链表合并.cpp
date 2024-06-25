#include <stdio.h>
#include <stdlib.h>
//尾插法  
typedef struct listnode 
{
    int val;
    struct listnode* next;
}listnode;

void ListInit(listnode* l)
{
    //头节点
    l->next = NULL;
}

void ListCreate(listnode* l)
{
    //建立链表
    int i = 1;
    int j;
    while (i)
    {
        scanf("%d", &j);
        if (j == '\n')   //当从键盘读取完数，即为-1时，终止建立
            i = 0;
        else
        {
            listnode* New = (listnode*)malloc(sizeof(listnode));//为新的结点分派内存
            New->val = j;//储存
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
    //讨论l1 l2为空
    listnode* head, * tail = NULL;
    listnode* L = l1;  //头结点
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
        //取小尾插新链表
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


void ListPrint(listnode* l)  //输出链表 
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
    //为结点分配内存
    listnode* l1 = (listnode*)malloc(sizeof(listnode));
    listnode* l2 = (listnode*)malloc(sizeof(listnode));

    //初始化结点
    ListInit(l1);
    ListInit(l2);

    //建立链表
    ListCreate(l1);
    ListCreate(l2);

    //输出合并后的新表
    listnode* l3 = MergeTwoLists(l1, l2);
    ListPrint(l3);
    return 0;
}
