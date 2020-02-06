#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int n, m;
int dn[105][2], dm[105][2];
int map[105][105];
int ans;
int match[105], vis[105];

double cdn(int i)
{
    double a = abs(dn[i][0] - dn[i + 1][0]), b = abs(dn[i][1] - dn[i + 1][1]);
    return sqrt(a * a + b * b);
}

double cdm(int i, int j)
{
    double a = abs(dn[i][0] - dm[j][0]), b = abs(dn[i][1] - dm[j][1]);
    return sqrt(a * a + b * b);
}

bool check(int i, int j)
{
    return cdn(i) > (cdm(i, j) + cdm(i + 1, j)) / 2.0;
}

bool dfs(int x)
{
    for (int i = 1; i < n; i++)
    {
        if (vis[i] == 0 && map[i][x] == 1)
        {
            vis[i] = 1;
            if (match[i] == 0 || dfs(match[i]))
            {
                match[i] = x;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> dn[i][0] >> dn[i][1];
    for (int i = 1; i <= m; i++)
        cin >> dm[i][0] >> dm[i][1];
    for (int i = 1; i < n; i++)
        for (int j = 1; j <= m; j++)
            if (check(i, j))
                map[i][j] = 1;
    for (int i = 1; i <= m; i++)
    {
        memset(vis, 0, sizeof(vis));
        if (dfs(i))
            ans++;
    }
    cout << ans + n << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << dn[i][0] << ' ' << dn[i][1] << ' ';
        if (i == n)
        {
            cout << endl;
        }
        else
        {
            if (match[i] != 0)
                cout << dm[match[i]][0] << ' ' << dm[match[i]][1] << ' ';
        }
    }
    return 0;
}