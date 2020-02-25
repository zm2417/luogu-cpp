#include <iostream>
#include <queue>
#include <string>
using namespace std;

int m, n;
int d[55][55][4];
int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};
int used[55][55];
int s, maxNum;
int f[55 * 55]; //记录编号s的房间的间数
string z = "WNEA";
int z1, z2;
char z3;
queue<pair<int, int>> q;

int main()
{
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int x;
            cin >> x;
            if (x & 1)
                d[i][j][0] = 1;
            if (x & 2)
                d[i][j][1] = 1;
            if (x & 4)
                d[i][j][2] = 1;
            if (x & 8)
                d[i][j][3] = 1;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (used[i][j] == 0)
            {
                used[i][j] = ++s;
                int sum = 0;
                q.push(make_pair(i, j));
                while (!q.empty())
                {
                    pair<int, int> p = q.front();
                    // cout << p.first << ' ' << p.second << endl;
                    sum++;
                    q.pop();
                    for (int k = 0; k < 4; k++)
                    {
                        int xi = p.first + dx[k], yi = p.second + dy[k];
                        if (xi > 0 && xi <= n && yi > 0 && yi <= m && d[p.first][p.second][k] == 0 && used[xi][yi] == 0)
                        {
                            q.push(make_pair(xi, yi));
                            used[xi][yi] = s;
                        }
                    }
                }
                maxNum = max(maxNum, sum);
                f[s] = sum;
                // cout << i << ' ' << j << ' ' << sum << endl;
            }
        }
    }
    cout << s << endl
         << maxNum << endl;
    for (int j = 1; j <= m; j++)
    {
        for (int i = n; i >= 1; i--)
        {
            for (int k = 1; k <= 2; k++)
            {
                if (d[i][j][k])
                {
                    int xi = dx[k] + i, yi = dy[k] + j;
                    int x = f[used[i][j]] + f[used[xi][yi]];
                    if (x > maxNum && used[i][j] != used[xi][yi])
                    {
                        maxNum = x;
                        z1 = i;
                        z2 = j;
                        z3 = z[k];
                    }
                }
            }
        }
    }
    cout << maxNum << endl
         << z1 << ' ' << z2 << ' ' << z3;
    return 0;
}