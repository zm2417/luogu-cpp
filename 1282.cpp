#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int d1[1005], d2[1005];
int dp[1005][5010];

int main()
{
    int n;
    cin >> n;
    int a = 0, b = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> d1[i] >> d2[i];
        a += d1[i], b += d2[i];
    }
    if (a == b)
    {
        cout << 0;
        return 0;
    }
    else if (a < b)
    {
        for (int i = 0; i < n; i++)
        {
            swap(d1[i], d2[i]);
        }
    }
    memset(dp, 0x7F, sizeof(dp));
    int maxDiff = abs(a - b);
    dp[0][maxDiff] = 0;
    for (int i = 1; i <= n; i++)
    {
        int x = 2 * (d2[i - 1] - d1[i - 1]);
        for (int j = 0; j <= 5000; j++)
        {
            int y = j - x;
            if (y >= 0 && y <= 5000)
            {
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][y] + 1);
            }else
            {
                dp[i][j] = dp[i-1][j];
            }
            
        }
    }
    int ans = 0;
    int minDiff = INT32_MAX;
    for (int i = 0; i <= maxDiff; i++)
    {

        if (dp[n][i] < 1000)
        {
            // cout << i << ' ' << dp[n][i] << endl;
            cout << dp[n][i];
            return 0;
        }
    }
    cout << 0;
    return 0;
}