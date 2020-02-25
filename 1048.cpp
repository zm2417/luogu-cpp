#include <iostream>
using namespace std;

int main()
{
    //t:时间；m:药的数量
    int t, m;
    cin >> t >> m;
    int d[m + 1], v[m + 1];
    for (int i = 1; i < m + 1; i++)
    {
        cin >> d[i] >> v[i];
    }
    int dp[t + 1] = {0};

    for (int i = 1; i <= m; i++)
    {
        for (int j = t; j >= d[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - d[i]] + v[i]);
        }
    }
    cout << dp[t];
    return 0;
}