#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int dp[m + 1][n+1];
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dp[i][j] = 0;
        }
    }
    int v[m + 1], w[m + 1];
    for (int i = 1; i < m + 1; i++)
    {
        cin >> v[i] >> w[i];
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (j < v[i])
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j] > (dp[i - 1][j - v[i]] + v[i] * w[i]) ? dp[i - 1][j] : (dp[i - 1][j - v[i]] + v[i] * w[i]);
            }
        }
    }
    cout << dp[m][n];
    // for (int i = 0; i <= m; i++)
    // {
    //     for (int k : dp[i])
    //     {
    //         cout << k << ' ';
    //     }
    //     cout << endl;
    // }
}