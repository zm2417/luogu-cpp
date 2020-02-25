#include <iostream>
using namespace std;

int n, m, r, c;
int d[20][20], selectH[20], dp[20][20];

int w[20], v[20][20];

int ans = INT32_MAX;

void dps()
{
    // for (int k = 1; k <= n; k++)
    //     cout << selectH[k] << ' ';
    // cout << endl;

    for (int i = 1; i <= m; i++)
        for (int j = i + 1; j <= m; j++)
        {
            v[i][j] = 0;
            for (int k = 1; k <= n; k++)
            {
                if (selectH[k] == 1)
                    v[i][j] += abs(d[k][i] - d[k][j]);
            }
        }

    int pre = -1;
    for (int i = 1; i <= m; i++)
    {
        w[i] = 0;
        for (int k = 1; k <= n; k++)
        {
            if (selectH[k] == 1)
            {
                if (pre != -1)
                    w[i] += abs(d[k][i] - d[pre][i]);
                pre = k;
            }
        }
        pre = -1;
        // cout << "w " << w[i] << endl;
    }

    // for (int i = 1; i <= m; i++)
    // {
    //     // for (int j = 1; j <= n; j++)
    //     cout << w[i] << ' ';
    //     // cout << endl;
    // }

    for (int i = 0; i < 20; i++)
        for (int j = 0; j < 20; j++)
            dp[i][j] = 0x3f3f3f3f;

    dp[0][0] = 0;
    for (int i = 1; i <= c; i++)
    {
        for (int j = i; j <= m; j++)
        {
            for (int k = 0; k < j; k++)
            {
                dp[i][j] = min(dp[i][j], dp[i - 1][k] + v[k][j] + w[j]);
            }
        }
    }

    // cout << endl;
    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j <= m; j++)
    //         cout << dp[i][j] << ' ';
    //     cout << endl;
    // }

    for (int i = c; i <= m; i++)
    {
        // cout << "dp: " << dp[c][i] << endl;
        ans = min(ans, dp[c][i]);
    }
}

// 枚举行
void dfs(int x, int y)
{
    if (y >= r)
    {
        dps();
        return;
    }

    for (int i = x; i <= n; i++)
    {
        selectH[i] = 1;
        dfs(i + 1, y + 1);
        selectH[i] = 0;
    }
}

int main()
{
    cin >> n >> m >> r >> c;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> d[i][j];

    // for (int i = 1; i <= n; i++)
    //     for (int j = 1; j <= m; j++)
    //         for (int k = j + 1; k <= m; k++)
    //             w[i][j][k] = abs(d[i][j] - d[i][k]);

    dfs(1, 0);
    cout << ans;
    return 0;
}