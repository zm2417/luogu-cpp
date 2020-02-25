#include <iostream>
#include <algorithm>
using namespace std;

// struct Node
// {
//     int x, y, z;
// } node[200000];
// int ans = 0;

// //  === 方法1: Kruskal + 并查集 ===
// // 并查集
// int parent[5001];
// void init(int n)
// {
//     for (int i = 1; i <= n; i++)
//         parent[i] = i;
// }
// int findParent(int x)
// {
//     if (parent[x] != x)
//         parent[x] = findParent(parent[x]);
//     return parent[x];
// }
// void unionSet(int x, int y)
// {
//     int xP = findParent(x);
//     int yP = findParent(y);
//     parent[xP] = yP;
// }
// // sort
// bool comp(Node n1, Node n2)
// {
//     return n1.z < n2.z;
// }
// void kruskal(int n, int m)
// {
//     init(n);
//     sort(node, node + m, comp);
//     for (int i = 0; i < m; i++)
//     {
//         int xP = findParent(node[i].x), yP = findParent(node[i].y);
//         if (xP == yP)
//             continue;
//         ans += node[i].z;
//         unionSet(node[i].x, node[i].y);
//     }
//     int root = -1;
//     for (int i = 1; i <= n; i++)
//     {
//         if (root == -1)
//             root = findParent(i);
//         else
//         {
//             if (root != findParent(i))
//             {
//                 cout << "orz";
//                 return;
//             }
//         }
//     }
//     cout << ans;
// }

// int main()
// {
//     int n, m;
//     cin >> n >> m;
//     for (int i = 0; i < m; i++)
//         cin >> node[i].x >> node[i].y >> node[i].z;
//     kruskal(n, m);
//     return 0;
// }

// === 方法2: prim ===
struct Edge
{
    // v:初始节点 next: 下一个节点 w: 距离
    int v, next, w;
} edge[200005 << 1];
// head: 链接头部 dis:
int head[5005], dis[5005], ans, k;
bool vis[5005];
void prim(int n, int m)
{
    for (int i = 2; i <= n; i++)
    {
        dis[i] = INT32_MAX;
    }
    // 初始化与1节点的距离dis数组
    for (int i = head[1]; i; i = edge[i].next)
    {
        dis[edge[i].v] = min(dis[edge[i].v], edge[i].w);
    }
    int totol = 0;
    int p = 1;
    while (++totol < n)
    {
        int minInf = INT32_MAX;
        vis[p] = true;
        // 查最短距离
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i] && minInf > dis[i])
            {
                minInf = dis[i];
                p = i;
            }
        }
        ans += minInf;
        // 更新dis数组
        for (int i = head[p]; i; i = edge[i].next)
        {
            int v = edge[i].v;
            if (!vis[v] && dis[v] > edge[i].w)
            {
                dis[v] = edge[i].w;
            }
        }
    }
    cout << ans;
    return;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        // 头部插入链表节点
        edge[++k].v = x;
        edge[k].w = z;
        edge[k].next = head[y];
        head[y] = k;

        edge[++k].v = y;
        edge[k].w = z;
        edge[k].next = head[x];
        head[x] = k;
    }
    prim(n, m);
    return 0;
}