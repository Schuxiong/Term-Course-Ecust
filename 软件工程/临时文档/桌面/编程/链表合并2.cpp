#include <stdio.h>
#include <stdlib.h>

//取小的结点，尾插到新链表（相等随便取）注意：第一个结点下来不是尾插，只是给给head和tail，所以不应放入循环。后面开始才是
//加一个tail 始终指向新链表结尾，l1 l2依次往后 当一个为空了，另一个剩下的全部一起链接到新的后面
//考虑开始 迭代 结束的情况

typedef struct listnode 
{
    int val;
    struct listnode* next;
}listnode;

void ListInit(listnode* l)
{
    //初始化头节点
    l->next = NULL;
}

void ListCreate(listnode *l)
{
    //建立链表
    int j = 1;
    do
    {
    	scanf("%d",&j);
        listnode *New = (listnode*)malloc(sizeof(listnode));//为新的结点分派内存
        New->val = j;//储存数据
        /*
        将最后结点的next域指向新结点new
        将新结点的next域设为空
        */
        l->next = New;
        New->next = NULL;
        l = l->next;
        }while(getchar() !='\n');
    }

listnode* MergeTwoLists(listnode*l1, listnode* l2)
{
    //讨论l1 l2为空的情况
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;

    listnode* head, * tail = NULL;
    listnode* L = l1;  //记录下头结点

    //先取一个小的去做第一个结点，方便后续尾插
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
        //取小的尾插新链表
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
