#include <iostream>
using namespace std;

long long dp[25][25];
void init(int x, int y)
{
    if (x >= 0 && y >= 0)
        dp[x][y] = -1;
}
void horse(int x, int y)
{
    dp[x][y] = -1;
    init(x - 1, y - 2);
    init(x - 2, y - 1);
    init(x + 1, y - 2);
    init(x + 2, y - 1);
    init(x - 1, y + 2);
    init(x - 2, y + 1);
    init(x + 1, y + 2);
    init(x + 2, y + 1);
}



int main()
{
    int b1, b2, m1, m2;
    cin >> b1 >> b2 >> m1 >> m2;
    dp[0][0] = 1;
    horse(m1, m2);
    for (int i = 0; i <= b1; i++)
    {
        for (int j = 0; j <= b2; j++)
        {
            if (dp[i][j] == 0)
            {
                if (i != 0 && dp[i - 1][j] != -1)
                    dp[i][j] += dp[i - 1][j];
                if (j != 0 && dp[i][j - 1] != -1)
                    dp[i][j] += dp[i][j - 1];
            }
        }
    }
    cout << dp[b1][b2];
    return 0;
}