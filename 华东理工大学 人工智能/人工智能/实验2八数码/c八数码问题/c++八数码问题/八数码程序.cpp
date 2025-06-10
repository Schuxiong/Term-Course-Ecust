//************************************
//*����������
//************************************
#include<iostream>
#include<map>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;

struct P{
	int d;	//���g(n)
	int w;	//����λ��h(n)
	int id;	//��¼�ýڵ��id���������ʱ�ҵ��ýڵ�
	string s;	//״̬
	friend bool operator <(const P &a,const P &b){//��f(n)=g(n)+h(n)��С����
		return a.d+a.w>b.d+b.w;  //����
	}
}p;
const int N=3;	//���̴�С
//const string t="123456780";	//Ŀ��״̬
const string t="123804765";
string stack[1000000];		//��¼�����еĽڵ�
string record[1000000];		//����㿪ʼ��¼��·��
int father[10000000];		//��¼�ýڵ�ĸ��ڵ�
int top=0;					//stack��ָ��
priority_queue<P> pq;		//open��
map<string,bool> mp;		//��¼��״̬�Ƿ��Ѿ����ʹ���1���ʹ���0û��

int calw(string s)//�����״̬�Ĳ���λ��h(n)
{
	int re=0;
	for(int i=0;i<9;i++) if(s[i]!=t[i]) re++;
	return re;
}
int solve()	//��������
{
	P cur;
	while(!pq.empty()){
		cur=pq.top(); //open��
		pq.pop();
		if(cur.s==t) return cur.id;	//�ﵽĿ��״̬�����ص�ǰ�ڵ��id
		int x,y;
		int ops=0;
		while(cur.s[ops]!='0') ops++;
		x=ops/3,y=ops%3;  //�ո�����λ��
		int r=cur.id;
		if(x>0){          //�ո�������
			p.s=cur.s;
			swap(p.s[ops],p.s[ops-3]);
			if(!mp[p.s]){
				p.d=cur.d+1,p.w=calw(p.s),p.id=top+1;
				pq.push(p);
				stack[++top]=p.s;
				father[top]=r;
				mp[p.s]=1;
			}
		}
		if(x<2){    //�ո�������
			p.s=cur.s;
			swap(p.s[ops],p.s[ops+3]);
			if(!mp[p.s]){
				p.d=cur.d+1,p.w=calw(p.s),p.id=top+1;
				pq.push(p);
				stack[++top]=p.s;
				father[top]=r;
				mp[p.s]=1;
			}
		}
		if(y>0){    //�ո�������
			p.s=cur.s;
			swap(p.s[ops],p.s[ops-1]);
			if(!mp[p.s]){
				p.d=cur.d+1,p.w=calw(p.s),p.id=top+1;
				pq.push(p);
				stack[++top]=p.s;
				father[top]=r;
				mp[p.s]=1;
			}
		}
		if(y<2){   //�ո�������
			p.s=cur.s;
			swap(p.s[ops],p.s[ops+1]);
			if(!mp[p.s]){
				p.d=cur.d+1,p.w=calw(p.s),p.id=top+1;
				pq.push(p);
				stack[++top]=p.s;
				father[top]=r;
				mp[p.s]=1;
			}
		}
	}
	return -1;	//����ʧ��
}

void print(int x)////��record���������ǰ�����Ľڵ�
{
	int k=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(record[x][k]=='0')
				printf("  ");
			else printf("%c ",record[x][k]);
			k++;
		}
		printf("\n");
	}
	printf("\n");
}
int main()
{
//	freopen("a.txt","r",stdin);
	int tt;	//���Ե�����
	cin>>tt;
	for(int k=1;k<=tt;k++){
		cout<<"Case "<<k<<":\n";
		int i,j;
		char a;
		p.s="";
		for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				cin>>a;  //����0��8����
				p.s+=a;
			}
		}
		p.d=0,p.w=calw(p.s),p.id=0;
		father[0]=-1;
		mp[p.s]=1;
		stack[0]=p.s;
		//pq.push(p);	//��open���м����ʼ״̬�ڵ�
		int id=solve();//������������
		if(id==-1){
			cout<<"�޽⣡\n";
		}else{
			int c=-1;
			while(id>=0){	//��stack�д�Ľڵ㰴������뵽record��
				record[++c]=stack[id];
				id=father[id];
			}
			cout<<"ԭͼ��"<<endl;
			print(c); //�����ʼ�ڵ�
			cout<<"�ƶ�����: \n\n";
			for(i=c-1;i>=0;i--){
				cout<<"Step "<<c-i<<":\n";//�����ǰ��������
				print(i);//�����ǰ�����Ľڵ�
			}
			cout<<"�ƶ�������\n";
		}
		mp.clear();
		while(!pq.empty()) pq.pop();
		top=0;
		cout<<endl;
	}
	system("pause\n");
	return 0;
}
