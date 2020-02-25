#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    int l, w;
} node[10000];

int f[5001];

bool comp(Node n1, Node n2)
{
    return n1.l == n2.l ? n1.w > n2.w : n1.l > n2.l;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> node[i].l >> node[i].w;
    }
    sort(node, node + n, comp);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (node[i].w > f[ans])
        {
            ans++;
            f[ans] = node[i].w;
        }
        else
        {
            int l = 0, r = ans;
            while (l <= r)
            {
                int mid = (l + r) / 2;
                if (f[mid] >= node[i].w)
                    r = mid - 1;
                else
                {
                    l = mid + 1;
                }
            }
            f[l] = node[i].w;
        }
    }
    cout << ans;
    return 0;
}