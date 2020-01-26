#include <iostream>
using namespace std;

long int t1(long int b, long int p, long int k)
{
    if (p == 1)
        return b % k;
    long int i = t1(b, p / 2, k) % k;
    if (p % 2 == 0)
        return (i * i) % k;
    else
    {
        return (i * i * b) % k;
    }
}

int main()
{
    long int b, p, k;
    cin >> b >> p >> k;

    if(p == 0){
        cout << b << "^" << p << " mod " << k << "=" << 1 % k;
    }else
    {
        long int ret1 = t1(b, p, k);
        cout << b << "^" << p << " mod " << k << "=" << ret1;
    }
}