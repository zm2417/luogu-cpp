/**
 * 洛谷cpp算法
 * 
 * @author: zhangMeng
 * @date: 2020-02-29 
 */
#include <iostream>
#include <vector>
// #include <stack>

const int MAXN = 10;
using namespace std;

int n, m, a, b;
vector<int> d[MAXN];

// stack<int> s;
int dfn[MAXN], low[MAXN], num, vis[MAXN];
// int numsucc, succ[MAXN], belong[MAXN];
int cut[MAXN];       // 是否是割点
int si[MAXN];        //
long long ans[MAXN]; // 删点后的答案

void tarjan(int x)
{
    dfn[x] = low[x] = ++num;
    // s.push(x);
    vis[x] = 1;
    int flag = 0, sum = 0; // sum:割点x节点后,分割出来的子连通分量,下面的子树的节点之后
    si[x] = 1;
    for (int i = 0; i < d[x].size(); i++)
    {
        int j = d[x][i];
        if (dfn[j] == 0)
        {
            tarjan(j);
            low[x] = min(low[x], low[j]);
            si[x] += si[j];
            if (low[j] >= dfn[x])
            {
                ans[x] += (long long)si[j] * (n - si[j]);
                sum += si[j];
                flag++;
                if (x != 1 || flag > 1)
                    cut[x] = 1;
            }
        }
        else if (vis[j] != 0)
        {
            low[x] = min(low[x], dfn[j]);
        }
    }
    if (cut[x] == 0)
        ans[x] = 2 * (n - 1);
    else
        ans[x] += (long long)(n - sum - 1) * (sum + 1) + n - 1;
    // if (dfn[x] == low[x])
    // {
    //     int j;
    //     numsucc++;
    //     do
    //     {
    //         j = s.top();
    //         s.pop();
    //         vis[j] = 0;
    //         succ[numsucc]++;
    //         belong[j] = numsucc;
    //     } while (j != x);
    // }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        d[a].push_back(b);
        d[b].push_back(a);
    }
    tarjan(1);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << endl;
    // for (int i = 1; i <= n; i++)
    //     if (dfn[i] == 0)
    //         tarjan(i);
    return 0;
}
