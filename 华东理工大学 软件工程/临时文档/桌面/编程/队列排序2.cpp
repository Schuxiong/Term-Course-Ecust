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


//归并排序

void queueMergeSort(queue<int> &q, int size)
{
	queue<int> qTemp;  //用于辅助排序
	int step=1;  //步幅, 2的指数1,2,4,8
	int remain;  //标记还有多少元素未进行归并
	int k1,k2,i;  //k1:q复制到qTemp队列中的元素   k2:q中将要和qTemp合并的元素的个数
	
	while(step<=size)
	{
		remain=size;  //每次归并前，初始化大小为队列大小
		while(remain>0) // 一次合并开始
		{
			k1=min(step,remain);
			//将k1个元素放入qTemp中, k1是remain和step中的最小值
			for(i=0;i<k1;i++){	qTemp.push(q.front());		q.pop();   }
 
			remain=remain-k1; //更新剩余值
			k2=min(remain,step);  //q中要合并的元素个数
			remain=remain-k2;
 
			//对q和qTemp队列中的前k2,k1个元素，进行合并排序
			while(k1>0 && k2>0) {   //将较小的元素压入队列尾部
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
			while(k2>0) {//q中还有剩余元素未合并(较大的)，直接加入q队列尾部
				q.push(q.front());		q.pop();		k2--;
			}
			while(k1>0) {//qTemp中还有剩余元素未合并(较大的)，直接加入q队列尾部
				q.push(qTemp.front());		qTemp.pop();		k1--;
			}
		}// 一次合并结束
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
