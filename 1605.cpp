#include <iostream>
using namespace std;
int ans = 0;
int d[5][5];

void dfs(int x, int y, int fx, int fy)
{
    if(x <0 || x>4 || y<0||y>4)
    {
        return;
    }
    if (x == fx && y == fy)
    {
        ans++;
        return;
    }
    if (d[x][y] == 0)
    {
        d[x][y] = 1;
        dfs(x + 1, y, fx, fy);
        dfs(x, y + 1, fx, fy);
        dfs(x - 1, y, fx, fy);
        dfs(x, y - 1, fx, fy);
        d[x][y] = 0;
    }
}

int main()
{
    int n, m, t, sx, sy, fx, fy;
    cin >> n >> m >> t >> sx >> sy >> fx >> fy;
    // int d[n][m];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if(i >=n || j>= m)
            {
                d[i][j] = 1;
            }else
            {
                d[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < t; i++)
    {
        int x, y;
        cin >> x >> y;
        d[x-1][y-1] = 1;
    }
    if(d[fx-1][fy-1] == 1)
    {
        cout << 0;
        return 0;
    }
    dfs(sx-1, sy-1, fx-1, fy-1);
    cout << ans;

    return 0;
}