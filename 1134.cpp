#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long ans = 1;
    long long temp = 1;
    for (int i = 2; i <= n; i++)
    {
        ans = ans * i;
        while (ans % 10 == 0)
        {
            ans /= 10;
        }
        // temp *= i;
        ans = ans % 100000000;
        // cout << temp << ' ' << ans << endl;
    }
    cout << ans % 10 << endl;
    return 0;
}