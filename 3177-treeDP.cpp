/**
 * 洛谷cpp算法
 * 
 * @author: zhangMeng
 * @date: 2020-03-09 
 */
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 2005;
int n, k, fr, to, dis;

struct Node
{
    int y, w;
};
vector<Node> d[MAXN];
int num[MAXN];
long long dp[MAXN][MAXN];

void add(int f, int t)
{
    Node node;
    node.y = t;
    node.w = dis;
    d[f].push_back(node);
}

// 点的计算 ==> 边的计算
// dp[u][i]表示以u为跟的子树中，选择i个黑节点，对答案有多少贡献
// 为什么是说“对答案有多少贡献呢”？
// 主要是想到一点，即分别考虑每条边对答案的贡献
// 即，边一侧的黑节点数*另一侧的黑节点数*边权+一侧的白节点数*另一侧的白节点数*边权
void deal(int x, int f, int v)
{
    // i从大到小倒序,防止干扰同一层dp的值
    for (int i = min(k, num[f]); i >= 0; i--)
        for (int j = 0; j <= min(k, num[x]); j++)
        {
            if (dp[f][i - j] >= 0)
            {
                long long black = 1ll * j * (k - j) * v;
                long long white = 1ll * (num[x] - j) * (n - k - (num[x] - j)) * v;
                dp[f][i] = max(dp[f][i], dp[x][j] + dp[f][i - j] + black + white);
            }
        }
}

void dfs(int u, int f)
{
    num[u] = 1;
    dp[u][0] = dp[u][1] = 0;
    for (int i = 0; i < d[u].size(); i++)
    {
        Node node = d[u][i];
        if (node.y == f)
            continue;
        dfs(node.y, u);
        num[u] += num[node.y];
        // deal(node.y, u, node.w);
    }
    for (int i = 0; i < d[u].size(); i++)
    {
        Node node = d[u][i];
        if (node.y == f)
            continue;
        // dfs(node.y, u);
        // num[u] += num[node.y];
        deal(node.y, u, node.w);
    }
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> fr >> to >> dis;
        add(fr, to);
        add(to, fr);
    }
    memset(dp, -1, sizeof(dp));
    dfs(1, 0);
    cout << dp[1][k] << endl;
    return 0;
}
