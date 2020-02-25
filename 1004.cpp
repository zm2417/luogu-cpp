#include <iostream>
using namespace std;

// 四维dp
int d[10][10], dp[10][10][10][10];

int main()
{
    int n;
    cin >> n;
    int x, y, z;
    cin >> x >> y >> z;
    while (x != 0 || y != 0 || z != 0)
    {
        d[x][y] = z;
        cin >> x >> y >> z;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                for (int l = 1; l <= n; l++) // 优化 ==》 l = i+j-k;
                {
                    dp[i][j][k][l] = max(max(dp[i - 1][j][k][l-1], dp[i][j - 1][k-1][l]), max(dp[i-1][j][k - 1][l], dp[i][j-1][k][l - 1])) + d[i][j] + d[k][l];
                    if (i == k && j == l)
                        dp[i][j][k][l] -= d[i][j];
                }

    cout << dp[n][n][n][n];
    return 0;
}