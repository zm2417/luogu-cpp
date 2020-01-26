#include <iostream>
using namespace std;

const int MOD = 9901;
int n, k;
// dp[i][j]表示i个点小于等于j层的方案数，那么最终我们所需的答案就是dp[n][k]-dp[n][k-1]是不是？
int dp[205][105];

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
    {
        dp[1][i] = 1;
    }
    for (int i = 1; i <= k; i++)
    {
        for (int j = 3; j <= n; j += 2)
        {
            for (int l = 1; l < j; l += 2)
            {
                dp[j][i] += dp[l][i-1] * dp[j-l-1][i-1] % MOD;
                dp[j][i] %= MOD;
            }
        }
    }
    cout << (dp[n][k] - dp[n][k-1] + MOD) % MOD << endl;
    return 0;
}