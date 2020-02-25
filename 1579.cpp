#include <iostream>
using namespace std;

bool isPrime(int x)
{
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 2; i < n; i++)
        for (int j = i; j < n; j++)
        {
            int k = n - i - j;
            if (k >= 2 && isPrime(k) && isPrime(i) && isPrime(j))
            {
                cout << i << ' ' << j << ' ' << k;
                return 0;
            }
        }
}