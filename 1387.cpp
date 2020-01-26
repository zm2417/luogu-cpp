#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int dp[n][m][3];
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int k;
            cin >> k;
            if (k == 0)
            {
                dp[i][j][0] = 0, dp[i][j][1] = 0, dp[i][j][2] = 0;
            }
            else
            {
                if (i == 0 && j == 0)
                    dp[i][j][0] = 1, dp[i][j][1] = 0, dp[i][j][2] = 0;
                else if (i == 0)
                {
                    dp[i][j][0] = 1, dp[i][j][1] = 0, dp[i][j][2] = dp[i][j - 1][2] + 1;
                }
                else if (j == 0)
                {
                    dp[i][j][0] = 1, dp[i][j][1] = dp[i - 1][j][1] + 1, dp[i][j][2] = 0;
                }
                else
                {
                    int x = min(dp[i-1][j][1], dp[i][j-1][2]);
                    dp[i][j][0] = min(dp[i - 1][j - 1][0], x) + 1;
                    dp[i][j][1] = dp[i - 1][j][1] + 1, dp[i][j][2] = dp[i][j - 1][2] + 1;
                }
            }
            ans = max(ans, dp[i][j][0]);
        }
    }
    cout << ans;
    return 0;
}