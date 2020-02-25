#include <iostream>
using namespace std;

int main()
{
    long long n, m;
    cin >> n >> m;
    int d[n + 1] = {0};

    int l = 1, r = n;
    for (int i = 1; i <= n; i++)
    {
        long long t = (n - i) * (n - i - 1) / 2;
        if (t >= m)
            d[l++] = i;
        else
        {
            d[r--] = i;
            m -= (r - l + 1);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << d[i] << ' ';
    }
    return 0;
}