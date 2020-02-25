#include <iostream>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    int d[m][n + 2];
    for (int i = 0; i < m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> d[i][j];
        }
    }
    int startj = n / 2 + 1;
    long long dp[201][210];
    for (int i = 0; i < m; i++)
        for (int j = 0; j <= n + 1; j++)
            dp[i][j] = INT32_MIN;
    dp[m - 1][startj] = d[m - 1][startj], dp[m - 1][startj - 1] = d[m - 1][startj - 1], dp[m - 1][startj + 1] = d[m - 1][startj + 1];
    for (int i = m - 2; i >= 0; i--)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = max(dp[i + 1][j], max(dp[i + 1][j - 1], dp[i + 1][j + 1])) + d[i][j];
        }
    }
    long long maxAns = INT32_MIN;
    for (int i = 1; i <= n; i++)
    {
        maxAns = max(maxAns, dp[0][i]);
    }
    cout << maxAns;
    return 0;
}