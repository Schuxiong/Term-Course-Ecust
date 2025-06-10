#include<stdio.h>
#define INF 99999999
#define MAXSIZE 999

typedef struct {
	int items[MAXSIZE];
	int front;
	int rear;
}Queue;
/*����ṹ�����Queue;Queue��һ��˳����У��涨ͷָ��front����ָ��ǰ��ͷԪ�ص�ǰһ��λ�ã�
βָ��rearָ��ǰ��βԪ�ص�λ��*/

void initQueue(Queue* q)
{
	q->front = q->rear = 0;
}//�����г�ʼ��������û�з���ֵ

int isEmpty(Queue* q)
{
	if (q->front == q->rear)//ѭ�������£��ж϶ӿյ�����
		return 1;
	else
		return 0;
}//�ж϶����Ƿ�Ϊ�գ���������������������Ԫ��ʱʹ��

void AddQ(Queue* q, int item)
{
	if ((q->rear + 1) % MAXSIZE == q->front)//ѭ�������£��ж϶���������
	{
		printf("������");
		return;//return ����ʲôҲ������������������
	}//return����ǰ����������Ψһ�취
	q->rear = (q->rear + 1) % MAXSIZE;//ѭ�������¶�βָ��+1�Ĳ���
	q->items[q->rear] = item;//���µ�Ԫ����ӵ���β
}

int DeleteQ(Queue* q)
{
	if (q->rear == q->front)//ѭ���������ж϶���Ϊ�յĲ���
	{
		printf("���п�");
		return NULL;
	}
	q->front = (q->front + 1) % MAXSIZE;//���Ӳ���ʱͷָ��+1
	return q->items[q->front];//���ض�ͷ��Ԫ��
}

int main() {

	Queue q;
	Queue tempQ;

	initQueue(&q);
	initQueue(&tempQ);

	int N;

	scanf("%d", &N);//������еĳ���N

	int m;

	for (int i = 0; i < N; i++) {
		scanf("%d", &m);
		AddQ(&q, m);
	}//��������е�N��Ԫ��

	int min;
	int i,j;

	for (i = 0; i < N; i++)
	{
		min = INF;

		for (j = i; j < N; j++)//��ʼһ��ѭ����ɸѡ��ԭ�����е���СԪ�أ�������ȡ�������¶��еĶ�β
		{

			m = DeleteQ(&q);//mΪԭ���еĶ�ͷԪ��
			if (m < min)
			{//ȡ��ͷԪ�أ�����Сֵ�Ƚϣ��������Сֵ����ȡ������Ԫ�طŵ�ԭ���еĶ�β
				if (min != INF) AddQ(&q, min);//�������СֵС���������Ԫ��ȡ����Сֵ����ԭ������Сֵ���
				min = m;
			}
			else
			{
				AddQ(&q, m);
			}
		}//����һ��ѭ���������õ�����СֵΪ�����е���Сֵ
		AddQ(&tempQ, min);//�������Сֵ��ӵ��¶��еĶ�β

	}//����N��ѭ�����¶��е�Ԫ�ذ���������

	printf("%d", DeleteQ(&tempQ));
	while (!isEmpty(&tempQ))
	{
		printf(" %d", DeleteQ(&tempQ));
	}
	printf("\n");
	return 0;
}


