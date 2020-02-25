#include <iostream>
using namespace std;

int dp[60][60][60][60];

int main()
{
    int m, n;
    cin >> m >> n;
    int d[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> d[i][j];
        }
    }

    // 两个要同时走
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= m; k++)
            {
                int l = i + j - k;
                if (l <= 0)
                    continue;
                dp[i][j][k][l] = max(dp[i - 1][j][k - 1][l], max(dp[i - 1][j][k][l - 1], max(dp[i][j - 1][k - 1][l], dp[i][j - 1][k][l - 1])));
                if (i == k && j == l)
                {
                    dp[i][j][k][l] += d[k - 1][l - 1];
                }
                else
                {
                    dp[i][j][k][l] += d[i - 1][j - 1] + d[k - 1][l - 1];
                }
                // cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << dp[i][j][k][l] << endl;
            }

    cout << dp[m][n][m][n];
    return 0;
}