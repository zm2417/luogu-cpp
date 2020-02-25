#include <iostream>
#include <cstring>
using namespace std;

int n, p, c;
int cow[805];
long long dp[805][805];

int main()
{
    cin >> n >> p >> c;
    for (int i = 1; i <= n; i++)
    {
        cin >> cow[i];
    }
    for (int i = 1; i <= p; i++)
    {
        for (int j = 1; j <= p; j++)
        {
            if (i == j)
                dp[i][j] = 0;
            else
                dp[i][j] = INT32_MAX;
        }
    }
    for (int i = 0; i < c; i++)
    {
        int a, b, d;
        cin >> a >> b >> d;
        dp[a][b] = d;
        dp[b][a] = d;
    }

    for (int k = 1; k <= p; k++)
    {
        for (int i = 1; i <= p; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                if (dp[i][k] + dp[k][j] < dp[i][j])
                {
                    dp[i][j] = dp[i][k] + dp[k][j];
                    dp[j][i] = dp[i][j];
                }
            }
        }
    }
    int minDis = INT32_MAX;
    for (int i = 1; i <= p; i++)
    {
        int t = 0;
        for (int j = 1; j <= n; j++)
        {
            if (i != cow[j])
                t += dp[i][cow[j]];
        }
        minDis = min(t, minDis);
    }
    cout << minDis << endl;
    return 0;
}