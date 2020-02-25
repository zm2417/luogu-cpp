#include <iostream>
using namespace std;

const int maxINf = 55;
int n, m;
int d[maxINf];
// 逆序dp
double dp[maxINf][maxINf];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> d[i];
    }
    dp[1][1] = 1.0;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            for (int k = 0; k < m; k++)
            {
                int c = (d[k] % i != 0) ? d[k] % i : i;
                if (c < j)
                {
                    dp[i][j] += dp[i - 1][j - c] / m;
                }
                else if (c > j)
                {
                    dp[i][j] += dp[i - 1][i - c + j] / m;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%.2lf%% ", dp[n][i] * 100.0);
    }
    return 0;
}