#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

const int INF = 2147483647;
int n, m, s, t, u, v, w;
vector<pair<int, int>> d[2505];
int dis[2505];

int main()
{
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        pair<int, int> p;
        p.first = v;
        p.second = w;
        d[u].push_back(p);
        p.first = u;
        d[v].push_back(p);
    }
    for (int i = 0; i <= n; i++)
        dis[i] = INF;
    // memset(dis, INF, sizeof(dis));
    dis[s] = 0;
    priority_queue<pair<int, int>> q;
    q.push(make_pair(0, s));
    while (q.size())
    {
        pair<int, int> p = q.top();
        int t1 = p.second;
        q.pop();
        for (int i = 0; i < d[t1].size(); i++)
        {
            int t2 = d[t1][i].first;
            int t3 = d[t1][i].second;
            if (dis[t2] > dis[t1] + t3)
            {
                dis[t2] = dis[t1] + t3;
                q.push(make_pair(-dis[t2], t2));
            }
        }
    }
    cout << dis[t] << endl;
    return 0;
}