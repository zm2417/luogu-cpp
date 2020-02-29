#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <cstdio>
#include <set>
using namespace std;

const int MAXN = 1010;
int n, m, si;
// int d[MAXN][MAXN];
int into[MAXN];
int vis[MAXN];
queue<int> q;
int dep[MAXN];
int ans;
set<int> vd[MAXN];

int main()
{
    scanf("%d %d", &n, &m);
    // cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &si);
        // cin >> si;
        int k;
        for (int i = 1; i <= n; i++)
            vis[i] = 0;
        int start = n + 1, end = -1;
        for (int j = 0; j < si; j++)
        {
            scanf("%d", &k);
            // cin >> k;
            vis[k] = 1;
            start = min(start, k);
            end = max(end, k);
        }
        for (int j = start; j <= end; j++)
            if (vis[j] == 0)
                for (int l = start; l <= end; l++)
                    if (vis[l] != 0 && vd[j].find(l) == vd[j].end())
                    {
                        vd[j].insert(l);
                        // d[j][l] = 1,
                        into[l]++;
                    }
    }
    // print();
    for (int i = 1; i <= n; i++)
    {
        dep[i] = 1;
        if (into[i] == 0)
            q.push(i);
    }
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i : vd[x])
        {
            into[i]--;
            dep[i] = max(dep[i], dep[x] + 1);
            if (into[i] == 0)
            {
                q.push(i);
            }
        }
    }
    for (int i = 1; i <= n; i++)
        ans = max(ans, dep[i]);
    cout << ans << endl;
    return 0;
}