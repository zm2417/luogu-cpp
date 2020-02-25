#include <iostream>
using namespace std;

const int max_n = 10005;
int m, n;
int d[max_n][2];
int dp[max_n];

int main()
{
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i][0] >> d[i][1];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = d[i][1]; j <= m; j++)
        {
            dp[j] = max(dp[j], dp[j - d[i][1]] + d[i][0]);
        }
    }
    cout << dp[m] << endl;
    return 0;
}