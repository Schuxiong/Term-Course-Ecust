#include<stdio.h>
#include<queue>
using namespace std;
 
void print(queue<int> q)
{
	bool first=true;
	while(!q.empty())
	{
		if(first)
		{
			printf("%d",q.front());
			first=false;
		}
		else
			printf(" %d",q.front());
 
		q.pop();
	}
	printf("\n");
}

 
int min(int x,int y)
{
	if(x<=y)
		return x;
	else
		return y;
}


//�鲢����

void queueMergeSort(queue<int> &q, int size)
{
	queue<int> qTemp;  //���ڸ�������
	int step=1;  //����, 2��ָ��1,2,4,8
	int remain;  //��ǻ��ж���Ԫ��δ���й鲢
	int k1,k2,i;  //k1:q���Ƶ�qTemp�����е�Ԫ��   k2:q�н�Ҫ��qTemp�ϲ���Ԫ�صĸ���
	
	while(step<=size)
	{
		remain=size;  //ÿ�ι鲢ǰ����ʼ����СΪ���д�С
		while(remain>0) // һ�κϲ���ʼ
		{
			k1=min(step,remain);
			//��k1��Ԫ�ط���qTemp��, k1��remain��step�е���Сֵ
			for(i=0;i<k1;i++){	qTemp.push(q.front());		q.pop();   }
 
			remain=remain-k1; //����ʣ��ֵ
			k2=min(remain,step);  //q��Ҫ�ϲ���Ԫ�ظ���
			remain=remain-k2;
 
			//��q��qTemp�����е�ǰk2,k1��Ԫ�أ����кϲ�����
			while(k1>0 && k2>0) {   //����С��Ԫ��ѹ�����β��
				if(q.front()<=qTemp.front())
				{
					
				q.push(q.front());		
				q.pop();		
				k2--;  }
				else
				{	
				q.push(qTemp.front());		
				qTemp.pop();		
				k1--;}
			
			}
			while(k2>0) {//q�л���ʣ��Ԫ��δ�ϲ�(�ϴ��)��ֱ�Ӽ���q����β��
				q.push(q.front());		q.pop();		k2--;
			}
			while(k1>0) {//qTemp�л���ʣ��Ԫ��δ�ϲ�(�ϴ��)��ֱ�Ӽ���q����β��
				q.push(qTemp.front());		qTemp.pop();		k1--;
			}
		}// һ�κϲ�����
		//print(q);
		step=step*2;
	}
	
}
int main()
{
	int N;
	queue<int> q1;
	queue<int> q2;
	scanf("%d",&N);
 
	int temp,i,j;
	for(i=0;i<N;i++)
	{
		scanf("%d",&temp);
		q1.push(temp);
	}
	queueMergeSort(q1,N);
	print(q1);
}
