#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int dp[350000], stone[350000], a[105], dis[105];
int l, s, t, m;

int main()
{
    cin >> l >> s >> t >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + m + 1);
    for (int i = 1; i <= m; i++)
        dis[i] = (a[i] - a[i - 1]) % 2520;
    for (int i = 1; i <= m; i++)
    {
        a[i] = a[i - 1] + dis[i];
        stone[a[i]] = 1;
    }
    l = a[m];
    for (int i = 1; i <= l + t; i++)
        dp[i] = m;
    for (int i = 1; i <= l + t; i++)
    {
        for (int j = s; j <= t; j++)
        {
            if (i - j >= 0)
            {
                dp[i] = min(dp[i], dp[i - j]);
            }
            dp[i] += stone[i];
        }
    }
    int minInf = INT32_MAX;
    for (int i = l; i <= l + t; i++)
    {
        minInf = min(dp[i], minInf);
    }
    cout << minInf;
    return 0;
}