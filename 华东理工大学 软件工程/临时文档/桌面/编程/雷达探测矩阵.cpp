#include <bits/stdc++.h>
int tag[105][105]={0}; //��ǵ��Ƿ񱻸���

int main()
{
	int n,m,r,sum=0;//nΪ����ͼ�߳���mΪ̽����������rΪ̽��뾶 
	scanf("%d%d%d",&n,&m,&r);
	
	for(int i=1;i<=m;i++)
	{
	int x,y;
	scanf("%d%d",&x,&y);//һ������һ�߼��� 
	tag[x][y]=1;      //���Ŀ��� Ҳ����̽������λ�� 

	for (int i=1;i<=n;i++)
	 for (int j=1;j<=n;j++)
	 { double r1=sqrt((x-i)*(x-i)+(y-j)*(y-j));
	  if (r1<=r)
	  tag[i][j]=1 ;    //�������ǲ�����̽������Χ֮�� 
   	 }
    }
    
	for (int i=1;i<=n;i++)
	 for (int j=1;j<=n;j++)
	  if(tag[i][j]=1)
	  sum++;  //���ڷ�Χ�����һ 
	  
	printf("%d",sum);
	return 0;
 } 
