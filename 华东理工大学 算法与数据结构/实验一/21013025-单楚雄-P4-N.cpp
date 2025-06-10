#include<stdio.h>
#define INF 99999999
#define MAXSIZE 999

typedef struct {
	int items[MAXSIZE];
	int front;
	int rear;
}Queue;
/*定义结构体队列Queue;Queue是一个顺序队列，规定头指针front总是指向当前队头元素的前一个位置，
尾指针rear指向当前队尾元素的位置*/

void initQueue(Queue* q)
{
	q->front = q->rear = 0;
}//将队列初始化，函数没有返回值

int isEmpty(Queue* q)
{
	if (q->front == q->rear)//循环意义下，判断队空的条件
		return 1;
	else
		return 0;
}//判断队列是否为空，这个函数将会在输出队列元素时使用

void AddQ(Queue* q, int item)
{
	if ((q->rear + 1) % MAXSIZE == q->front)//循环意义下，判断队满的条件
	{
		printf("队列满");
		return;//return 后面什么也不跟，用来结束函数
	}//return是提前结束函数的唯一办法
	q->rear = (q->rear + 1) % MAXSIZE;//循环意义下队尾指针+1的操作
	q->items[q->rear] = item;//将新的元素添加到队尾
}

int DeleteQ(Queue* q)
{
	if (q->rear == q->front)//循环意义下判断队列为空的操作
	{
		printf("队列空");
		return NULL;
	}
	q->front = (q->front + 1) % MAXSIZE;//出队操作时头指针+1
	return q->items[q->front];//返回队头的元素
}

int main() {

	Queue q;
	Queue tempQ;

	initQueue(&q);
	initQueue(&tempQ);

	int N;

	scanf("%d", &N);//输入队列的长度N

	int m;

	for (int i = 0; i < N; i++) {
		scanf("%d", &m);
		AddQ(&q, m);
	}//输入队列中的N个元素

	int min;
	int i,j;

	for (i = 0; i < N; i++)
	{
		min = INF;

		for (j = i; j < N; j++)//开始一轮循环，筛选出原队列中的最小元素，并将其取出放入新队列的队尾
		{

			m = DeleteQ(&q);//m为原队列的队头元素
			if (m < min)
			{//取队头元素，与最小值比较，如果比最小值大，则将取出来的元素放到原队列的队尾
				if (min != INF) AddQ(&q, min);//如果比最小值小，则用这个元素取代最小值，将原来的最小值入队
				min = m;
			}
			else
			{
				AddQ(&q, m);
			}
		}//经过一轮循环下来，得到的最小值为队列中的最小值
		AddQ(&tempQ, min);//将这个最小值添加到新队列的队尾

	}//经过N轮循环，新队列的元素按增序排列

	printf("%d", DeleteQ(&tempQ));
	while (!isEmpty(&tempQ))
	{
		printf(" %d", DeleteQ(&tempQ));
	}
	printf("\n");
	return 0;
}


