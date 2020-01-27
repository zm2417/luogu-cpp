#include <iostream>
using namespace std;

inline long long gcd(long long x, long long y)
{
    return x % y == 0 ? y : gcd(y, x % y);
}
long long n, m, p;

// pick定理

int main()
{
    cin >> n >> m >> p;
    long long s = p * m / 2;
    long long cnt = (gcd(n, m) + gcd(abs(n - p), m) + p) / 2;
    long long ans = s - cnt + 1;
    cout << ans << endl;
    return 0;
}