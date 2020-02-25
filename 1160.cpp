#include <iostream>
#include <deque>
#include <set>
using namespace std;

struct Node
{
    int l = -1;
    int r = -1;
} node[100001];

int main()
{
    int n;
    cin >> n;
    node[0].r = 1;
    node[1].l = 0;
    for (int i = 2; i <= n; i++)
    {
        int k, p;
        cin >> k >> p;
        if (p == 0)
        {
            node[i].l = node[k].l;
            node[i].r = k;
            node[node[k].l].r = i;
            node[k].l = i;
        }
        else
        {
            node[i].l = k;
            node[i].r = node[k].r;
            node[node[k].r].l = i;
            node[k].r = i;
        }
    }
    int m;
    cin >> m;
    set<int> s;
    for (int i = 0; i < m; i++)
    {
        int t;
        cin >> t;
        s.insert(t);
    }
    Node head = node[0];
    while (head.r != -1)
    {
        int i = head.r;
        if (s.find(i) == s.end())
        {
            cout << i << ' ';
        }
        head = node[head.r];
    }
    return 0;
}