#include<iostream>
using namespace std;
int a[100001],b[100001],c[100001];
int main()
{
	int N,M,t;
	cin>>N>>M;
	for(int i=1;i<N;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=N;i++)
	{
		cin>>b[i];
	}
	for(int i=1;i<=N;i++)
	{
		cin>>c[i];
	}
	for(int i=1;i<=N;i++)
	{
		if(i==1)
		{
			M=M;
		}
		else
		{
			M=M+a[i-1];
		}
		if(c[i]<M%(b[i]+c[i]))
		{
			M=M+(b[i]+c[i]-M%(b[i]+c[i]));
		}
		cout<<M<<endl;
	}
	return 0;
}




