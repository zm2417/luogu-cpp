#include <iostream>
using namespace std;

int n, b, d;
int ans[70];
int m;

bool comp(int x, int y)
{
    int s = x ^ y;
    int p = 0;
    while (s)
    {
        if (s & 1)
        {
            p++;
        }
        s = s >> 1;
    }
    if (p >= d)
        return true;
    return false;
}

bool hm(int x)
{
    for (int i = 0; i <= m; i++)
    {
        if (!comp(x, ans[i]))
            return false;
    }
    return true;
}

int main()
{
    cin >> n >> b >> d;
    for (int i = 1; i < (1 << (b + 1)) && m < n - 1; i++)
    {
        if (hm(i))
            ans[++m] = i;
    }
    int j = 1;
    for (int i = 0; i < n; i++)
    {
        cout << ans[i];
        if (j % 10 == 0)
            cout << endl;
        else
        {
            cout << ' ';
        }
        j++;
    }
    return 0;
}