#include <iostream>
#include <string>
using namespace std;

int rule[5][5] = {{5, -1, -2, -1, -3},
                  {-1, 5, -3, -2, -4},
                  {-2, -3, 5, -2, -2},
                  {-1, -2, -2, 5, -1},
                  {-3, -4, -2, -1, INT32_MIN}};
int dp[101][101];

int getIndex(char c)
{
    if (c == 'A')
        return 0;
    else if (c == 'C')
        return 1;
    else if (c == 'G')
        return 2;
    else if (c == 'T')
        return 3;
    else
        return 4;
}

int main()
{
    int n1, n2;
    string s1, s2;
    cin >> n1 >> s1 >> n2 >> s2;
    dp[n1][n2] = 0;
    for (int i = n1 - 1; i >= 0; i--)
        dp[i][n2] = rule[getIndex(s1[i])][4] + dp[i + 1][n2];
    for (int i = n2 - 1; i >= 0; i--)
        dp[n1][i] = rule[4][getIndex(s2[i])] + dp[n1][i + 1];
    
    // for (int i = 0; i <= n1; i++)
    // {
    //     for (int j = 0; j <= n2; j++)
    //         cout << dp[i][j] << ' ';
    //     cout << endl;
    // }

    for (int i = n1 - 1; i >= 0; i--)
    {
        for (int j = n2 - 1; j >= 0; j--)
        {
            int x = dp[i + 1][j + 1] + rule[getIndex(s1[i])][getIndex(s2[j])];
            int y = dp[i][j + 1] + rule[getIndex(s2[j])][4];
            int z = dp[i + 1][j] + rule[4][getIndex(s1[i])];
            dp[i][j] = max(max(x, y), z);
        }
    }

    // for (int i = 0; i < n1; i++)
    // {
    //     for (int j = 0; j < n2; j++)
    //         cout << dp[i][j] << ' ';
    //     cout << endl;
    // }
    cout << dp[0][0];
    return 0;
}