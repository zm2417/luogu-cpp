/**
 * 洛谷cpp算法
 * 
 * @author: zhangMeng
 * @date: 2020-02-29 
 */
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int MAXN = 5010;
int n, m, a, b, t;
vector<int> d[MAXN];

stack<int> s;
int dfn[MAXN], low[MAXN], num, vis[MAXN];
int sumscc, scc[MAXN], belong[MAXN], maxSum;

void tarjin(int x)
{
    dfn[x] = low[x] = ++num;
    s.push(x);
    vis[x] = 1;
    for (int i = 0; i < d[x].size(); i++)
    {
        int j = d[x][i];
        if (dfn[j] == 0)
        {
            tarjin(j);
            low[x] = min(low[x], low[j]);
        }
        else if (vis[j] == 1)
        {
            low[x] = min(low[x], dfn[j]);
        }
    }
    if (dfn[x] == low[x])
    {
        int j;
        sumscc++;
        do
        {
            j = s.top();
            s.pop();
            scc[sumscc]++;
            belong[j] = sumscc;
            vis[j] = 0;
        } while (j != x);
        maxSum = max(maxSum, scc[sumscc]);
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> t;
        d[a].push_back(b);
        if (t == 2)
            d[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
    {
        if (belong[i] == 0)
            tarjin(i);
    }
    cout << maxSum << endl;
    for (int i = 1; i <= n; i++)
    {
        if (scc[belong[i]] == maxSum)
        {
            cout << i << ' ';
            for (int j = i + 1; j <= n; j++)
            {
                if (belong[i] == belong[j])
                    cout << j << ' ';
            }
            cout << endl;
            return 0;
        }
    }
    return 0;
}
