#include <iostream>
#include <cstring>
using namespace std;

const int maxInf = 101;
int n;
int a[3], b[3];
int vis[maxInf][3];
int ans;

bool check(int i, int j)
{
    if (abs(j - i) <= 2 || abs(i + n - j) <= 2 || abs(j + n - i) <= 2)
        return true;
    return false;
}

int main()
{
    cin >> n;
    cin >> a[0] >> a[1] >> a[2] >> b[0] >> b[1] >> b[2];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                if (check(i, a[0]) && check(j, a[1]) && check(k, a[2]))
                {
                    ans++;
                }
                else if (check(i, b[0]) && check(j, b[1]) && check(k, b[2]))
                {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}