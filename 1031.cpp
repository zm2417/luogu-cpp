#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, sum = 0;
    cin >> n;
    int d[n];
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
        sum += d[i];
    }
    int pj = sum / n;

    // sort(d, d + n, greater<int>());

    int ans = 0, cur = 0, p = 0;
    for (int i = 0; i < n; i++)
    {
        cur += d[i];
        p++;
        if(pj * p == cur)
        {
            ans += p -1;
            cur = 0;
            p = 0;
        }
    }
    cout << ans;

    return 0;
}