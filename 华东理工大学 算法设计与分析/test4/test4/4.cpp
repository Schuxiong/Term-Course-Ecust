#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <list>
#include <map>

#define P(x) x > 0 ? x : 0
#define INF 0x3f3f3f3f

using namespace std;
typedef long long ll;
const int maxn = 1e4 + 5;
const int maxm = 1e4 + 5;

int n, m;
double dp[maxn];
double ans;
struct node
{
    int a;
    double b;
    node(int aa = 0, double bb = 0) : a(aa), b(bb) {}
    friend bool operator<(node n1, node n2)
    {
        return n1.a < n2.a;
    }
} item[maxm];

void init()
{
    for (int i = 0; i < maxn; i++)
    {
        dp[i] = 1;
    }
    ans = 1;
}

int main()
{
    ifstream infile("input.txt");
    ofstream outfile("output.txt");

    while (true)
    {
        infile >> n >> m;

        if (n == 0 && m == 0)
        {
            break;
        }

        init();

        for (int i = 1; i <= m; i++)
        {
            infile >> item[i].a >> item[i].b;
            item[i].b = 1 - item[i].b; //我们让item[i].b存不会被录取的概率
        }

        if (n == 0)
        {
            for (int i = 1; i <= m; i++)
            {
                if (item[i].a == 0)
                    ans *= item[i].b;
            }
            outfile << fixed;
            outfile.precision(1);
            outfile << (1 - ans) * 100 << "%" << endl;
            continue;
        }

        for (int i = 1; i <= m; i++)
        {
            for (int j = n; j >= item[i].a; j--)
            {
                dp[j] = min(dp[j - item[i].a] * item[i].b, dp[j]);
            }
        }

        for (int i = 1; i <= n; i++)
            ans = min(ans, dp[i]);

        outfile << fixed;
        outfile.precision(1);
        outfile << (1 - ans) * 100 << "%" << endl;
    }

    infile.close();
    outfile.close();

    return 0;
}
