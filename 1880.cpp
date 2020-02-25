#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int d[101], dpmax[210][210], dpmin[210][210], sum[210];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
        sum[i] += sum[i - 1] + d[i];
    }
    for (int i = 1; i <= n; i++)
    {
        sum[i + n] = sum[i + n - 1] + d[i];
    }
    for (int len = 1; len < n; len++)
    {
        for (int i = 1, j = i + len; (j < 2 * n) && (i < n + n); i++, j = i + len)
        {
            dpmin[i][j] = INT32_MAX;
            for (int k = i; k < j; k++)
            {
                dpmax[i][j] = max(dpmax[i][j], dpmax[i][k] + dpmax[k + 1][j] + sum[j] - sum[i - 1]);
                dpmin[i][j] = min(dpmin[i][j], dpmin[i][k] + dpmin[k + 1][j] + sum[j] - sum[i - 1]);
            }
        }
    }

    int ansMax = 0, ansMin = INT32_MAX;
    for (int i = 1; i <= n; i++)
    {
        ansMax = max(ansMax, dpmax[i][i + n - 1]);
        ansMin = min(ansMin, dpmin[i][i + n - 1]);
    }
    cout << ansMin << endl
         << ansMax;
    return 0;
}