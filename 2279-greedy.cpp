#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int maxInf = 1005;
const int INF = 2000000000;
vector<int> tree[maxInf];
int n;
int ans;
int dep[maxInf], fa[maxInf];
int visit[maxInf];

struct cmp
{
    bool operator()(int i, int j)
    {
        return dep[i] < dep[j];
    }
};

priority_queue<int, vector<int>, cmp> q;

void dfs(int p, int f, int h)
{
    dep[p] = h;
    fa[p] = f;
    for (int i = 0; i < tree[p].size(); i++)
    {
        if (tree[p][i] == f)
            continue;
        dfs(tree[p][i], p, h + 1);
    }
}

void dfs2(int x, int h)
{
    if (h > 2)
    {
        return;
    }
    visit[x] = 1;
    for (int i = 0; i < tree[x].size(); i++)
    {
        int j = tree[x][i];
        dfs2(j, h + 1);
    }
}

// 贪心
int main()
{
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        int j;
        cin >> j;
        tree[i].push_back(j);
        tree[j].push_back(i);
    }
    dfs(1, 0, 1);
    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }
    while (q.size())
    {
        while (q.size() && visit[q.top()])
        {
            q.pop();
        }
        if (!q.size())
            break;
        if (fa[fa[q.top()]])
            dfs2(fa[fa[q.top()]], 0);
        else
            dfs2(1, 0);
        q.pop();
        ans++;
    }
    cout << ans << endl;
    return 0;
}