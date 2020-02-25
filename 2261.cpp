#include <iostream>
using namespace std;

long long n, k;

int main()
{
    cin >> n >> k;
    long long l, r;
    long long ans = n * k;
    for (l = 1; l <= n; l = r + 1)
    {
        if (k / l != 0)
        {
            r = min((k / (k / l)), n);
        }
        else
        {
            r = n;
        }
        ans -= (k / l) * (r - l + 1) * (l + r) / 2;
    }
    cout << ans << endl;
    return 0;
}