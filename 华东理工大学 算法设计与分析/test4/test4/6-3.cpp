#include <queue>
#include <fstream>
#include <iostream>
using namespace std;

const int MAX = 1000;
int G[MAX][MAX];//�洢����Ϣ
int bestx[MAX];//����ֵ�ĸ
int w[MAX];//�����Ȩ
int n, e; //������������
ifstream in("input.txt");
ofstream out("output.txt");

//�����
class Node
{
public:
    int dep;  //��ǰ��
    int cut;  //�������
    int e;    //ʣ��ߵ�����
    int* x;   //������

    Node(int d, int c, int ee)
    {
        x = new int[n + 1];
        dep = d;
        cut = c;
        e = ee;
    }

    //���������ȳ�����
    bool operator < (const Node& node) const
    {
        return cut < node.cut;
    }
};

//�洢������Ľ������ȶ���
priority_queue<Node> q;

//��ӽ��
void addNode(Node enode, bool isLeft)
{
    Node now(enode.dep + 1, enode.cut, enode.e);
    copy(enode.x, enode.x + n + 1, now.x);
    //������
    if (isLeft)
    {
        now.x[now.dep] = 1;//����ǸԪ��
        for (int j = 1; j <= n; j++)//ͳ�Ƹ�ߵ�����
            if (G[now.dep][j])
                if (now.x[j] == 0) //�����ǰ�����ڸ�У����ߵ���һ�����㲻�ڸ
                {
                    now.cut++;  //��ߵ���������
                    now.e--;    //ʣ��ߵ���������
                }
                else
                    now.cut--;//��������������
    }
    else//�ҽڵ�
    {
        now.x[now.dep] = 0;//��ǲ��ǸԪ��
        now.e--;//ʣ��ߵ���������
    }
    q.push(now);//�������ȶ���
}

int search()
{
    //��ʼ��
    Node enode(0, 0, e);
    for (int j = 1; j <= n; j++)
        enode.x[j] = 0;
    int best = 0;
    //��֧�޽����
    while (true)
    {
        if (enode.dep > n)//����Ҷ�ӽڵ㣬����ȵ�ǰ���Ž���ţ�����
        {
            if (enode.cut > best)
            {
                best = enode.cut;
                copy(enode.x, enode.x + n + 1, bestx);
                break;
            }
        }
        else//û�е���Ҷ�ӽڵ�
        {
            addNode(enode, true);//�������ӽ��
            if (enode.cut + enode.e > best)//����Լ���������������ӽ��
                addNode(enode, false);
        }
        if (q.empty())
            break;
        else//ȡ������Ԫ��
        {
            enode = q.top();
            q.pop();
        }
    }
    return best;
}

int main()
{
    int a, b, i;
    in >> n >> e;
    memset(G, 0, sizeof(G));
    for (i = 1; i <= e; i++)
    {
        in >> a >> b;
        G[a][b] = G[b][a] = 1;
    }
    out << search() << '\n';
    for (i = 1; i <= n; i++) {
        out << bestx[i];
        if (i != n) out << " ";
    }
    out << '\n';
    in.close();
    out.close();
    return 0;
}