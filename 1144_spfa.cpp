#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<int> d[1000005];
int num[1000005];
queue<int> q;
int mask[1000005];
int dis[1000005];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        d[x].push_back(y);
        d[y].push_back(x);
    }
    for (int i = 2; i <= n; i++)
        dis[i] = 3000000;
    q.push(1);
    mask[1] = 1;
    num[1] = 1;
    while (q.size())
    {
        int x = q.front();
        q.pop();
        mask[x] = 0;
        for (int i = 0; i < d[x].size(); i++)
        {
            if (dis[d[x][i]] > dis[x] + 1)
            {
                dis[d[x][i]] = dis[x] + 1;
                num[d[x][i]] = num[x];
                if (mask[d[x][i]] == 0)
                {
                    mask[d[x][i]] = 1;
                    q.push(d[x][i]);
                }
            }
            else if (dis[d[x][i]] == dis[x] + 1)
            {
                num[d[x][i]] += num[x];
                num[d[x][i]] %= 100003;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (dis[i] == 3000000)
            cout << 0 << endl;
        else
            cout << num[i] << endl;
    }
    return 0;
}