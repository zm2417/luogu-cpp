#include <iostream>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int d[n + 1] = {0};
    d[0] = 1;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (i + j <= n)
                d[i + j] += d[i] % 100003;
        }
    }
    cout << d[n] % 100003;
    return 0;
}