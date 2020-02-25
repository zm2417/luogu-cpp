#include <iostream>
using namespace std;

const int maxInf = 10005;
int dp[maxInf][2][2];

int n, d[maxInf];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
    }
    dp[0][0][0] = dp[0][0][1] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (d[i] == 0)
        {
            dp[i][0][0] += dp[i - 1][0][0];
        }
        else if (d[i] == 1)
        {
            dp[i][0][0] += dp[i - 1][1][0];
            dp[i][0][1] += dp[i - 1][0][0];
            dp[i][1][0] += dp[i - 1][0][1];
        }
        else if (d[i] == 2)
        {
            dp[i][1][0] += dp[i - 1][1][1];
            dp[i][0][1] += dp[i - 1][1][0];
            dp[i][1][1] += dp[i - 1][0][1];
        }
        else
        {
            dp[i][1][1] += dp[i - 1][1][1];
        }
    }
    cout << dp[n][1][0] + dp[n][0][0];
    return 0;
}