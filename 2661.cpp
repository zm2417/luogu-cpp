#include <iostream>
using namespace std;

const int maxInf = 200010;
int n;
int parent[maxInf], dis[maxInf], ans = INT32_MAX;
void init()
{
    for (int i = 1; i <= n; i++)
        parent[i] = i;
}
int find(int x)
{
    if (parent[x] != x)
    {
        int p = parent[x];
        parent[x] = find(parent[x]);
        dis[x] += dis[p];
    }
    return parent[x];
}
void join(int x, int y)
{
    int xx = find(x), yy = find(y);
    if (xx != yy)
    {
        parent[xx] = parent[yy];
        dis[x] = dis[y] + 1;
    }
    else
    {
        ans = min(ans, dis[x] + dis[y] + 1);
    }
}

int main()
{
    cin >> n;
    init();
    for (int i = 1; i <= n; i++)
    {
        int j;
        cin >> j;
        join(i, j);
    }
    cout << ans;
    return 0;
}