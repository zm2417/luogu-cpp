#include <iostream>
using namespace std;

struct Edge
{
    int fi, gi, wi;
} edge[500005];

int head[10005], dis[10005], k, n, m, s, maxInf = 2147483647;
bool vis[10005];

void add(int f, int g, int w)
{
    edge[++k].fi = g;
    edge[k].wi = w;
    edge[k].gi = head[f];
    head[f] = k;
}

void dijkstra()
{
    for (int i = 1; i <= n; i++)
    {
        if (i != s)
            dis[i] = maxInf;
    }
    for (int i = head[s]; i; i = edge[i].gi)
    {
        dis[edge[i].fi] = min(dis[edge[i].fi], edge[i].wi);
    }
    int totol = 0;
    while (++totol < n)
    {
        vis[s] = true;
        int minInf = 2147483647;
        // 可以堆优化
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i] && minInf > dis[i])
            {
                minInf = dis[i];
                s = i;
            }
        }
        // dis[s] = minInf;
        for (int i = head[s]; i; i = edge[i].gi)
        {
            int v = edge[i].fi;
            if (!vis[v] && dis[v] > edge[i].wi + dis[s])
            {
                dis[v] = edge[i].wi + dis[s];
            }
        }
    }
}

int main()
{
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++)
    {
        int f, g, w;
        cin >> f >> g >> w;
        add(f, g, w);
    }
    dijkstra();
    for (int i = 1; i <= n; i++)
        cout << dis[i] << ' ';
    return 0;
}