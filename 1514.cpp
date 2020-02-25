#include <iostream>
#include <algorithm>
using namespace std;

const int maxInf = 510;
int n, m, d[maxInf][maxInf], vis[maxInf][maxInf];
int op[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

struct Node
{
    int l = INT32_MAX, r = INT32_MIN;
} node[maxInf][maxInf];

void dfs(int x, int y)
{
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int xx = x + op[i][0], yy = y + op[i][1];
        if (xx > 0 && xx <= n && yy > 0 && yy <= m && d[x][y] > d[xx][yy])
        {
            if (vis[xx][yy] == 0)
            {
                dfs(xx, yy);
            }
            node[x][y].l = min(node[xx][yy].l, node[x][y].l);
            node[x][y].r = max(node[xx][yy].r, node[x][y].r);
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> d[i][j];

    for (int i = 1; i <= m; i++)
        node[n][i].l = i, node[n][i].r = i;

    for (int i = 1; i <= m; i++)
        if (vis[1][i] == 0)
            dfs(1, i);

    int num = 0;
    for (int i = 1; i <= m; i++)
    {
        if (vis[n][i] == 1)
            num++;
    }
    if (num != m)
    {
        cout << 0 << endl
             << m - num;
    }
    else
    {
        int left = 1, minNum = 0;
        while (left <= m)
        {
            int maxr = 0;
            for (int i = 1; i <= m; i++)
            {
                if (node[1][i].l <= left)
                {
                    maxr = max(maxr, node[1][i].r);
                }
            }
            minNum++;
            left = maxr + 1;
        }
        cout << 1 << endl
             << minNum;
    }

    // cout << endl;
    // for (int i = 1; i <= m; i++)
    //     cout << node[1][i].l << ' ' << node[1][i].r << endl;
    return 0;
}
