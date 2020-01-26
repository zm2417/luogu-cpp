#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
using namespace std;

int dpMax[120][120][10], dpMin[120][120][10];

int mod(int x)
{
    return (x % 10 + 10) % 10;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int sum[2 * n + 1] = {0};
    for (int i = 1; i <= n; i++)
    {
        cin >> sum[i];
        sum[i] += sum[i - 1];
    }
    for (int i = n + 1; i <= 2 * n; i++)
    {
        sum[i] = sum[i - n] + sum[n];
    }
    for (int i = 0; i <= 2 * n; i++)
    {
        for (int j = 0; j <= 2 * n; j++)
        {
            for (int k = 0; k <= m; k++)
            {
                dpMin[i][j][k] = 127;
            }
        }
    }
    // 初始化i到j不分割时的值
    for (int i = 1; i <= 2 * n; i++)
    {
        for (int j = i; j <= 2 * n; j++)
        {
            dpMax[i][j][1] = dpMin[i][j][1] = mod(sum[j] - sum[i - 1]);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 2 * n && i + j - 1 <= 2 * n; j++)
        {
            int k = i + j - 1;

            for (int l = 2; l <= m; l++)
            {
                for (int a = j + l - 1; a < k; a++)
                {
                    dpMax[j][k][l] = max(dpMax[j][k][l], dpMax[j][a][l - 1] * mod(sum[k] - sum[a]));
                    dpMin[j][k][l] = min(dpMin[j][k][l], dpMin[j][a][l - 1] * mod(sum[k] - sum[a]));
                }
            }
        }
    }
    int maxAns = 0, minAns = INT16_MAX;
    for (int i = 1; i <= n; i++)
    {
        maxAns = max(maxAns, dpMax[i][i + n - 1][m]);
        minAns = min(minAns, dpMin[i][i + n - 1][m]);
        // cout << dpMin[i][i + n - 1][m] << endl;
    }
    cout << minAns << endl
         << maxAns;
    return 0;
}