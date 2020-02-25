#include <iostream>
#include <algorithm>
using namespace std;

const int maxInf = 200005;
int m, n;
int tree[maxInf << 2], u[maxInf], s[maxInf], cnt = 1;

struct A
{
    long long v;
    int id;
} a[maxInf];

bool comp(A a1, A a2)
{
    return a1.v < a2.v;
}

void update(int index, int l, int r, int p)
{
    if (l == r && l == p)
    {
        tree[index]++;
        return;
    }
    tree[index]++;
    int mid = (l + r) / 2;
    if (mid >= p)
        update(index * 2, l, mid, p);
    else
    {
        update(index * 2 + 1, mid + 1, r, p);
    }
    tree[index] = tree[index * 2] + tree[index * 2 + 1];
}

int query(int index, int l, int r, int p)
{
    if (l == r)
        return l;
    int mid = (l + r) / 2;
    if (tree[index * 2] >= p)
        return query(index * 2, l, mid, p);
    else
    {
        return query(index * 2 + 1, mid + 1, r, p - tree[index * 2]);
    }
}

// 离散化 + 权值线段树
int main()
{
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i].v;
        a[i].id = i;
    }
    for (int i = 1; i <= n; i++)
        cin >> u[i];
    sort(a + 1, a + m + 1, comp);
    for (int i = 1; i <= m; i++)
        s[a[i].id] = i;
    for (int i = 1; i <= m; i++)
    {
        update(1, 1, m, s[i]);
        while (i == u[cnt])
        {
            cout << a[query(1, 1, m, cnt)].v << endl;
            cnt++;
        }
    }
    return 0;
}