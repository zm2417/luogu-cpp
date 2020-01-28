#include <cstdio>
#include <iostream>
#include <cstring>
#define MAXN 210
using namespace std;
int n, m, l[MAXN], g[MAXN][MAXN], dist[MAXN][MAXN];
int connect[MAXN][MAXN]; //两条边的交点
struct union_find_set
{ //超级简洁的并查集
    int n, fa[MAXN];
    void init(int N)
    {
        n = N;
        for (int i = 1; i <= n; i++)
            fa[i] = i;
    }
    int getFather(int u)
    {
        while (u = fa[u] = fa[fa[u]], u != fa[u])
            ;
        return u;
    }
    bool set_union(int u, int v)
    {
        return (u = getFather(u)) == (v = getFather(v)) ? false : fa[v] = u;
    }
} ufs;
inline int min(int a, int b)
{
    return a < b ? a : b;
}
int main()
{
    scanf("%d", &m);
    //一开始默认有2m个点，后面进行合并
    for (int i = 0; i < m; i++)
    {
        int s, L, n1, n2, x; //标号，长度
        scanf("%d%d%d%d", &s, &L, &n1, &n2);
        l[s] = L;
        for (int i = 0; i < n1; i++)
        {
            scanf("%d", &x);
            connect[s][x] = s * 2 - 1;
        }
        for (int i = 0; i < n2; i++)
        {
            scanf("%d", &x);
            connect[s][x] = s * 2;
        }
    }
    //合并
    int nn = m * 2, nid[MAXN] = {};
    ufs.init(m * 2);
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (connect[i][j])
                ufs.set_union(connect[i][j], connect[j][i]);
        }
    }
    //离散化  加边
    for (int i = 1; i <= nn; i++)
    {
        int fa = ufs.getFather(i);
        nid[i] = nid[fa] ? nid[fa] : nid[fa] = ++n;
    }
    //建图
    memset(dist, 0x0f, sizeof dist);
    memset(g, 0x0f, sizeof g);
    for (int i = 1; i <= m; i++)
    {
        int u = nid[i * 2 - 1], v = nid[i * 2];
        g[u][v] = g[v][u] = dist[u][v] = dist[v][u] = l[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << g[i][j] << ' ';
        }
        cout << endl;
    }
    //求解
    int ans = 1 << 20;
    for (int i = 1; i <= n; i++)
        dist[i][i] = 0;
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i < k; i++)
        {
            for (int j = i + 1; j < k; j++)
            {
                ans = min(ans, dist[i][j] + g[j][k] + g[k][i]);
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}