#include <iostream>
#include <algorithm>
using namespace std;

struct node
{
    int l, r;
    friend bool operator<(const node &a, const node &b)
    {
        return a.l * a.r < b.r * b.l;
    }
} d[1001];

struct gaojd
{
    int d[5050] = {0};
    int len = 1;

    gaojd()
    {
        d[0] = 1;
    }

    friend gaojd operator*(const gaojd a, int j)
    {
        gaojd t;
        t.d[0] = 0;
        t.len = a.len + 10;
        for (int i = 0; i < t.len - 1; i++)
        {
            t.d[i] += a.d[i] * j;
            t.d[i + 1] = t.d[i] / 10;
            t.d[i] %= 10;
        }
        while (t.len >= 0 && t.d[t.len - 1] == 0)
        {
            t.len--;
        }
        return t;
    }

    friend gaojd operator/(const gaojd a, int j)
    {
        gaojd t;
        t.len = a.len;
        int x = 0;
        for (int i = t.len - 1; i >= 0; i--)
        {
            t.d[i] = (10 * x + a.d[i]) / j;
            x = (10 * x + a.d[i]) % j;
        }
        while (t.len >= 0 && t.d[t.len - 1] == 0)
        {
            t.len--;
        }
        return t;
    }

    friend bool operator<(const gaojd a, const gaojd b)
    {
        if (a.len > b.len)
            return false;
        if (a.len < b.len)
            return true;
        for (int i = a.len - 1; i >= 0; i--)
        {
            if (a.d[i] < b.d[i])
            {
                return true;
            }
            else if (a.d[i] > b.d[i])
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        cin >> d[i].l >> d[i].r;
    }
    sort(d+1, d + n+1);
    gaojd sm, ans;
    for (int i = 0; i <= n-1; i++)
    {
        sm = sm * d[i].l;
        ans = max(ans, sm / d[i + 1].r);
    }
    for (int i = ans.len-1; i >= 0; i--)
    {
        cout << ans.d[i];
    }
    return 0;
}