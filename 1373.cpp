#include <iostream>
using namespace std;

const int maxInf = 805;
const int mod = 1000000007;
int n, m, k;
int d[maxInf][maxInf], dp[maxInf][maxInf][20][2];

int main()
{
    cin >> n >> m >> k;
    k++;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> d[i][j];
            dp[i][j][d[i][j] % k][0] = 1;
        }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            for (int h = 0; h < k; h++)
            {
                dp[i][j][h][0]=(dp[i][j][h][0]+dp[i-1][j][(h-d[i][j]+k)%k][1])%mod;
                dp[i][j][h][0]=(dp[i][j][h][0]+dp[i][j-1][(h-d[i][j]+k)%k][1])%mod;
                dp[i][j][h][1]=(dp[i][j][h][1]+dp[i-1][j][(h+d[i][j])%k][0])%mod;
                dp[i][j][h][1]=(dp[i][j][h][1]+dp[i][j-1][(h+d[i][j])%k][0])%mod;
            }
        }

    long long ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            // ans  = (ans + dp[i][j][0][1]) % mod;
            ans += dp[i][j][0][1] % mod;
    ans %= mod;
    cout << ans<< endl;
    return 0;
}