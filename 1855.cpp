#include <iostream>
using namespace std;

// 第几个，目前的钱，目前的时间
int dp[101][210][210];

int main()
{
    int n, m, t;
    cin >> n >> m >> t;
    int d[n][2];
    for (int i = 0; i < n; i++)
    {
        cin >> d[i][0] >> d[i][1];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            for (int k = 0; k <= t; k++)
            {
                if (j >= d[i - 1][0] && k >= d[i - 1][1])
                    dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][j - d[i - 1][0]][k - d[i - 1][1]] + 1);
                else
                {
                    dp[i][j][k] = dp[i - 1][j][k];
                }
                ans = max(ans, dp[i][j][k]);
            }
        }
    }
    cout << ans;
    return 0;
}