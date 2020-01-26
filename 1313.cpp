#include <iostream>
using namespace std;

int a,b,k,n,m;
int MOD = 10007;
long long dp[1005][1005];

int main()
{
    cin >> a >> b >>k >>n >>m;
    dp[0][0] = 1;
    for (int  i = 0; i <= n; i++)
    {
        for(int j = 0;j<=m;j++)
        {
            if(i ==0 && j == 0)continue;
            if(i > 0)
                dp[i][j] = (dp[i-1][j] * a + dp[i][j]) % MOD;
            if(j > 0 )
                dp[i][j] = (dp[i][j-1] * b + dp[i][j]) % MOD;
        }
    }
    cout << dp[n][m];
    return 0;
}