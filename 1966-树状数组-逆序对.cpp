/**
 * 洛谷cpp算法
 * 
 * @author: zhangMeng
 * @date: 2020-03-10 
 */
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100005;
const int MOD = 99999997;
int n;
int d1[MAXN], d2[MAXN];
int p1[MAXN], p2[MAXN];
int q[MAXN];
int tree[MAXN];
long long ans;

int lowbit(int x)
{
    return x & (-x);
}

void add(int x)
{
    while (x <= n)
    {
        tree[x]++;
        tree[x] %= MOD;
        x += lowbit(x);
    }
}

int sum(int x)
{
    int ret = 0;
    while (x > 0)
    {
        ret += tree[x];
        ret %= MOD;
        x -= lowbit(x);
    }
    return ret;
}

bool com1(int i, int j)
{
    return d1[i] < d1[j];
}
bool com2(int i, int j)
{
    return d2[i] < d2[j];
}

void print()
{
    // for (int i = 1; i <= n; i++)
    //     cout << p1[i] << ' ';
    // cout << endl;
    // for (int i = 1; i <= n; i++)
    //     cout << p2[i] << ' ';
    // cout << endl;
    // for (int i = 1; i <= n; i++)
    //     cout << q[i] << ' ';
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> d1[i];
        p1[i] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> d2[i];
        p2[i] = i;
    }
    sort(p1 + 1, p1 + 1 + n, com1);
    sort(p2 + 1, p2 + 1 + n, com2);
    for (int i = 1; i <= n; i++)
        q[p1[i]] = p2[i];
    print();
    for (int i = n; i > 0; i--)
    {
        add(q[i]);
        ans = (ans + sum(q[i] - 1)) % MOD;
    }
    cout << ans << endl;
    return 0;
}
