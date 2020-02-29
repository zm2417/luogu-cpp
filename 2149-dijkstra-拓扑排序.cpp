/**
 * 洛谷cpp算法
 * 
 * @author: zhangMeng
 * @date: 2020-02-28 
 */
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int MAXN = 1510;
int n, m, x1, x2, y1, y2, u, v, w;

struct Node
{
    int y, w;
    friend bool operator<(Node n1, Node n2)
    {
        return n1.w > n2.w;
    }
};
vector<Node> d[MAXN];

void addNode(int u1, int v1, int w1)
{
    Node node;
    node.y = v1;
    node.w = w1;
    d[u1].push_back(node);
}

int vis[MAXN], dis[5][MAXN];
priority_queue<Node> q;
void dijkstra(int id, int x)
{
    memset(vis, 0, sizeof(vis));
    memset(dis[id], 0x3f, sizeof(dis[id]));
    dis[id][x] = 0;
    q.push((Node){x, 0});
    while (!q.empty())
    {
        Node temp = q.top();
        q.pop();
        if (vis[temp.y] == 1)
            continue;
        vis[temp.y] = 1;
        for (int i = 0; i < d[temp.y].size(); i++)
        {
            Node node = d[temp.y][i];
            if (dis[id][node.y] > dis[id][temp.y] + node.w)
            {
                dis[id][node.y] = dis[id][temp.y] + node.w;
                q.push((Node){node.y, dis[id][node.y]});
            }
        }
    }
}

struct edge
{
    int to, cst;
} el2[MAXN * MAXN];
int E2, head2[MAXN], nxt2[MAXN * MAXN], len[MAXN], deg[MAXN], que[MAXN], he, ta;
inline void addedge2(int u, int v, int w)
{
    E2++;
    el2[E2] = (edge){v, w};
    nxt2[E2] = head2[u];
    head2[u] = E2;
    deg[v]++;
}
inline void quepush(int x)
{
    que[ta] = x;
    ta++;
}
inline int quepop()
{
    int ret = que[he];
    he++;
    return ret;
}
inline void topo()
{
    memset(vis, 0, sizeof(vis));
    he = ta = 1;
    for (int i = 1; i <= n; i++)
        if (!deg[i])
            quepush(i);
    while (he != ta)
    {
        int u = quepop();
        for (int i = head2[u]; i != -1; i = nxt2[i])
        {
            deg[el2[i].to]--;
            len[el2[i].to] = max(len[el2[i].to], len[u] + el2[i].cst);
            if (deg[el2[i].to] == 0)
                quepush(el2[i].to);
        }
    }
}

int main()
{
    memset(head2, -1, sizeof(head2));
    cin >> n >> m >> x1 >> y1 >> x2 >> y2;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        addNode(u, v, w);
        addNode(v, u, w);
    }
    dijkstra(1, x1);
    dijkstra(2, y1);
    dijkstra(3, x2);
    dijkstra(4, y2);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < d[i].size(); j++)
        {
            if (dis[1][i] + d[i][j].w + dis[2][d[i][j].y] == dis[1][y1])
                if (dis[3][i] + d[i][j].w + dis[4][d[i][j].y] == dis[3][y2])
                {
                    addedge2(i, d[i][j].y, d[i][j].w);
                    // cout << "data1: " << i << ' ' << d[i][j].y << ' ' << d[i][j].w << endl;
                }
        }
    }
    topo();
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, len[i]);
    memset(head2, -1, sizeof(head2));
    E2 = 0;
    memset(deg, 0, sizeof(deg));
    memset(len, 0, sizeof(len));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < d[i].size(); j++)
        {
            if (dis[1][i] + d[i][j].w + dis[2][d[i][j].y] == dis[1][y1])
                if (dis[4][i] + d[i][j].w + dis[3][d[i][j].y] == dis[3][y2])
                {
                    addedge2(i, d[i][j].y, d[i][j].w);
                    // cout << "data2: " << i << ' ' << d[i][j].y << ' ' << d[i][j].w << endl;
                }
        }
    }
    topo();
    for (int i = 1; i <= n; i++)
        ans = max(ans, len[i]);
    printf("%d\n", ans);

    return 0;
}
