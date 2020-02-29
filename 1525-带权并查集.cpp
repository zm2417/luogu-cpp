#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
int parent[20010]; // 并查集,集合中放敌人的敌人(即放一起的人)
int enemy[20010];  // 记录冲突的人

struct Node
{
    int a, b, c;
    friend bool operator<(Node n1, Node n2)
    {
        return n1.c > n2.c;
    }
} node[100010];

void init()
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }
}
int findParent(int x)
{
    if (parent[x] != x)
        parent[x] = findParent(parent[x]);
    return parent[x];
}
void unionSet(int x, int y)
{
    int xx = findParent(x), yy = findParent(y);
    if (xx != yy)
        parent[xx] = yy;
}

// 检查冲突两人在一个集合中
bool check(int x, int y)
{
    return findParent(x) == findParent(y);
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        cin >> node[i].a >> node[i].b >> node[i].c;
    sort(node, node + m);
    init();
    for (int i = 0; i <= m; i++)
    {
        if (check(node[i].a, node[i].b))
        {
            cout << node[i].c << endl;
            return 0;
        }
        if (enemy[node[i].a] != 0)
            unionSet(node[i].b, enemy[node[i].a]);
        else
            enemy[node[i].a] = node[i].b;
        if (enemy[node[i].b] != 0)
            unionSet(node[i].a, enemy[node[i].b]);
        else
            enemy[node[i].b] = node[i].a;
    }
    return 0;
}