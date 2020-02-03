#include <iostream>
#include <queue>
using namespace std;

int n, m1, m2, ans;
int t[1010];

struct Node
{
    int t, v;
    bool operator<(Node k) const
    {
        return t > k.t;
    }
};
priority_queue<Node> q;

int main()
{
    cin >> n >> m1 >> m2;
    for (int i = 0; i < m1; i++)
    {
        Node temp;
        cin >> temp.v;
        temp.t = temp.v;
        q.push(temp);
    }
    for (int i = 0; i < n; i++)
    {
        Node temp = q.top();
        q.pop();
        t[i] = temp.t;
        temp.t += temp.v;
        q.push(temp);
    }
    while (!q.empty())
    {
        q.pop();
    }
    for (int i = 0; i < m2; i++)
    {
        Node temp;
        cin >> temp.v;
        temp.t = temp.v;
        q.push(temp);
    }
    // 贪心 大+小 优与 大+大
    for (int i = n - 1; i >= 0; i--)
    {
        Node temp = q.top();
        q.pop();
        if (t[i] + temp.t > ans)
            ans = t[i] + temp.t;
        // t[i] = temp.t;
        temp.t += temp.v;
        q.push(temp);
    }
    cout << t[n - 1] << ' ' << ans << endl;
    return 0;
}