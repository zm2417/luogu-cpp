#include <iostream>
using namespace std;

// gcd(a,b)=gcd(b, a mod b );
long long gcd(long long a, long long b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    int n, k;
    cin >> n >> k;
    // long long x = gcd(n, k);
    cout << n / k;
    return 0;
}