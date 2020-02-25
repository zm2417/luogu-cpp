#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // n:菜；m:钱
    int n, m;
    cin >> n >> m;
    int dp[m + 1] = {0};
    int v[n+1];
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= v[i]; j--)
        {
            dp[j] += dp[j - v[i]];
        }
    }
    cout << dp[m];
    return 0;
}