#include <iostream>
#include <algorithm>
using namespace std;
// long long n, d[500001], temp[500001], ans = 0;

// // 归并算法
// void merge(int i, int j)
// {
//     if (i >= j)
//     {
//         return;
//     }
//     else if (i + 1 == j)
//     {
//         if (d[i] > d[j])
//         {
//             ans++;
//             int t = d[i];
//             d[i] = d[j];
//             d[j] = t;
//         }
//         return;
//     }
//     int mid = (i + j) / 2;
//     merge(i, mid);
//     merge(mid + 1, j);
//     int pl = i, pr = mid + 1, t = 0;
//     while (pl <= mid && pr <= j)
//     {
//         if (d[pl] > d[pr])
//         {
//             temp[t++] = d[pr++];
//             ans += mid - pl + 1;
//         }
//         else
//         {
//             temp[t++] = d[pl++];
//         }
//     }
//     while (pl <= mid)
//     {
//         temp[t++] = d[pl++];
//     }
//     while (pr <= j)
//     {
//         temp[t++] = d[pr++];
//     }
//     for (int k = i; k <= j; k++)
//     {
//         d[k] = temp[k - i];
//     }
// }

// int main()
// {
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> d[i];
//     }
//     merge(0, n - 1);
//     cout << ans;
// }

//树状数组
long long ans;
const int m = 500001;
int n, r[m], tree[m];

struct Node
{
    int index, val;
};
Node node[m];

bool comp(Node n1, Node n2)
{
    if (n1.val == n2.val)
        return n1.index < n2.index;
    return n1.val < n2.val;
}

void add(int p)
{
    while (p <= n)
    {
        tree[p]++;
        p += p & -p;
    }
}

int sum(int p)
{
    int ret = 0;
    while (p > 0)
    {
        ret += tree[p];
        p -= p & -p;
    }
    return ret;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> node[i].val;
        node[i].index = i;
    }
    sort(node, node + n, comp);
    for (int i = 0; i < n; i++)
    {
        r[node[i].index] = i;
    }
    for (int i = 0; i < n; i++)
    {
        add(r[i] + 1);
        ans += i - sum(r[i] + 1) + 1;
    }
    cout << ans;
}