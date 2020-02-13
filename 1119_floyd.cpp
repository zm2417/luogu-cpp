#include <iostream>
using namespace std;

const int MAXW = 20000;
const int MAXN = 205;
int n, m, q;
int x, y, t;
int times[MAXN], dis[MAXN][MAXN];
int now;

// 理解floyd思想的,Floyd算法就是一个利用其它点进行中转来求最短路的步骤。

// 所有的边全部给出，按照时间顺序更新每一个可用的点（即修建好村庄），
// 对于每个时间点进行两点之间询问，求对于目前建设的所有村庄来说任意两点之间的最短路
// 不正好就是Floyd算法中使用前k个节点更新最短路的思维吗？

// 将最外层的中转点的循环,放到询问循环中(时间是单调递增)
void floyd(int k)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (dis[i][j] > dis[i][k] + dis[k][j])
                dis[i][j] = dis[i][k] + dis[k][j];
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> times[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i != j)
                dis[i][j] = MAXW;
    for (int k = 0; k < m; k++)
    {
        int i, j, w;
        cin >> i >> j >> w;
        dis[i][j] = w;
        dis[j][i] = w;
    }
    cin >> q;
    for (int k = 0; k < q; k++)
    {
        cin >> x >> y >> t;
        while (times[now] <= t && now < n)
        {
            floyd(now);
            now++;
        }
        if (dis[x][y] == MAXW || times[x] > t || times[y] > t)
            cout << -1 << endl;
        else
            cout << dis[x][y] << endl;
    }
    return 0;
}
