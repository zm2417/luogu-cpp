#include <iostream>
using namespace std;

int dp[120][120];

int main()
{
    int n, m;
    cin >> n >> m;
    int d[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            for (int k = 0; k <= d[i] && k <= j; k++)
            {
                dp[i][j] += dp[i-1][j-k];
                dp[i][j] %= 1000007;
            }
        }
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 0; j <= m; j++)
    //     {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    
    // int ans = 0;
    // for (int i = 1; i <= n; i++)
    // {
    //     ans += dp[i][m];
    //     ans %= 1000007;
    // }
    cout << dp[n][m];
    return 0;
}