#include <iostream>
#include <algorithm>
using namespace std;

int n;
int d[505][505];
int ans;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            cin >> d[i][j];
            d[j][i] = d[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        sort(d[i] + 1, d[i] + 1 + n);
        ans = ans > d[i][n - 1] ? ans : d[i][n - 1];
    }
    cout << 1 << endl
         << ans << endl;
    return 0;
}