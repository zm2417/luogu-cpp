#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 10010;
int n;
int t[MAXN], t1[MAXN];
vector<int> node[MAXN];
int into[MAXN];
queue<int> q;
int ans = 0;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int j, len, k;
        cin >> j >> len >> k;
        t[j] = len;
        t1[j] = len;
        while (k != 0)
        {
            node[k].push_back(j);
            into[j]++;
            cin >> k;
        }
    }
    for (int i = 1; i <= n; i++)
        if (into[i] == 0)
            q.push(i);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = 0; i < node[x].size(); i++)
        {
            int j = node[x][i];
            into[j]--;
            if (t[j] + t1[x] > t1[j])
            {
                t1[j] = t[j] + t1[x];
            }
            if (into[j] == 0)
            {
                q.push(j);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, t1[i]);
    }
    cout << ans << endl;
    return 0;
}