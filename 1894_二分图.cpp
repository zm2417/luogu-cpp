#include <iostream>
using namespace std;

int n, m;
int d[250][250];
int cow[250]; // 牛栏中的牛编号
int vis[250];
int ans;

// x: 牛的编号
bool dfs(int x)
{
    // 遍历牛栏
    for (int i = 1; i <= m; i++)
    {
        if (d[x][i] && !vis[i])
        {
            vis[i] = 1;
            if (cow[i] == 0 || dfs(cow[i])) // 牛栏没有牛 或者 修改连线
            {
                cow[i] = x;
                return true;
            }
        }
    }
    return false;
}

inline void initVis()
{
    for (int i = 0; i < 250; i++)
        vis[i] = 0;
}

int main()
{
    cin >> n >> m;
    int si, sj;
    for (int i = 1; i <= n; i++)
    {
        cin >> si;
        for (int j = 1; j <= si; j++)
        {
            cin >> sj;
            d[i][sj] = 1;
        }
    }
    // 遍历牛编号
    for (int i = 1; i <= n; i++)
    {
        initVis();
        if (dfs(i))
            ans++;
    }
    cout << ans << endl;
    return 0;
}