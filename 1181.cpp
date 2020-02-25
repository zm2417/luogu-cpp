#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int d[n];
    int ans = 0, cur = 0;
    for (int i = 0; i < n; i++)
    {
        int j;
        cin >> j;
        if (cur + j <= m)
        {
            cur += j;
        }
        else
        {
            ans++;
            cur = j;
        }
    }
    ans++;
    cout << ans;
    return 0;
}