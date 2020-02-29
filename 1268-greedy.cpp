#include <iostream>
using namespace std;

int n;
int d[30][30];
int ans;

int main()
{
    cin >> n;
    while (n != 0)
    {
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++)
                cin >> d[i][j];
        ans = d[1][2];
        for (int i = 3; i <= n; i++)
        {
            int temp = INT16_MAX;
            for (int j = 2; j < i; j++)
            {
                temp = min(temp, (d[1][i] + d[j][i] - d[1][j]) / 2);
            }
            ans += temp;
        }
        cout << ans << endl;
        cin >> n;
    }
    return 0;
}