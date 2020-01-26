#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxInf = 15;
int n;
int ans;
int to[maxInf];
int con[maxInf];
bool tag[maxInf];

struct Node
{
    int x, y;
} node[maxInf];

bool comp(Node n1, Node n2)
{
    return n1.y < n2.y || (n1.y == n2.y && n1.x < n2.x);
}

bool cycle(int i)
{
    while (to[i])
    {
        if (tag[i])
            return 1;
        tag[i] = 1;
        i = con[to[i]];
    }
    return 0;
}

void dfs(int k)
{
    if (k > n)
    {
        bool ok = 0;
        for (int i = 1; i <= n && !ok; i++)
        {
            memset(tag, 0, sizeof(tag));
            ok |= cycle(i);
        }
        ans += ok;
        return;
    }
    if (con[k])
        dfs(k + 1);
    else
    {
        for (int i = k + 1; i <= n; i++)
        {
            if (!con[i])
            {
                con[i] = k, con[k] = i;
                dfs(k + 1);
                con[i] = 0, con[k] = 0;
            }
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> node[i].x >> node[i].y;
    }
    sort(node + 1, node + n + 1, comp);
    for (int i = 1; i <= n - 1; i++)
    {
        if (node[i].y == node[i + 1].y)
            to[i] = i + 1;
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}