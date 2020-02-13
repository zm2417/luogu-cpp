#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

const int inf = 1000000010;
const int MAXN = 10005;
int n, m, b, fi, ai, bi, ci;
int f[MAXN], s[MAXN];
vector<pair<int, int>> d[MAXN];
int dis[MAXN], vis[MAXN];
int ans;

struct Node
{
    int v, w;
    friend bool operator<(const Node &a, const Node &b)
    {
        return a.w > b.w;
    }
};

bool check(int x)
{
    if (x < f[1] || x < f[n])
        return false;
    for (int i = 0; i <= n; i++)
        dis[i] = inf;
    for (int i = 1; i <= n; i++)
    {
        if (f[i] > x)
            vis[i] = 1;
        else
            vis[i] = 0;
    }
    priority_queue<Node> q;
    q.push({1, 0});
    dis[1] = 0;
    // vis[1] = 1;
    while (q.size())
    {
        Node temp = q.top();
        int y = temp.v;
        q.pop();
        if (vis[y])
            continue;
        vis[y] = 1;
        for (int i = 0; i < d[y].size(); i++)
        {
            int t = d[y][i].first, wi = d[y][i].second;
            if (dis[t] > dis[y] + wi)
            {
                dis[t] = dis[y] + wi;
                q.push({t, dis[t]});
            }
        }
    }
    // cout << dis[n] << endl;
    return dis[n] <= b;
}

int main()
{
    cin >> n >> m >> b;
    for (int i = 1; i <= n; i++)
    {
        cin >> f[i];
        s[i] = f[i];
    }
    sort(s + 1, s + 1 + n);
    for (int i = 1; i <= m; i++)
    {
        cin >> ai >> bi >> ci;
        pair<int, int> p;
        p.first = bi;
        p.second = ci;
        d[ai].push_back(p);
        p.first = ai;
        d[bi].push_back(p);
    }
    if (!check(s[n]))
    {
        cout << "AFK" << endl;
        return 0;
    }
    int l = 1, r = n;
    ans = s[n];
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (check(s[mid]))
        {
            r = mid - 1;
            ans = s[mid];
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}