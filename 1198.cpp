#include <iostream>
using namespace std;

const int maxInf = 200005;
int M;
long long MOD;
long long d[maxInf];
long long t = 0;
int s;

struct Tree
{
    int l, r;
    long long maxNum;
} tree[4 * maxInf];

long long max(long long a, long long b)
{
    return a > b ? a : b;
}

void build(int index, int l, int r)
{
    tree[index].l = l;
    tree[index].r = r;
    if (l == r)
        return;
    int mid = (l + r) / 2;
    build(index * 2, l, mid);
    build(index * 2 + 1, mid + 1, r);
}

long long query(int index, int l, int r)
{
    // if (index >= 4 * maxInf)
    // {
    //     cout << "test" << endl;
    //     return -1e18;
    // }
    if (tree[index].l > r || tree[index].r < l)
        return -1e18;
    if (tree[index].l >= l && tree[index].r <= r)
        return tree[index].maxNum;
    long long ans = -1e18;
    if (tree[index * 2].r >= l)
        ans = max(ans, query(index * 2, l, r));
    if (tree[index * 2 + 1].l <= r)
        ans = max(ans, query(index * 2 + 1, l, r));
    return ans;
}

void add(int index, int p, long long k)
{
    if (tree[index].l > p || tree[index].r < p)
        return;
    if (tree[index].l == tree[index].r)
    {
        tree[index].maxNum = k;
        return;
    }
    if (tree[index].l <= p && tree[index].r >= p)
        tree[index].maxNum = max(tree[index].maxNum, k);
    add(index * 2, p, k);
    add(index * 2 + 1, p, k);
}

int main()
{
    cin >> M >> MOD;
    build(1, 1, maxInf);
    for (int i = 1; i <= M; i++)
    {
        char c;
        long long j;
        cin >> c >> j;
        if (c == 'Q')
        {
            if (j == 0)
                t = 0;
            else
                t = query(1, s - j + 1, s);
            cout << t << endl;
        }
        else
        {
            s++;
            add(1, s, (t + j) % MOD);
        }
    }
    return 0;
}