#include <iostream>
using namespace std;

int R, C, d[100][100], dp[100][100], f[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool check(int i, int j)
{
    if (i >= 0 && i < R && j >= 0 && j < C)
        return true;
    return false;
}

int dfs(int i, int j)
{
    if (dp[i][j] != -1)
        return dp[i][j];
    int maxSum = 0;
    for (int k = 0; k < 4; k++)
    {
        if (check(i + f[k][0], j + f[k][1]) && d[i][j] > d[i + f[k][0]][j + f[k][1]])
        {
            int t = dfs(i + f[k][0], j + f[k][1]);
            maxSum = max(maxSum, t + 1);
            dp[i + f[k][0]][j + f[k][1]] = t;
        }
    }
    return maxSum;
}

int main()
{
    cin >> R >> C;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
        {
            cin >> d[i][j];
            dp[i][j] = -1;
        }
    int maxSum = 0;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
        {
            maxSum = max(maxSum, dfs(i, j));
        }
    cout << maxSum+1;
    return 0;
}