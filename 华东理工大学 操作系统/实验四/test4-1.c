#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define TRUE 1
#define FALSE 0
#define INVALID -1

#define total_instruction 320 /* 指令流长 */
#define total_vp 32           /* 虚页长 */
#define clear_period 50       /* 清零周期 */

typedef struct { /* 页面结构 */
    int pn, pfn, counter, time;
} pl_type;

pl_type pl[total_vp]; /* 页面结构数组 */

struct pfc_struct {    /* 页面控制结构 */
    int pn, pfn;
    struct pfc_struct *next;
};

struct pfc_struct pfc[total_vp], *freepf_head, *busypf_head, *busypf_tail;
int diseffect, a[total_instruction];
int page[total_instruction], offset[total_instruction];

void initialize();
void FIFO();
void LRU();
void OPT();
void LFU();
void CLOCK();

int main()
{
    int S, i;
    srand(10 * getpid());
    /* 由于每次运行时进程号不同，故可用来作为初始化随机数队列的“种子” */
    S = (int)(319.0 * rand() / RAND_MAX) + 1;
    for (i = 0; i < total_instruction; i += 4) /* 产生指令队列 */
    {
        a[i] = S;             /* 任选一指令访问点 */
        a[i + 1] = a[i] + 1;   /* 顺序执行下一条指令 */
        a[i + 2] = (int)(1.0 * a[i] * rand() / RAND_MAX); /* 执行前地址指令m' */
        a[i + 3] = a[i + 2] + 1;                           /* 执行后地址指令 */
        S = (int)(1.0 * rand() * (318 - a[i + 2]) / RAND_MAX) + a[i + 2] + 2;
    }

    for (i = 0; i < total_instruction; i++) /* 将指令序列变换成页地址流 */
    {
        page[i] = a[i] / 10;
        offset[i] = a[i] % 10;
    }

    for (i = 4; i <= 32; i++) /* 用户内存工作区从4个页面到32个页面 */
    {
        printf("%2d page frames\t", i);
        FIFO(i);
        LRU(i);
        OPT(i);
        LFU(i);
        CLOCK(i);
    }

    return 0;
}

void initialize(int total_pf) /* 初始化相关数据结构 */
{
    int i;
    diseffect = 0;
    for (i = 0; i < total_vp; i++)
    {
        pl[i].pn = i;
        pl[i].pfn = INVALID; /* 置页面控制结构中的页号，页面为空 */
        pl[i].counter = 0;
        pl[i].time = -1; /* 置页面控制结构中的访问次数，时间为-1 */
    }

    for (i = 1; i < total_pf; i++)
    {
        pfc[i - 1].next = &pfc[i];
        pfc[i - 1].pfn = i - 1;
    } /* 建立pfc[i-1]和pfc[i]之间的链接 */
    pfc[total_pf - 1].next = NULL;
    pfc[total_pf - 1].pfn = total_pf - 1;
    freepf_head = &pfc[0];
    /* 空页面队列的头指针为pfc[0] */
}

void FIFO(int total_pf)
{
    int i;
    struct pfc_struct *p;
    initialize(total_pf); /* 初始化相关页面控制用数据结构 */
    busypf_head = busypf_tail = NULL; /* 忙页面队列，队列尾链接 */
    for (i = 0; i < total_instruction; i++)
    {
        if (pl[page[i]].pfn == INVALID) /* 页面失效 */
        {
            diseffect += 1; /* 失效次数 */
            if (freepf_head == NULL) /* 无空闲页面 */
            {
                p = busypf_head->next;
                pl[busypf_head->pn].pfn = INVALID;
                freepf_head = busypf_head; /* 释放忙页面队列中的第一个页面 */
                freepf_head->next = NULL;
                busypf_head = p;
            }
            p = freepf_head->next; /* 按FIFO方式调新页面入内存页面 */
            freepf_head->next = NULL;
            freepf_head->pn = page[i];
            pl[page[i]].pfn = freepf_head->pfn;
            if (busypf_tail == NULL)
                busypf_head = busypf_tail = freepf_head;
            else
            {
                busypf_tail->next = freepf_head;
                busypf_tail = freepf_head;
            }
            freepf_head = p;
        }
    }
    printf("FIFO:%6.4f ", 1 - (float)diseffect / 320);
}

void LRU(int total_pf)
{
    int i;
    struct pfc_struct *p, *pre, *ptr;
    initialize(total_pf); /* 初始化相关页面控制用数据结构 */
    busypf_head = busypf_tail = NULL; /* 忙页面队列，队列尾链接 */
    for (i = 0; i < total_instruction; i++)
    {
        if (pl[page[i]].pfn == INVALID) /* 页面失效 */
        {
            diseffect += 1; /* 失效次数 */
            if (freepf_head == NULL) /* 无空闲页面 */
            {
                p = busypf_head->next;
                pl[busypf_head->pn].pfn = INVALID;
                freepf_head = busypf_head; /* 释放忙页面队列中的第一个页面 */
                freepf_head->next = NULL;
                busypf_head = p;
            }
            p = freepf_head->next; /* 按LRU方式调新页面入内存页面 */
            freepf_head->next = NULL;
            freepf_head->pn = page[i];
            pl[page[i]].pfn = freepf_head->pfn;
            pl[page[i]].counter = i; /* 更新访问次数 */
            if (busypf_tail == NULL)
                busypf_head = busypf_tail = freepf_head;
            else
            {
                busypf_tail->next = freepf_head;
                busypf_tail = freepf_head;
            }
            freepf_head = p;
        }
        else
        {
            pl[page[i]].counter = i; /* 更新访问次数 */
        }
    }
    printf("LRU:%6.4f ", 1 - (float)diseffect / 320);
}

void OPT(int total_pf)
{
    int i, j, max_future_distance, index_to_replace;
    struct pfc_struct *p;
    initialize(total_pf); /* 初始化相关页面控制用数据结构 */
    busypf_head = busypf_tail = NULL; /* 忙页面队列，队列尾链接 */

    for (i = 0; i < total_instruction; i++)
    {
        if (pl[page[i]].pfn == INVALID) /* 页面失效 */
        {
            diseffect += 1; /* 失效次数 */

            if (freepf_head == NULL) /* 无空闲页面 */
            {
                p = busypf_head->next;
                pl[busypf_head->pn].pfn = INVALID;
                freepf_head = busypf_head; /* 释放忙页面队列中的第一个页面 */
                freepf_head->next = NULL;
                busypf_head = p;
            }

            p = freepf_head->next; /* 按 OPT 方式调新页面入内存页面 */
            freepf_head->next = NULL;
            freepf_head->pn = page[i];
            pl[page[i]].pfn = freepf_head->pfn;

            if (busypf_tail == NULL)
                busypf_head = busypf_tail = freepf_head;
            else
            {
                busypf_tail->next = freepf_head;
                busypf_tail = freepf_head;
            }

            freepf_head = p;
        }
        else
        {
            /* 查找未来最长时间不访问的页面 */
            max_future_distance = -1;
            index_to_replace = -1;

            for (j = 0; j < total_pf; j++)
            {
                if (pl[j].pfn != INVALID)
                {
                    int future_distance = 0;
                    for (int k = i + 1; k < total_instruction; k++)
                    {
                        if (page[k] == pl[j].pn)
                        {
                            break;
                        }
                        future_distance++;
                    }

                    if (future_distance > max_future_distance)
                    {
                        max_future_distance = future_distance;
                        index_to_replace = j;
                    }
                }
            }

            pl[index_to_replace].pfn = INVALID;
        }
    }

    printf("OPT:%6.4f ", 1 - (float)diseffect / 320);
}

void LFU(int total_pf)
{
    int i, j, min, index;
    struct pfc_struct *p, *pre, *ptr;
    initialize(total_pf); /*初始化相关页面控制用数据结构*/
    busypf_head = busypf_tail = NULL; /*忙页面队列，队列尾链接*/
    for (i = 0; i < total_instruction; i++)
    {
        if (pl[page[i]].pfn == INVALID) /*页面失效*/
        {
            diseffect += 1; /*失效次数*/
            if (freepf_head == NULL) /*无空闲页面*/
            {
                p = busypf_head->next;
                pl[busypf_head->pn].pfn = INVALID;
                freepf_head = busypf_head; /*释放忙页面队列中的第一个页面*/
                freepf_head->next = NULL;
                busypf_head = p;
            }
            p = freepf_head->next; /*按LFU方式调新页面入内存页面*/
            freepf_head->next = NULL;
            freepf_head->pn = page[i];
            pl[page[i]].pfn = freepf_head->pfn;
            pl[page[i]].counter = 1; /*初始化访问次数为1*/
            if (busypf_tail == NULL)
                busypf_head = busypf_tail = freepf_head;
            else
            {
                busypf_tail->next = freepf_head;
                busypf_tail = freepf_head;
            }
            freepf_head = p;
        }
        else
        {
            pl[page[i]].counter += 1; /*访问次数增加*/
        }
    }
    printf("LFU:%6.4f ", 1 - (float)diseffect / 320);
}

void CLOCK(int total_pf)
{
    int i;
    struct pfc_struct *p, *pre, *ptr;
    initialize(total_pf); /*初始化相关页面控制用数据结构*/
    busypf_head = busypf_tail = NULL; /*忙页面队列，队列尾链接*/
    ptr = freepf_head;
    for (i = 0; i < total_instruction; i++)
    {
        if (pl[page[i]].pfn == INVALID) /*页面失效*/
        {
            diseffect += 1; /*失效次数*/
            if (freepf_head == NULL) /*无空闲页面*/
            {
                p = busypf_head->next;
                pl[busypf_head->pn].pfn = INVALID;
                freepf_head = busypf_head; /*释放忙页面队列中的第一个页面*/
                freepf_head->next = NULL;
                busypf_head = p;
            }
            p = freepf_head->next; /*按CLOCK方式调新页面入内存页面*/
            freepf_head->next = NULL;
            freepf_head->pn = page[i];
            pl[page[i]].pfn = freepf_head->pfn;
            pl[page[i]].counter = 1; /*初始化访问次数为1*/
            if (busypf_tail == NULL)
                busypf_head = busypf_tail = freepf_head;
            else
            {
                busypf_tail->next = freepf_head;
                busypf_tail = freepf_head;
            }
            freepf_head = p;
        }
        else
        {
            pl[page[i]].counter += 1; /*访问次数增加*/
        }
        ptr = freepf_head;
    }
    printf("CLOCK:%6.4f\n", 1 - (float)diseffect / 320);
}
 
