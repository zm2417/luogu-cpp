/**
 * 洛谷cpp算法
 * 
 * @author: zhangMeng
 * @date: 2020-03-02 
 */
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int MAXN = 105;
int n;
vector<int> d[MAXN]; // 原图
vector<int> g[MAXN]; // 缩点后的图
int into[MAXN], outDu[MAXN];
int a, b; // a:入度为0的节点 b:出度为0的节点

stack<int> s;
int dfn[MAXN], low[MAXN], vis[MAXN], num;
int numscc, scc[MAXN], belong[MAXN];

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
        else if (vis[j] != 0)
        {
            low[x] = min(low[x], dfn[j]);
        }
    }
    if (dfn[x] == low[x])
    {
        int j;
        numscc++;
        do
        {
            j = s.top();
            s.pop();
            scc[numscc]++;
            belong[j] = numscc;
            vis[j] = 0;
        } while (j != x);
    }
}

void createG()
{
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < d[i].size(); j++)
            if (belong[i] != belong[d[i][j]])
                g[belong[i]].push_back(belong[d[i][j]]);
}

void creatDu()
{
    // for (int i = 1; i <= numscc; i++)
    // {
    //     for (int j = 0; j < g[i].size(); j++)
    //     {
    //         int k = g[i][j];
    //         into[k]++;
    //         outDu[i]++;
    //     }
    // }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < d[i].size(); j++)
        {
            if (belong[i] != belong[d[i][j]])
            {
                // int k = d[i][j];
                into[belong[d[i][j]]]++;
                outDu[belong[i]]++;
            }
        }
    }
}

void ans()
{
    if (numscc == 1)
    {
        cout << 1 << endl
             << 0 << endl;
        return;
    }
    for (int i = 1; i <= numscc; i++)
        if (into[i] == 0)
            a++;
    for (int i = 1; i <= numscc; i++)
        if (outDu[i] == 0)
            b++;
    cout << a << endl
         << max(a, b) << endl;
}

void ans1()
{
    // int ans = 0;
    for (int i = 1; i <= numscc; i++)
        if (into[i] == 0)
            a++;
    cout << a << endl;
}

void ans2()
{
    if (numscc == 1)
    {
        cout << 0 << endl;
        return;
    }

    for (int i = 1; i <= numscc; i++)
        if (outDu[i] == 0)
            b++;
    cout << max(a, b) << endl;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int j;
        cin >> j;
        while (j != 0)
        {
            d[i].push_back(j);
            cin >> j;
        }
    }
    for (int i = 1; i <= n; i++)
        if (dfn[i] == 0)
            tarjan(i);
    // createG();
    creatDu();
    // ans1();
    // ans2();
    ans();
    return 0;
}
