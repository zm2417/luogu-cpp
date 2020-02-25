#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long ans = 0;
    long temp = 1;
    long tempAns = 2;
    for (long long i = 1; i <= n; )
    {
        tempAns = i * 2;
        if(tempAns <= n)
            ans += i * temp;
        else
        {
            ans += (n-i) *temp;
        }
        i = tempAns;
        temp++;
    }
    cout << ans;
    return 0;
}