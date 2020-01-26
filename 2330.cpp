#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    int u, v, c;
} node[100010];

int n, m,num,maxSize;

bool comp(Node n1,Node n2)
{
    return n1.c < n2.c;
}

int parent[320];
void init()
{
    for (int i = 0; i <= n; i++)
    {
        parent[i] = i;
    }
}
int find(int x)
{
    if(parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}
void join(int x,int y)
{
    int xp = find(x),yp = find(y);
    if(xp != yp)
        parent[xp] = yp;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> node[i].u >> node[i].v >> node[i].c;
    }
    sort(node,node+m,comp);
    init();
    for (int i = 0; i < m; i++)
    {
        if(find(node[i].u) != find(node[i].v))
        {
            num++;
            maxSize = max(maxSize,node[i].c);
            join(node[i].u,node[i].v);
        }
    }
    cout << num << ' ' << maxSize;
    return 0;
}