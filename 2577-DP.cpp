/**
 * 洛谷cpp算法
 * 
 * @author: zhangMeng
 * @date: 2020-03-07 
 */
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 205;
int n, ai, bi;
struct Node
{
    int da, eat;
    friend bool operator<(Node n1, Node n2)
    {
        return n1.eat == n2.eat ? n1.da > n2.da : n1.eat > n2.eat;
    }
} d[MAXN];
int dp[MAXN][MAXN * MAXN]; // i个人,在1号打饭j,最终吃完的时间
int sum[MAXN];

void init()
{
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = dp[i][1] = 200 * 200 * 10;
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        Node node;
        cin >> node.da >> node.eat;
        d[i] = node;
    }
    sort(d + 1, d + 1 + n);
    memset(dp, 127, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + d[i].da;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum[i]; j++)
        {
            if (j >= d[i].da)
                dp[i][j] = min(dp[i][j], max(dp[i - 1][j - d[i].da], j + d[i].eat));
            dp[i][j] = min(dp[i][j], max(dp[i - 1][j], sum[i] - j + d[i].eat));
        }
    }
    int ans = INT16_MAX;
    for (int i = 1; i <= sum[n]; i++)
    {
        ans = min(ans, dp[n][i]);
    }
    cout << ans << endl;
    return 0;
}
