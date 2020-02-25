#include <iostream>
using namespace std;

const int maxInf = 100005;
int n, m, p;
int d[maxInf];

struct Tree
{
    int l, r;
    long long num;
    long long add;
    long long multiply = 1;
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
    tree[index].num = (tree[index * 2].num + tree[index * 2 + 1].num) % p;
}

// 子区间的lazyP = 子区间lazyP * 父亲lazyM + 父亲lazyP。
// 子区间的lazyM = 子区间lazyM * 父亲lazyM
void pushDown(int index)
{
    if (tree[index].add != 0 || tree[index].multiply != 1)
    {
        tree[index * 2].num = (tree[index * 2].num * tree[index].multiply + tree[index].add * (tree[index * 2].r - tree[index * 2].l + 1)) % p;
        tree[index * 2 + 1].num = (tree[index * 2 + 1].num * tree[index].multiply + tree[index].add * (tree[index * 2 + 1].r - tree[index * 2 + 1].l + 1)) % p;

        tree[index * 2].multiply = (tree[index].multiply * tree[index * 2].multiply) % p;
        tree[index * 2 + 1].multiply = (tree[index].multiply * tree[index * 2 + 1].multiply) % p;

        tree[index * 2].add = (tree[index].multiply * tree[index * 2].add + tree[index].add) % p;
        tree[index * 2 + 1].add = (tree[index].multiply * tree[index * 2 + 1].add + tree[index].add) % p;

        tree[index].multiply = 1;
        tree[index].add = 0;
    }
}

void mul(int index, int l, int r, int k)
{
    if (l > tree[index].r || r < tree[index].l)
        return;
    if (tree[index].l >= l && tree[index].r <= r)
    {
        tree[index].num *= k;
        tree[index].add *= k;
        tree[index].multiply *= k;
        tree[index].num %= p;
        tree[index].add %= p;
        tree[index].multiply %= p;
        return;
    }
    pushDown(index);
    mul(index * 2, l, r, k);
    mul(index * 2 + 1, l, r, k);
    tree[index].num = (tree[index * 2].num + tree[index * 2 + 1].num) % p;
}

void add(int index, int l, int r, int k)
{
    if (l > tree[index].r || r < tree[index].l)
        return;
    if (tree[index].l >= l && tree[index].r <= r)
    {
        tree[index].num += (tree[index].r - tree[index].l + 1) * k;
        tree[index].num %= p;
        tree[index].add += k;
        tree[index].add %= p;
        return;
    }
    pushDown(index);
    add(index * 2, l, r, k);
    add(index * 2 + 1, l, r, k);
    tree[index].num = (tree[index * 2].num + tree[index * 2 + 1].num) % p;
}

long long query(int index, int l, int r)
{
    if (l > tree[index].r || r < tree[index].l)
        return 0;
    if (tree[index].l >= l && tree[index].r <= r)
    {
        return tree[index].num;
    }
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
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++)
        cin >> d[i];
    build(1, 1, n);
    // printTree(1);
    for (int i = 0; i < m; i++)
    {
        int j, x, y, k;
        cin >> j >> x >> y;
        if (j == 1)
        {
            cin >> k;
            mul(1, x, y, k);
        }
        else if (j == 2)
        {
            cin >> k;
            add(1, x, y, k);
            // printTree(1);
        }
        else
        {
            cout << query(1, x, y) << endl;
        }
    }
}