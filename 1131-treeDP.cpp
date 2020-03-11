/**
 * 洛谷cpp算法
 * 
 * @author: zhangMeng
 * @date: 2020-03-07 
 */
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 500005;
int n, s, a, b, t;

struct Node
{
    int y, t;
};
vector<Node> d[MAXN];
long long dp[MAXN];
// int lef[MAXN];
long long maxSum;
long long ans;

void dfs(int x, int f)
{
    // if (d[x].size() == 0)
    //     lef[x] = 1;
    for (int i = 0; i < d[x].size(); i++)
    {
        Node node = d[x][i];
        if (f == node.y)
            continue;
        dfs(node.y, x);
        dp[x] = max(dp[x], dp[node.y] + node.t);
        // dp[node.y] = dp[x] + node.t;
    }
    for (int i = 0; i < d[x].size(); i++)
    {
        Node node = d[x][i];
        if (f == node.y)
            continue;
        ans += dp[x] - (dp[node.y] + node.t);
    }
    // maxSum = max(maxSum, dp[x]);
}

int main()
{
    cin >> n >> s;
    for (int i = 0; i < n - 1; i++)
    {
        Node node;
        cin >> a >> b >> t;
        node.y = b, node.t = t;
        d[a].push_back(node);
        Node node1;
        node1.y = a, node1.t = t;
        d[b].push_back(node1);
    }
    dfs(s, 0);
    // for (int i = 0; i < n; i++)
    // {
    //     if (lef[i] == 1 && maxSum != dp[i])
    //     {
    //         ans += maxSum - dp[i];
    //     }
    // }
    cout << ans << endl;
    return 0;
}
