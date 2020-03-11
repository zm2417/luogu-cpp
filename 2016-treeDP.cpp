/**
 * 洛谷cpp算法
 * 
 * @author: zhangMeng
 * @date: 2020-03-07 
 */
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1500;
int n;
vector<int> d[MAXN];
int root[MAXN];
int dp[MAXN][2];
int ans = INT16_MAX;

void dfs(int x)
{
    dp[x][1] = 1;
    if (d[x].size() == 0)
        return;
    for (int i = 0; i < d[x].size(); i++)
    {
        int j = d[x][i];
        dfs(j);
        dp[x][0] += dp[j][1];
        dp[x][1] += min(dp[j][0], dp[j][1]);
    }
    ans = min(dp[x][0], dp[x][1]);
}

int main()
{
    cin >> n;
    for (int j = 0; j < n; j++)
    {
        int i, k;
        cin >> i >> k;
        for (int l = 0; l < k; l++)
        {
            int m;
            cin >> m;
            d[i].push_back(m);
            root[m] = 1;
        }
    }
    if (n == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    for (int i = 0; i < n; i++)
        if (root[i] == 0)
            dfs(i);
    cout << ans << endl;
    return 0;
}
