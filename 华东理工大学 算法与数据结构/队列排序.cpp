#include<iostream>
#include<queue>
#include<math.h>
using namespace std;
 
deque<int> que1;
deque<int> que2;
 
void print_q(deque<int> que)
{
	bool first=true;
	while(!que.empty())
	{
		if(!first)
			printf(" %d",que.front());
		else
			printf("%d",que.front());
		first=false;
		que.pop_front();
 
	}
 
}

void merge_sort(int n,int m,deque<int>& que,deque<int>& que2) 
{
	int i=0,j=0;
	while(i<m&&j<n)
	{
		if(que.front()<que2.front())
		{
			que.push_back(que.front());
			que.pop_front();
			i++;
		}
		else
		{
			que.push_back(que2.front());
			que2.pop_front();
			j++;
		}
 
	}
	while(i<m)
	{
		que.push_back(que.front());
		que.pop_front();
		i++;
	}
	while(j<n)
	{
		que.push_back(que2.front());
		que2.pop_front();
		j++;
	}
 
}
 
void que_pop(int num , deque<int>&que_out , deque<int>& que_in)
{
	int i=0;
	for(i=0;i<num;i++)
	{
		que_in.push_front(que_out.back());
		que_out.pop_back();
	}
}
 
void merge_div(int n,int m, deque<int>& que,deque<int>& que2)
{
	int i=0;
	if(n!=1)
		merge_div(n/2,n-n/2,que,que2);
	if(m!=1)
		merge_div(m/2,m-m/2,que,que2);
	if((n==1&&m==1))
	{   
		que2.push_back(que.front());
		que.pop_front();
		merge_sort(n,m,que,que2);
	}
	else//if m n doesn't equal 1 they should be combine with other nums
	{  
		if(n==1)
		{
			 que_pop(m,que,que2);
			 merge_sort(m,n,que,que2);
		}
		else if(m==1)
		{
		   que_pop(n,que,que2);
		   merge_sort(n,m,que,que2);
		}  
		else
		{
		    que_pop(m,que,que2);
			que_pop(n,que,que);
			merge_sort(m,n,que,que2);
		}
	}
}
 
int main()
{
	int n=0,i=0;
	int temp=0;
 
	while(scanf("%d",&n)!=EOF)
	{ 
		
		//	n=100;
 
		//int time_s=time(NULL);
		for(i=0;i<n;i++)
		{
			scanf("%d",&temp);
			//temp=rand();
			que1.push_front(temp);
 
		}
		merge_div(n/2,n-n/2,que1,que2);
		print_q(que1);
		//int time_e=time(NULL);
 
		//printf("\n%d---%d",time_e,time_s);
	}
 
	return 0;
}
