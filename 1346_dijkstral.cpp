#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 105;
int n, a, b, ki, k;
vector<int> d[MAXN];
int dis[MAXN], vis[MAXN];

struct Node
{
    int p, num;
    friend bool operator<(const Node n1, const Node n2)
    {
        return n1.num < n2.num;
    }
};

int main()
{
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++)
    {
        cin >> ki;
        for (int j = 0; j < ki; j++)
        {
            cin >> k;
            d[i].push_back(k);
        }
    }
    for (int i = 0; i <= n; i++)
        dis[i] = 200;
    priority_queue<Node> q;
    q.push({a, 0});
    dis[a] = 0;
    while (q.size())
    {
        Node temp = q.top();
        q.pop();
        // if (vis[temp.p])
        //     continue;
        // vis[temp.p] = 1;
        for (int i = 0; i < d[temp.p].size(); i++)
        {
            int p = d[temp.p][i];
            if (i == 0)
            {
                if (dis[p] > dis[temp.p])
                {
                    dis[p] = dis[temp.p];
                    q.push({p, dis[p]});
                }
            }
            else
            {
                if (dis[p] > dis[temp.p] + 1)
                {
                    dis[p] = dis[temp.p] + 1;
                    q.push({p, dis[p]});
                }
            }
        }
    }
    if (dis[b] == 200)
        cout << -1 << endl;
    else
        cout << dis[b] << endl;
    return 0;
}