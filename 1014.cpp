#include <iostream>
#include <cstdio>
using namespace std;
int n, k = 1, cnt;
int main()
{
    cin >> n;
    while (1)
    {
        if (n - k >= 0)
            n -= k, cnt++, k++; //cnt表示第几层。
        else
            break;
    }
    if (!n)
        cout << 1 << '/' << cnt;
    else if ((cnt + 1) & 1)
        cout << k - n + 1 << '/' << n;
    else
        cout << n << '/' << k - n + 1;
    return 0;
}