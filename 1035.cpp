#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    double i = 1;
    double d = 0.0;
    for (; d <= n; i++)
        d += 1 / i;
    cout << i - 1;
    return 0;
}