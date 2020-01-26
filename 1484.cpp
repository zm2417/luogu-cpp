#include <iostream>
#include <queue>
using namespace std;

const int maxInf = 500005;
int n, k;
int l[maxInf], r[maxInf], used[maxInf];
long long d[maxInf], ans;

struct Node
{
    long long w;
    int id;

    friend bool operator<(const Node &a, const Node &b)
    {
        return a.w < b.w; // ascending sort
    }
};

priority_queue<Node> q;

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        Node t;
        cin >> t.w;
        d[i] = t.w;
        t.id = i;
        q.push(t);
        l[i] = i - 1;
        r[i] = i + 1;
    }
    r[0] = 1;
    l[n + 1] = n;
    while (k--)
    {
        while (used[q.top().id] == 1)
        {
            q.pop();
        }
        Node t = q.top();
        if (t.w <= 0)
            break;
        q.pop();
        ans += t.w;
        used[l[t.id]] = 1, used[r[t.id]] = 1;
        d[t.id] = d[l[t.id]] + d[r[t.id]] - d[t.id];
        t.w = d[t.id];
        l[t.id] = l[l[t.id]];
        r[t.id] = r[r[t.id]];
        r[l[t.id]] = t.id;
        l[r[t.id]] = t.id;
        q.push(t);
    }
    cout << ans;
    return 0;
}