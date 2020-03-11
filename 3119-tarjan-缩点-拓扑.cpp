/**
 * 洛谷cpp算法
 * 
 * @author: zhangMeng
 * @date: 2020-03-03 
 */
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>

using namespace std;

const int MAXN = 100001;
int n, m;
vector<int> d[MAXN];
int ans;

stack<int> s;
int dfn[MAXN], low[MAXN], num, vis[MAXN]; // tarjan
int numscc, scc[MAXN], belong[MAXN];      // 缩点

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
            low[x] = min(low[x], dfn[j]);
    }
    if (dfn[x] == low[x])
    {
        int j;
        numscc++;
        do
        {
            j = s.top();
            s.pop();
            vis[j] = 0;
            scc[numscc]++;
            belong[j] = numscc;
        } while (j != x);
    }
}

vector<int> dag[MAXN]; // DAG
int into[MAXN];        // 入度
queue<int> q;          // 拓扑入度=0节点队列
int dis[MAXN][2];      // 离1的距离
int to[MAXN][2];       // 能到达1

void dfs(int x, int num1)
{
    vis[x] = 1;
    to[x][num1] = 1;
    for (int i = 0; i < dag[x].size(); i++)
    {
        into[dag[x][i]]++;
        if (vis[dag[x][i]] == 0)
            dfs(dag[x][i], num1);
    }
}

void topology(int num1)
{
    memset(vis, 0, sizeof(vis));
    q.push(belong[1]);
    dfs(belong[1], num1);
    dis[belong[1]][num1] = 0;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = 0; i < dag[x].size(); i++)
        {
            int j = dag[x][i];
            dis[j][num1] = max(dis[j][num1], dis[x][num1] + scc[j]);
            into[j]--;
            if (into[j] == 0)
                q.push(j);
        }
    }
}

void init()
{
    for (int i = 0; i <= n; i++)
    {
        vis[i] = 0;
        into[i] = 0;
        dag[i].clear();
    }
}

void DAG()
{
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < d[i].size(); j++)
            if (belong[i] != belong[d[i][j]])
                dag[belong[i]].push_back(belong[d[i][j]]);
    topology(0);
    init();
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < d[i].size(); j++)
            if (belong[i] != belong[d[i][j]])
                dag[belong[d[i][j]]].push_back(belong[i]);
    topology(1);
}

int main()
{
    cin >> n >> m;
    int x, y;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        d[x].push_back(y);
    }
    for (int i = 1; i <= n; i++)
        if (dfn[i] == 0)
            tarjan(i);
    DAG();
    // 枚举每一条反边,更新最大值
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < d[i].size(); j++)
        {
            x = belong[i], y = belong[d[i][j]];
            // cout << x << ":" << dis[x][1] << " " << y << ":" << dis[y][0] << endl;
            if (x == y || to[x][1] == 0 || to[y][0] == 0)
                continue;
            ans = max(ans, dis[x][1] + dis[y][0]);
        }
    }
    cout << ans + scc[belong[1]] << endl;
    return 0;
}
