#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int w, n;
    cin >> w >> n;
    int d[n];
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
    }

    sort(d, d + n);

    int i = 0,j = n-1,ans = 0,cur = 0;
    while (i <= j)
    {
        while (i <= j && d[j] + cur <= w)
        {
            cur += d[j--];
        }
        while (i <= j && d[i] + cur <= w)
        {
            cur += d[i++];
        }
        ans++;
        cur = 0;
    }
    cout << ans;

    return 0;
}