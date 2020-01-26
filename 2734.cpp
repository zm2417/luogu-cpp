#include <iostream>
using namespace std;

int n, d[110];
int sum[110], dp[110][110];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
        sum[i] = sum[i - 1] + d[i];
        dp[i][i] = d[i];
    }
    for (int len = 1; len <= n; len++)
        for (int l = 1; l + len <= n; l++)
        {
            int r = l + len;
            dp[l][r] = sum[r] - sum[l - 1] - min(dp[l + 1][r], dp[l][r - 1]);
        }
    cout << dp[1][n] << ' ' << sum[n] - dp[1][n] << endl;
    return 0;
}