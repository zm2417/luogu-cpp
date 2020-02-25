#include <iostream>
using namespace std;

struct Node
{
    int s, e;
} node[250];

int d[250], dp[250][250];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
    }
    for (int i = n; i <= 2 * n; i++)
    {
        d[i] = d[i - n];
    }
    for (int i = 0; i < 2 * n; i++)
    {
        node[i].s = d[i];
        node[i].e = d[i + 1];
    }
    // 区间dp
    for (int len = 2; len <= n; len++)
    {
        for (int i = 0; i < 2 * n && i + len < 2 * n; i++)
        {
            int j = i + len - 1;
            for (int k = i; k < j; k++)
            {
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j] + node[i].s * node[k].e * node[j].e);
            }
        }
    }
    int maxPower = 0;
    for (int i = 0; i < n; i++)
    {
        maxPower = max(maxPower, dp[i][i + n - 1]);
    }
    cout << maxPower;
    return 0;
}