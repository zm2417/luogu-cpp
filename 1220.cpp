#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxInf = 55;
int n, c;
int dp[maxInf][maxInf][2];
int sum[maxInf]; // 功率前缀和

struct Node
{
    int p, w;
} node[maxInf];

// 区间dp 去关某一区间的灯，那么整条街道上除了这一区间的灯会逐渐灭掉其他肯定会全亮。
int main()
{
    cin >> n >> c;
    for (int i = 1; i <= n; i++)
    {
        cin >> node[i].p >> node[i].w;
        sum[i] = sum[i - 1] + node[i].w;
    }
    memset(dp, 127, sizeof(dp));
    for (int i = c; i >= 1; i--)
    {
        for (int j = c; j <= n; j++)
        {
            if (i == c && j == c)
                dp[c][c][0] = 0, dp[c][c][1] = 0;
            else
            {
                dp[i][j][0] = min(dp[i + 1][j][0] + (node[i + 1].p - node[i].p) * (sum[n] + sum[i] - sum[j]),
                                  dp[i + 1][j][1] + (node[j].p - node[i].p) * (sum[n] + sum[i] - sum[j]));

                dp[i][j][1] = min(dp[i][j - 1][0] + (node[j].p - node[i].p) * (sum[n] + sum[i - 1] - sum[j - 1]),
                                  dp[i][j - 1][1] + (node[j].p - node[j - 1].p) * (sum[n] + sum[i - 1] - sum[j - 1]));
            }
        }
    }
    cout << min(dp[1][n][0], dp[1][n][1]);
    return 0;
}