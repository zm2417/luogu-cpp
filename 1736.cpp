#include <iostream>
using namespace std;

int dpl[2510][2510][3];

int main()
{
    int n, m;
    cin >> n >> m;

    int d[n + 1][m + 1];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> d[i][j];

    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (d[i][j] == 0)
            {
                dpl[i][j][0] = 0, dpl[i][j][1] = dpl[i - 1][j][1] + 1, dpl[i][j][2] = dpl[i][j - 1][2] + 1;
            }
            else
            {
                int x = min(dpl[i - 1][j - 1][0], min(dpl[i - 1][j][1], dpl[i][j - 1][2])) + 1;
                dpl[i][j][0] = x, dpl[i][j][1] = 0, dpl[i][j][2] = 0;
            }
            ans = max(ans, dpl[i][j][0]);
        }

    for (int i = 1; i <= n; i++)
        for (int j = m; j > 0; j--)
        {
            if (d[i][j] == 0)
            {
                dpl[i][j][0] = 0, dpl[i][j][1] = dpl[i - 1][j][1] + 1, dpl[i][j][2] = dpl[i][j + 1][2] + 1;
            }
            else
            {
                int x = min(dpl[i - 1][j + 1][0], min(dpl[i - 1][j][1], dpl[i][j + 1][2])) + 1;
                dpl[i][j][0] = x, dpl[i][j][1] = 0, dpl[i][j][2] = 0;
            }
            ans = max(ans, dpl[i][j][0]);
        }

    cout << ans;
    return 0;
}