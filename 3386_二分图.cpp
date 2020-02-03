#include <iostream>
using namespace std;

int n, m, e, u, v;
int d[1010][1010];
int vis[1010];
int er[1010];
int ans;

bool dfs(int x)
{
    for (int i = 1; i <= m; i++)
    {
        if (vis[i] == 0 && d[x][i] == 1)
        {
            vis[i] = 1;
            if (er[i] == 0 || dfs(er[i]))
            {
                er[i] = x;
                return true;
            }
        }
    }
    return false;
}

void initVis()
{
    for (int i = 0; i < 1010; i++)
        vis[i] = 0;
}

int main()
{
    cin >> n >> m >> e;
    for (int i = 0; i < e; i++)
    {
        cin >> u >> v;
        if (u > n || v > m)
            continue;
        d[u][v] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        initVis();
        if (dfs(i))
            ans++;
    }
    cout << ans << endl;
    return 0;
}