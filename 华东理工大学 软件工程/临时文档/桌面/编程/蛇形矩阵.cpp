
#include<stdio.h>
	int main()
	{
	int n,m; //n��n�е����η��� 
	scanf("%d",&n); 
	m=n;
	int dx[]={-1,0,1,0};	
	int dy[]={0,1,0,-1};  //dx��dy�������ڵ�������
	int g[110][110] = {0}; //��ʼ������Ԫ��ȫΪ0   
	int x=0,y=0,d=1;    
	
	for(int i=1;i<=m*n;i++)
	{
	
		g[x][y]=i; 
		int a=x+dx[d]; //��ʼʱ�������ƣ��Դ�d=1��ʼ �� 
		int b=y+dy[d];  //a��b��¼Ҫ�ƶ�����λ��
		if(a<0||a>=m||b<0||b>=n||g[a][b]) //�߽紦��������������������е�һ�֣���Խ�磬��Ҫ�ı䷽��
		{
			d=(d+1)%4; //˳ʱ��ı䷽�����
			a=x+dx[d]; 
			b=y+dy[d];
		}
		x=a;
		y=b;
	}
	
	for(int i=0;i<m;i++)  //������ξ���
	{  for(int j=0;j<n;j++)
			printf("%3d",g[i][j]);
			printf("\n");
	}
}

