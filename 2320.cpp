#include <iostream>
using namespace std;

int d[600];

int main()
{
    int m;
    cin >> m;
    int k = 0;
    while (m)
    {
        d[++k] = (m + 1) / 2;
        m /= 2;
    }
    cout << k << endl;
    for (int i = k; i > 0; i--)
    {
        cout << d[i] << ' ';
    }
    return 0;
}