/**
 * 洛谷cpp算法
 * 
 * @author: zhangMeng
 * @date: 2020-03-09 
 */
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 105;
int n, q;
struct Node
{
    int y, v;
};
vector<Node> d[MAXN];
int sum[MAXN];
int dp[MAXN][MAXN]; // 设f[i][j]f[i][j]表示以 ii 为根节点保存 jj 根树枝的可以获得的最大苹果数

void add(int i, int j, int k)
{
    Node node;
    node.y = j;
    node.v = k;
    d[i].push_back(node);
}

void dfs(int x, int f)
{
    // sum[x] = 1;
    for (int i = 0; i < d[x].size(); i++)
    {
        Node node = d[x][i];
        if (node.y == f)
            continue;
        dfs(node.y, x);
        sum[x] += sum[node.y] + 1;
        for (int j = min(sum[x], q); j > 0; j--)
            for (int k = 0; k <= min(sum[node.y], j - 1); k++)
            {
                dp[x][j] = max(dp[x][j], dp[node.y][k] + dp[x][j - k - 1] + node.v);
            }
    }
}

int main()
{
    cin >> n >> q;
    for (int i = 0; i < n - 1; i++)
    {
        int j, k, l;
        cin >> j >> k >> l;
        add(j, k, l), add(k, j, l);
    }
    dfs(1, 0);
    cout << dp[1][q] << endl;
    return 0;
}
