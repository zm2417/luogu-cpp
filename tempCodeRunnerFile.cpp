/**
 * 洛谷cpp算法
 * 
 * @author: zhangMeng
 * @date: 2020-03-10 
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 300005;
int n, m;
// int d[MAXN];
vector<int> pos[MAXN], q1[MAXN], q2[MAXN];
int ans[MAXN];

struct Node
{
    int ai, p;
} d[MAXN];

bool comp(Node n1, Node n2)
{
    return n1.ai < n2.ai;
}

void add(int i, int j)
{
    pos[min(i, j)].push_back(max(i, j));
}

int tree[MAXN];
int lowbit(int x)
{
    return x & (-x);
}
void modify(int x)
{
    while (x <= n)
    {
        tree[x]++;
        x += lowbit(x);
    }
}
int query(int x)
{
    int ret = 0;
    while (x >= 1)
    {
        ret += tree[x];
        x -= lowbit(x);
    }
    return ret;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i].ai;
        d[i].p = i;
    }
    sort(d + 1, d + 1 + n, comp);
    // 因为ai互不相同，那么满足条件的ay最多只有2个，我们可以预处理出所有好的配对。
    // 将节点对应的最小值记录
    for (int i = 1; i <= n; i++)
    {
        int t = INT16_MAX;
        int a = d[i].ai;
        if (i != 1)
            t = min(t, a - d[i - 1].ai);
        if (i != n)
            t = min(t, d[i + 1].ai - a);
        if (i != 1 && t == a - d[i - 1].ai)
            add(d[i].p, d[i - 1].p);
        if (i != n && t == d[i + 1].ai - a)
            add(d[i].p, d[i + 1].p);
    }
    for (int i = 1; i <= m; i++)
    {
        int l, r;
        cin >> l >> r;
        q1[l].push_back(r);
        q2[l].push_back(i);
    }
    // for (int j = 0; j < pos[1].size(); j++)
    // {
    //     cout << pos[1][j] << ' ';
    // }
    // cout << endl;
    for (int i = n; i > 0; i--)
    {
        for (int j = 0; j < pos[i].size(); j++)
        {
            modify(pos[i][j]);
        }
        for (int j = 0; j < q1[i].size(); j++)
        {
            ans[q2[i][j]] = query(q1[i][j]);
        }
        // cout << i << endl;
        // for (int i = 1; i <= n; i++)
        //     cout << tree[i] << ' ';
        // cout << endl;
    }
    long long sum = 0;
    for (int i = 1; i <= m; i++)
        sum += 1ll * ans[i] * i;
    cout << sum << endl;
    return 0;
}
