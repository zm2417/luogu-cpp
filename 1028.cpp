#include <iostream>
using namespace std;

int n,ans,d[1001];

int main()
{
    cin >> n;
    d[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        d[i] = d[i-1];
        if(i % 2 == 0)
            d[i] += d[i/2];
    }
    
    cout << d[n];
    return 0;
}