#include <iostream>
using namespace std;

int main()
{
    int T, M;
    cin >> T >> M;
    int d[M + 1], v[M + 1];
    for (int i = 1; i <= M; i++)
    {
        cin >> d[i] >> v[i];
    }

    int dp[T + 1] = {0};
    // dp[0] = 1;

    for (int j = 1; j <= M; j++)
    {
        for (int i = d[j]; i <= T; i++)
        {
            dp[i] = max(dp[i], dp[i - d[j]] + v[j]);
        }
        // for (int k : dp)
        // {
        //     cout << k << ' ';
        // }
        // cout << endl;
    }

    cout << dp[T];

    return 0;
}