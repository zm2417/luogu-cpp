#include <cstdio>
#include <iostream>
using namespace std;
int t[21][21][21];

void init()
{
    for (int i = 0; i < 21; i++)
    {
        for (int j = 0; j < 21; j++)
        {
            for (int k = 0; k < 21; k++)
            {
                t[i][j][k] = 0;
            }
        }
    }
}

long w(long long a, long long b, long long c)
{
    int res = 0;
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;
    else if (a > 20 || b > 20 || c > 20)
    {
        if (t[20][20][20] != 0)
            return t[20][20][20];
        res = w(20, 20, 20);
        t[20][20][20] = res;
        return res;
    }
    if (t[a][b][c] != 0)
    {
        return t[a][b][c];
    }
    else if (a < b && b < c)
    {
        res = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    }
    else
    {
        res = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
    }
    t[a][b][c] = res;
    return res;
}

int main()
{
    init();
    while (true)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1)
            break;
        long res = w(a, b, c);
        printf("w(%lld, %lld, %lld) = %ld\n", a, b, c, res);
    }
    return 0;
}