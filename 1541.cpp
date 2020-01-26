#include <iostream>
using namespace std;

int dp[41][41][41][41];

int main()
{
    int n, m;
    cin >> n >> m;
    int dis[n];
    for (int i = 0; i < n; i++)
    {
        cin >> dis[i];
    }
    int card[5] = {0};
    for (int i = 0; i < m; i++)
    {
        int j;
        cin >> j;
        card[j]++;
    }
    dp[0][0][0][0] = dis[0];
    for (int i = 0; i <= card[1]; i++)
    {
        for (int j = 0; j <= card[2]; j++)
        {
            for (int k = 0; k <= card[3]; k++)
            {
                for (int l = 0; l <= card[4]; l++)
                {
                    if (i == 0 && j == 0 && k == 0 && l == 0)
                        continue;
                    if (i != 0)
                        dp[i][j][k][l] = max(dp[i][j][k][l], dp[i - 1][j][k][l]);
                    if (j != 0)
                        dp[i][j][k][l] = max(dp[i][j][k][l], dp[i][j - 1][k][l]);
                    if (k != 0)
                        dp[i][j][k][l] = max(dp[i][j][k][l], dp[i][j][k - 1][l]);
                    if (l != 0)
                        dp[i][j][k][l] = max(dp[i][j][k][l], dp[i][j][k][l - 1]);
                    dp[i][j][k][l] += dis[i + 2 * j + 3 * k + 4 * l];
                }
            }
        }
    }
    cout << dp[card[1]][card[2]][card[3]][card[4]];
    return 0;
}