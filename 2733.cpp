#include <iostream>
#include <string>
using namespace std;

int n, d[260][260];
int dp[260][260];

int main()
{
    cin >> n;
    string ts;
    for (int i = 1; i <= n; i++)
    {
        cin >> ts;
        for (int j = 1; j <= n; j++)
            d[i][j] = ts[j - 1] - '0';
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (d[i][j] == 1)
                dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
    for (int l = 2; l <= n; l++)
    {
        int num = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (dp[i][j] >= l)
                    num++;
        if (num > 0)
            cout << l << ' ' << num << endl;
    }
    return 0;
}