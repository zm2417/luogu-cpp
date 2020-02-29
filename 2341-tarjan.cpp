/**
 * 洛谷cpp算法
 * 受欢迎的奶牛只有可能是图中唯一的出度为零的强连通分量中的所有奶牛，
 * 所以若出现两个以上出度为0的强连通分量则不存在明星奶牛，
 * 因为那几个出度为零的分量的爱慕无法传递出去。
 * 那唯一的分量能受到其他分量的爱慕同时在分量内相互传递，所以该分量中的所有奶牛都是明星。
 * 
 * @author: zhangMeng
 * @date: 2020-02-29 
 */
#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;

const int MAXN = 10005;
int n, m, a, b;
vector<int> d[MAXN];
int out[MAXN];

stack<int> s;
int dfn[MAXN], low[MAXN], num, vis[MAXN];
int sumscc, scc[MAXN], belong[MAXN];

void tarjan(int x)
{
    dfn[x] = low[x] = ++num;
    vis[x] = 1;
    s.push(x);
    for (int i = 0; i < d[x].size(); i++)
    {
        int j = d[x][i];
        if (dfn[j] == 0)
        {
            tarjan(j);
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
    }
}

// int like[MAXN];
// bool check(int x)
// {
//     memset(vis, 0, sizeof(vis));
//     for (int i = 1; i <= n; i++)
//     {
//     }
// }

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        d[a].push_back(b);
    }
    // for (int i = 1; i <= n; i++)
    //     d[i].push_back(i);
    for (int i = 1; i <= n; i++)
        if (dfn[i] == 0)
            tarjan(i);
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < d[i].size(); j++)
            if (belong[i] != belong[d[i][j]])
                out[belong[i]]++;
    int ans = 0, u = 0;
    for (int i = 1; i <= sumscc; i++)
        if (out[i] == 0)
            ans = scc[i], u++;
    if (u == 1)
        cout << ans << endl;
    else
        cout << 0 << endl;
    return 0;
}
