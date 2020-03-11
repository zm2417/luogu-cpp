/**
 * 洛谷cpp算法
 * 
 * @author: zhangMeng
 * @date: 2020-03-07 
 */
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 6005;
int n;
int r[MAXN];
vector<int> d[MAXN];
int dp[MAXN][2];
int root[MAXN];
int ans;

void dfs(int x)
{
    dp[x][1] = r[x];
    if (d[x].size() == 0)
    {
        return;
    }
    for (int i = 0; i < d[x].size(); i++)
    {
        int j = d[x][i];
        dfs(j);
        dp[x][1] += dp[j][0];
        dp[x][0] += max(dp[j][0], dp[j][1]);
    }
    ans = max(ans, max(dp[x][1], dp[x][0]));
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> r[i];
    for (int i = 1; i <= n; i++)
    {
        int k, l;
        cin >> l >> k;
        d[k].push_back(l);
        root[l] = 1;
    }
    for (int i = 1; i <= n; i++)
        if (root[i] == 0)
            dfs(i);
    cout << ans << endl;
    return 0;
}
