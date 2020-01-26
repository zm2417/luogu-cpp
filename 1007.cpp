#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int l, n;
    cin >> l >> n;
    int d[n];
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
    }
    sort(d, d + n);
    int minTime = 0;
    int maxTime = 0;
    for (int i = 0; i < n; i++)
    {
        int x = min(d[i], l - d[i] + 1);
        minTime = max(minTime, x);
        maxTime = max(maxTime,max(d[i],l-d[i]+1));
    }
    cout << minTime << ' ' << maxTime;
}