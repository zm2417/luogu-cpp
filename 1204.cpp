#include <iostream>
#include <algorithm>
using namespace std;

const int maxInf = 5005;
const int INF = 1000005;
int n, d[INF];

struct Node
{
    int l, r;
} node[maxInf];

bool comp(Node n1, Node n2)
{
    if (n1.l == n2.l)
        return n1.r < n2.r;
    return n1.l < n2.l;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> node[i].l >> node[i].r;
    }
    sort(node, node + n, comp);
    int p = 0;
    int person = 0, noPerson = 0;
    for (int i = 0; i < n; )
    {
        int j = i + 1;
        while (node[i].r >= node[j].l && j < n)
        {
            node[i].r = max(node[i].r, node[j].r);
            j++;
        }
        person = max(person,node[i].r - node[i].l);
        noPerson = max(noPerson,node[j].l - node[i].r);
        i = j;
    }
    cout << person << ' ' << noPerson;
    return 0;
}