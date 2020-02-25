#include <iostream>
#include <algorithm>
using namespace std;

int n, m;

struct Node
{
    int x, y, t;
} node[100020];

bool comp(Node n1, Node n2)
{
    return n1.t < n2.t;
}

int parent[100020][2];
void init()
{
    for (int i = 1; i <= n; i++)
    {
        parent[i][0] = i;
        parent[i][1] = 1;
    }
}
int find(int x)
{
    if (parent[x][0] != x)
        parent[x][0] = find(parent[x][0]);
    return parent[x][0];
}
bool unionNode(int x, int y)
{
    int xp = find(x), yp = find(y);
    if (xp != yp)
    {
        parent[xp][0] = yp;
        parent[yp][1] += parent[xp][1];
    }
    if (parent[yp][1] == n)
    {
        return true;
    }
    return false;
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < m; i++)
        cin >> node[i].x >> node[i].y >> node[i].t;

    sort(node, node + m, comp);
    init();
    for (int i = 0; i < m; i++)
    {
        if (unionNode(node[i].x, node[i].y))
        {
            cout << node[i].t;
            return 0;
        }
    }
    cout << "-1";
    return 0;
}