/**
 * 洛谷cpp算法
 * 
 * @author: zhangMeng
 * @date: 2020-02-28 
 */
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 10005, inf = 23333333;
int n, m, a, b, c;
struct Node
{
    int y, v;
};

vector<Node> d[MAXN];
int dis[MAXN], vis[MAXN];

bool spfa(int x)
{
    vis[x] = 1;
    for (int i = 0; i < d[x].size(); i++)
    {
        Node temp = d[x][i];
        if (dis[temp.y] < dis[x] + temp.v)
        {
            dis[temp.y] = dis[x] + temp.v;
            if (vis[temp.y] == 1) // 判环
                return false;
            if (!spfa(temp.y))
                return false;
        }
    }
    vis[x] = 0;
    return true;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int j;
        cin >> j;
        if (j == 1)
        {
            cin >> a >> b >> c;
            d[b].push_back((Node){a, c});
        }
        else if (j == 2)
        {
            cin >> a >> b >> c;
            d[a].push_back((Node){b, -1 * c});
        }
        else
        {
            cin >> a >> b;
            d[a].push_back((Node){b, 0});
            d[b].push_back((Node){a, 0});
        }
    }

    for (int i = 1; i <= n; i++)
        d[0].push_back((Node){i, 0}), dis[i] = -inf;
    // 以0开始.0相当于是一个“超级源点”（因为图可能不联通）
    if (!spfa(0))
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
    return 0;
}
