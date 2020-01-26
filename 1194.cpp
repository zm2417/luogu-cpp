#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    int i, j, v;
} node[250010];

bool comp(Node n1, Node n2)
{
    return n1.v < n2.v;
}

//并查集
int parent[600];
void init()
{
    for (int i = 0; i < 600; i++)
        parent[i] = i;
}
int findParent(int x)
{
    if (parent[x] != x)
        parent[x] = findParent(parent[x]);
    return parent[x];
}
void unionSet(int x, int y)
{
    int xP = findParent(x);
    int yP = findParent(y);
    if (xP != yP)
        parent[xP] = yP;
}

int main()
{
    int a, b;
    cin >> a >> b;
    int cnt = 0;
    for (int i = 1; i <= b; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            int x;
            cin >> x;
            if (i < j)
            {
                node[cnt].i = i;
                node[cnt].j = j;
                node[cnt].v = x == 0 ? a : x;
                cnt++;
            }
        }
    }
    sort(node, node + cnt, comp);
    int ans = a;
    init();
    for (int i = 0; i < cnt; i++)
    {
        int x = findParent(node[i].i);
        int y = findParent(node[i].j);
        if (x != y)
        {
            ans += node[i].v > a ? a : node[i].v;
            unionSet(x, y);
        }
    }
    cout << ans << endl;
    return 0;
}