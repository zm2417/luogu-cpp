#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

struct Node
{
    int x, y;
    double v;
} node[510 * 510];

int s, p, d[510][2];
int parent[510];
void init()
{
    for (int i = 0; i < p; i++)
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
    int i= find(x),j =find(y);
    if(i != j)
        parent[i] = j;
}

bool comp(Node n1, Node n2)
{
    return n1.v < n2.v;
}

int main()
{
    cin >> s >> p;
    for (int i = 0; i < p; i++)
        cin >> d[i][0] >> d[i][1];
    int cnt = 0;
    for (int i = 0; i < p; i++)
    {
        for (int j = i + 1; j < p; j++)
        {
            double t = sqrt((d[i][0] - d[j][0]) * (d[i][0] - d[j][0]) + (d[i][1] - d[j][1]) * (d[i][1] - d[j][1]));
            node[cnt].x = i;
            node[cnt].y = j;
            node[cnt].v = t;
            cnt++;
        }
    }
    sort(node, node + cnt, comp);
    int num = 0;
    init();
    for (int i = 0; i < cnt; i++)
    {
        if(find(node[i].x) != find(node[i].y))
        {
            join(node[i].x,node[i].y);
            num++;
        }
        if(num == p- s)
        {
            printf("%.2f",node[i].v);
            return 0;
        }
    }
    return 0;
}