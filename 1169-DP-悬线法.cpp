/**
 * 洛谷cpp算法
 * 
 * @author: zhangMeng
 * @date: 2020-03-06 
 */
#include <iostream>

using namespace std;

const int MAXN = 2005;
int n, m;
int d[MAXN][MAXN];
// int dp[MAXN][MAXN];
int l[MAXN][MAXN];  // 代表从(i,j)(i,j)能到达的最左位置
int r[MAXN][MAXN];  // 代表从(i,j)(i,j)能到达的最右位置
int up[MAXN][MAXN]; // 代表从(i,j)(i,j)向上扩展最长长度.
int ans1, ans2;

void init()
{
    for (int i = 0; i <= n; i++)
        d[i][0] = -1;
    for (int j = 0; j <= m; j++)
        d[0][j] = -1;
}

int main()
{
    cin >> n >> m;
    // init();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> d[i][j];
            up[i][j] = 1;
            l[i][j] = r[i][j] = j;
        }
    for (int i = 1; i <= n; i++)
        for (int j = 2; j <= m; j++)
            if (d[i][j] != d[i][j - 1])
                l[i][j] = l[i][j - 1];
    for (int i = 1; i <= n; i++)
        for (int j = m - 1; j > 0; j--)
            if (d[i][j] != d[i][j + 1])
                r[i][j] = r[i][j + 1];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (i > 1 && d[i - 1][j] != d[i][j])
            {
                l[i][j] = max(l[i][j], l[i - 1][j]);
                r[i][j] = min(r[i][j], r[i - 1][j]);
                up[i][j] = up[i - 1][j] + 1;
            }
            int a = r[i][j] - l[i][j] + 1;
            int b = min(a, up[i][j]);
            ans1 = max(ans1, b * b);
            ans2 = max(ans2, a * up[i][j]);
        }
    cout << ans1 << endl
         << ans2 << endl;
    return 0;
}
