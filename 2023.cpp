#include <iostream>
using namespace std;

const int maxInf = 100005;
int n, m;
long long p;
long long d[maxInf];

struct Tree
{
    int l, r;
    long long num;
    long long add = 0;
    long long mul = 1;
} tree[4 * maxInf];

void build(int index, int l, int r)
{
    tree[index].l = l;
    tree[index].r = r;
    if (l == r)
    {
        tree[index].num = d[l];
        return;
    }
    int mid = (l + r) / 2;
    build(index * 2, l, mid);
    build(index * 2 + 1, mid + 1, r);
    tree[index].num = tree[index * 2].num + tree[index * 2 + 1].num;
}

void pushDown(int index)
{
    if (tree[index].add != 0 || tree[index].mul != 1)
    {
        tree[index * 2].num = (tree[index * 2].num * tree[index].mul + tree[index].add * (tree[index * 2].r - tree[index * 2].l + 1)) % p;
        tree[index * 2 + 1].num = (tree[index * 2 + 1].num * tree[index].mul + tree[index].add * (tree[index * 2 + 1].r - tree[index * 2 + 1].l + 1)) % p;

        tree[index * 2].mul = (tree[index].mul * tree[index * 2].mul) % p;
        tree[index * 2 + 1].mul = (tree[index].mul * tree[index * 2 + 1].mul) % p;

        tree[index * 2].add = (tree[index].mul * tree[index * 2].add + tree[index].add) % p;
        tree[index * 2 + 1].add = (tree[index].mul * tree[index * 2 + 1].add + tree[index].add) % p;

        tree[index].add = 0;
        tree[index].mul = 1;
    }
}

void add(int index, int l, int r, long long k)
{
    if (l > tree[index].r || r < tree[index].l)
        return;
    if (tree[index].l >= l && tree[index].r <= r)
    {
        tree[index].num = (tree[index].num + (tree[index].r - tree[index].l + 1) * k) % p;
        tree[index].add = (tree[index].add + k) % p;
        return;
    }
    pushDown(index);
    add(index * 2, l, r, k);
    add(index * 2 + 1, l, r, k);
    tree[index].num = (tree[index * 2].num + tree[index * 2 + 1].num) % p;
}

void mul(int index, int l, int r, long long k)
{
    if (l > tree[index].r || r < tree[index].l)
        return;
    if (tree[index].l >= l && tree[index].r <= r)
    {
        tree[index].num = (tree[index].num * k) % p;
        tree[index].add = (tree[index].add * k) % p;
        tree[index].mul = (tree[index].mul * k) % p;
        return;
    }
    pushDown(index);
    mul(index * 2, l, r, k);
    mul(index * 2 + 1, l, r, k);
    tree[index].num = (tree[index * 2].num + tree[index * 2 + 1].num) % p;
}

long long query(int index, int l, int r)
{
    if (l > tree[index].r || r < tree[index].l)
        return 0;
    if (tree[index].l >= l && tree[index].r <= r)
        return tree[index].num;
    pushDown(index);
    return (query(index * 2, l, r) + query(index * 2 + 1, l, r)) % p;
}

void printTree(int index)
{
    cout << "tree " << tree[index].l << ' ' << tree[index].r << ' ' << tree[index].num << endl;
    if (tree[index].l == tree[index].r)
    {
        return;
    }
    printTree(index * 2);
    printTree(index * 2 + 1);
}

int main()
{
    cin >> n >> p;
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
    }
    build(1, 1, n);

    cin >> m;
    int j, t, g;
    long long c;
    for (int i = 0; i < m; i++)
    {
        cin >> j >> t >> g;
        if (j == 1)
        {
            cin >> c;
            mul(1, t, g, c);
        }
        else if (j == 2)
        {
            cin >> c;
            add(1, t, g, c);
        }
        else
        {
            cout << query(1, t, g) << endl;
            // printTree(1);
        }
    }
    return 0;
}