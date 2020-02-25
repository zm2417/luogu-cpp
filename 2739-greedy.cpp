#include <iostream>
#include <queue>
#include <string>
#include <set>
using namespace std;

int n;
int d[17][17];
int cnt;

inline void check(int x)
{
    if (x % 20 == 0)
        cout << endl;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n + 1; i++)
    {
        if (i % 2 == 1)
        {
            for (int j = 0; j < i; j++)
                d[i][j] = n + i - j - j;
        }
        else
        {
            for (int j = 0; j < i; j++)
                d[i][j] = n - i + j + j + 2;
        }
    }
    for (int i = 2; i <= n + 1; ++i)
        for (int j = 0; j < i; ++j)
            printf("%d ", d[i][j]), check(++cnt);
    for (int i = n; i >= 1; --i)
        for (int j = 0; j < i; ++j)
            printf("%d ", d[i][j]), check(++cnt);
    return 0;
}