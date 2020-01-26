#include <iostream>
using namespace std;

int gcd(int x, int y)
{
    if (y == 0)
        return x;
    return gcd(y, x % y);
}

int main()
{
    int x, y;
    cin >> x >> y;
    long long a = x * y;
    long long ans = 0;
    for (int i = x; i <= y; i = i + x)
    {
        if (a % i == 0 && a/i >= i && gcd(i,a/i) == x)
        {
            ans++;
        }
    }
    cout << ans * 2 << endl;
    return 0;
}