#include <iostream>
using namespace std;

const int maxW = 400;
int n;
int w;
long long dp[40][maxW];
long long ans;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        w += i;
    }
    if (w % 2 != 0)
    {
        cout << 0;
        return 0;
    }
    w /= 2;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        // dp[i][i] = 1;
        for (int j = 0; j <= w; j++)
        {
            if (j >= i)
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - i]; // 放於不放兩種之和
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     // ans += dp[i][w];
    //     for (int j = 0; j <= w; j++)
    //     {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    cout << dp[n][w] / 2 << endl;
    return 0;
}