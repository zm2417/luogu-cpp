#include <iostream>
using namespace std;

int n, m;
long long d[100010], ans;

struct Tree
{
    // 节点代表区间[l,r]之间的信息(如最大值,总和)
    int l, r;
    // num代表区间的信息
    long long num;
    // 延时加载
    long long add;
} tree[400010];

// 线段树的构造
void build(int index, int left, int right)
{
    tree[index].l = left;
    tree[index].r = right;
    if (left == right)
    {
        tree[index].num = d[left];
        return;
    }
    int mid = (left + right) / 2;
    build(index * 2, left, mid);
    build(index * 2 + 1, mid + 1, right);
    tree[index].num = tree[index * 2].num + tree[index * 2 + 1].num;
}

void pushDown(int p)
{
    if (tree[p].add)
    {
        tree[p * 2].num += (tree[p * 2].r - tree[p * 2].l + 1) * tree[p].add;
        tree[p * 2 + 1].num += (tree[p * 2 + 1].r - tree[p * 2 + 1].l + 1) * tree[p].add;
        tree[p * 2].add += tree[p].add;
        tree[p * 2 + 1].add += tree[p].add;
        tree[p].add = 0;
    }
}

void change(int index, int l, int r, int k)
{
    if (tree[index].l >= l && tree[index].r <= r)
    {
        tree[index].num += k * (tree[index].r - tree[index].l + 1);
        tree[index].add += k;
        return;
    }
    pushDown(index);
    if (l <= tree[index * 2].r)
        change(index * 2, l, r, k);
    if (r >= tree[index * 2 + 1].l)
        change(index * 2 + 1, l, r, k);
    tree[index].num = tree[index * 2].num + tree[index * 2 + 1].num;
}

void getSum(int index, int l, int r)
{
    if (tree[index].l >= l && tree[index].r <= r)
    {
        ans += tree[index].num;
        // cout << "tree: " << tree[index].num << ' ' << tree[index].l << ' ' << tree[index].r << ' ';
        return;
    }
    pushDown(index);
    if (l <= tree[index * 2].r)
        getSum(index * 2, l, r);
    if (r >= tree[index * 2 + 1].l)
        getSum(index * 2 + 1, l, r);
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
    }
    build(1, 1, n);
    for (int i = 0; i < m; i++)
    {
        int o, x, y;
        cin >> o >> x >> y;
        if (o == 1)
        {
            int k;
            cin >> k;
            change(1, x, y, k);
        }
        else
        {
            ans = 0;
            getSum(1, x, y);
            cout << ans << endl;
        }
    }
}