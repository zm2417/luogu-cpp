#include <iostream>
#include <cstring>
using namespace std;

int k, n;
int d[55];
int dp[200 * 10000];

int main()
{
    cin >> k >> n;
    for (int i = 0; i < n; i++)
        cin >> d[i];
    for (int j = 0; j <= 200 * 10000; j++)
    {
        dp[j] = 2000;
    }
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = d[i]; j <= 200 * 10000; j++)
        {
            dp[j] = min(dp[j - d[i]] + 1, dp[j]);
        }
    }
    int s = 0;
    for (int j = 0; j <= 200 * 10000; j++)
    {
        // cout << dp[j] << endl;
        if (dp[j] <= k)
        {
            s = j;
        }
        else
        {
            break;
        }
    }
    cout << s << endl;
    return 0;
}
