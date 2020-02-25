#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
#define N 100001
// n:钱；m:物品个数
int n, m;
int v[N][3], p[N][3], q[N][3];
int flag[N] = {0};

// 题目告诉我们每个主件只有0,1,2个附件所以产生了五种情况：1.只买主件  2.买主件+附件1  3.买主件+附件2   4.都买   5.不买。
int main()
{
    cin >> n >> m;
    // v:价格 p:等级 q:0：主件
    for (int i = 1; i <= m; i++)
    {
        int v1, p1, q1;
        cin >> v1 >> p1 >> q1;
        if (q1 == 0)
        {
            v[i][0] = v1;
            p[i][0] = p1 * v1;
            q[i][0] = q1;
        }
        else
        {
            int t = q1;
            if (flag[t] == 0)
            {
                v[t][1] = v1;
                p[t][1] = p1 * v1;
                q[t][1] = q1;
                flag[t] = 1;
            }
            else
            {
                v[t][2] = v1;
                p[t][2] = p1 * v1;
                q[t][2] = q1;
            }
        }
    }
    int dp[n + 1] = {0};

    for (int i = 1; i <= m; i++)
    {
        if (v[i][0] > 0)
        {
            for (int j = n; j > 0; j--)
            {
                if (j >= v[i][0])
                {
                    dp[j] = max(dp[j], dp[j - v[i][0]] + p[i][0]);
                }
                if (j >= v[i][0] + v[i][1])
                {
                    dp[j] = max(dp[j], dp[j - v[i][0] - v[i][1]] + p[i][0] + p[i][1]);
                }
                if (j >= v[i][0] + v[i][2])
                {
                    dp[j] = max(dp[j], dp[j - v[i][0] - v[i][2]] + p[i][0] + p[i][2]);
                }
                if (j >= v[i][0] + v[i][2] + v[i][1])
                {
                    dp[j] = max(dp[j], dp[j - v[i][0] - v[i][2] - v[i][1]] + p[i][0] + p[i][2] + p[i][1]);
                }
            }
        }
    }
    // cout << endl;
    // for (int i = 0; i <= n; i++)
    // {
    //     cout << dp[i] << ' ';
    // }
    cout << dp[n];

    return 0;
}