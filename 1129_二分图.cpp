#include <iostream>
#include <cstring>
using namespace std;

int t, n;
int d[210][210];
int mask[210], vis[210];

bool dfs(int x)
{
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0 && d[x][i] == 1)
        {
            vis[i] = 1;
            if (mask[i] == 0 || dfs(mask[i]))
            {
                mask[i] = x;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                cin >> d[j][k];
        int ans = 0;
        memset(mask, 0, sizeof(mask));
        for (int j = 1; j <= n; j++)
        {
            memset(vis, 0, sizeof(vis));
            if (dfs(j))
                ans++;
        }
        if (ans < n)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
    return 0;
}