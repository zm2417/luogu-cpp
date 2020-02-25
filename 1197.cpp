#include <iostream>
#include <vector>
using namespace std;

int n, m, k;
const int maxInf = 400020;

int parent[maxInf];
vector<int> g[maxInf];
vector<pair<int, int>> v;
int destory[maxInf], p[maxInf];
int ans[maxInf];

void init()
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
}
int find(int x)
{
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}
void join(int x, int y)
{
    int xp = find(x), yp = find(y);
    if (xp != yp)
        parent[xp] = yp;
}
int findNum()
{
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        if (parent[i] == i && destory[i] == 0)
            x++;
    }
    return x;
}

// 摧毁与安装是相对的
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(x, y));
        g[x].push_back(y);
        g[y].push_back(x);
    }
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> p[i];
        destory[p[i]] = 1;
    }
    init();
    for (int i = 0; i < m; i++)
    {
        int x = v[i].first, y = v[i].second;
        if (destory[x] != 1 && destory[y] != 1)
        {
            join(x, y);
        }
    }
    int tot = findNum();
    for (int i = 0; i <= k; i++)
    {
        ans[i] = tot;
        int x = p[k - i - 1];
        destory[x] = 0;
        tot++;
        if (g[x].size())
            for (int j = 0; j < g[x].size(); j++)
            {
                if (destory[g[x][j]] == 0)
                {
                    if (find(x) != find(g[x][j]))
                    {
                        tot--;
                        join(x, g[x][j]);
                    }
                }
            }
    }
    for (int i = k; i >= 0; i--)
    {
        cout << ans[i] << endl;
    }
    return 0;
}