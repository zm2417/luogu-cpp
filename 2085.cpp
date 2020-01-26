#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int a, b, c;
    long long num;
    int x;
    friend bool operator<(const Node &a, const Node &b)
    {
        return a.num > b.num; // ascending sort
    }
};
priority_queue<Node> q;
int n, m;

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        Node n;
        cin >> n.a >> n.b >> n.c;
        n.num = n.a + n.b + n.c;
        n.x = 1;
        q.push(n);
    }
    for (int i = 0; i < m; i++)
    {
        cout << q.top().num << ' ';
        Node n = q.top();
        q.pop();
        n.x += 1;
        n.num = n.a * n.x * n.x + n.b * n.x + n.c;
        q.push(n);
    }
    return 0;
}