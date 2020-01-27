#include <iostream>
using namespace std;

int n, t, m;
int d[25];
int dp[25][25];

int main()
{
    cin >> n >> t >> m;
    for (int i = 1; i <= n; i++)
        cin >> d[i];
    for (int k = 1; k <= n; k++)
        for (int i = m; i >= 1; i--)
            for (int j = t; j >= d[k]; j--)
                dp[i][j] = max(dp[i][j], max(dp[i - 1][t] + 1, dp[i][j - d[k]] + 1));
    cout << dp[m][t] << endl;
    return 0;
}