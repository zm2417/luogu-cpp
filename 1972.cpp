#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cctype>
#define ll long long
#define gc() getchar()
using namespace std;

const int maxInf = 1000010;
int n, m, d[maxInf];
int has[maxInf];
int ans[maxInf];
int sum[maxInf]; // 树状数组

inline ll read()
{
    ll a = 0;
    int f = 0;
    char p = gc();
    while (!isdigit(p))
    {
        f |= p == '-';
        p = gc();
    }
    while (isdigit(p))
    {
        a = (a << 3) + (a << 1) + (p ^ 48);
        p = gc();
    }
    return f ? -a : a;
}
void write(ll a)
{
    if (a > 9)
        write(a / 10);
    putchar(a % 10 + '0');
}

struct Tree
{
    int l, r, num;
} tree[maxInf];

inline bool comp(Tree t1, Tree t2)
{
    return t1.r < t2.r;
}

inline int lowbit(int x)
{
    return x & (-x);
}
inline void update(int x, int k)
{
    while (x <= n)
    {
        sum[x] += k;
        x += lowbit(x);
    }
}
inline int query(int x)
{
    int t = 0;
    while (x >= 1)
    {
        t += sum[x];
        x -= lowbit(x);
    }
    return t;
}

// 离线+树状数组
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0); //针对iostream的小优化，帮助卡常
    n = read();
    for (int i = 1; i <= n; i++)
        d[i] = read();
    m = read();
    for (int i = 1; i <= m; i++)
    {
        tree[i].l = read();
        tree[i].r = read();
        tree[i].num = i;
    }
    sort(tree + 1, tree + m + 1, comp);
    for (int i = 1; i <= m; i++)
    {
        for (int j = tree[i - 1].r + 1; j <= tree[i].r; j++)
        {
            if (has[d[j]])
            {
                update(has[d[j]], -1);
            }
            has[d[j]] = j;
            update(j, 1);
        }
        ans[tree[i].num] = query(tree[i].r) - query(tree[i].l - 1);
    }
    for (int i = 1; i <= m; i++)
        write(ans[i]), putchar('\n');
    return 0;
}