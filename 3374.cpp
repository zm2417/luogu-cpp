#include <iostream>
using namespace std;

int n, m, d[500005];

int lowbit(int x)
{
    return x & (-x);
}

void add(int x, int k)
{
    while (x <= n)
    {
        d[x] += k;
        x += lowbit(x);
    }
}

int getSum(int x)
{
    int res = 0;
    while (x > 0)
    {
        res += d[x];
        x -= lowbit(x);
    }
    return res;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int j;
        cin >> j;
        add(i, j);
    }
    for (int i = 0; i < m; i++)
    {
        int p, x, y;
        cin >> p >> x >> y;
        if (p == 1)
        {
            add(x, y);
        }
        else
        {
            cout << getSum(y) - getSum(x - 1) << endl;
        }
    }
}