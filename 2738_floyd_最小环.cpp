#include <iostream>
using namespace std;

int n;
int s, ls, n1s, n2s;
int l[110];
int connect[110][110];
int nid[220];
int graph[220][220];
int dist[220][220];
int ans = 1 << 20;

// 并查集
int father[220];
void init()
{
    for (int i = 0; i < 220; i++)
        father[i] = i;
}
int findFather(int x)
{
    while (father[x] != x)
    {
        father[x] = father[father[x]];
        x = father[x];
    }
    return father[x];
}
void unionSet(int x, int y)
{
    int xx = findFather(x), yy = findFather(y);
    father[xx] = yy;
}

void initDist()
{
    for (int i = 0; i < 220; i++)
        for (int j = 0; j < 220; j++)
            dist[i][j] = graph[i][j] = 252645135;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s >> ls >> n1s >> n2s;
        l[s] = ls;
        int k;
        for (int j = 0; j < n1s; j++)
        {
            cin >> k;
            connect[s][k] = 2 * s - 1;
        }
        for (int j = 0; j < n2s; j++)
        {
            cin >> k;
            connect[s][k] = 2 * s;
        }
    }

    // 合并 connect[i][j] 与 connect[j][i]
    init();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (connect[i][j])
                unionSet(connect[i][j], connect[j][i]);

    // 离散化 同一个并查集
    int m = 0;
    // for (int i = 1; i <= n; i++)
    //     for (int j = 1; j <= n; j++)
    //     {
    //         int fa = findFather(connect[i][j]);
    //         if (nid[fa] == 0)
    //             nid[fa] = ++m;
    //         nid[connect[i][j]] = nid[fa];
    //     }
    for (int i = 1; i <= n * 2; i++)
    {
        int fa = findFather(i);
        nid[i] = nid[fa] ? nid[fa] : nid[fa] = ++m;
    }

    initDist();

    // 建图
    for (int i = 1; i <= n; i++)
    {
        int u = nid[2 * i - 1], v = nid[2 * i];
        graph[u][v] = graph[v][u] = dist[u][v] = dist[v][u] = l[i];
    }

    // for (int i = 1; i <= m; i++)
    // {
    //     for (int j = 1; j <= m; j++)
    //         cout << dist[i][j] << ' ';
    //     cout << endl;
    // }

    for (int i = 1; i <= m; i++)
        dist[i][i] = 0;
    // floyd 求最小环
    for (int k = 1; k <= m; k++)
    {
        for (int i = 1; i < k; i++)
            for (int j = i + 1; j < k; j++)
                ans = min(ans, graph[i][k] + graph[k][j] + dist[i][j]);
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= m; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    }
    cout << ans << endl;
    return 0;
}