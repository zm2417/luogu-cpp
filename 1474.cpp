#include <iostream>
using namespace std;

int v, n;
long long d[30];
long long dp[10005];

int main()
{
    cin >> v >> n;
    for (int i = 1; i <= v; i++)
    {
        cin >> d[i];
    }
    dp[0] = 1;
    for (int i = 1; i <= v; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if(j >= d[i])
                dp[j] += dp[j-d[i]];
        }
    }
    cout << dp[n] << endl;
    return 0;
}