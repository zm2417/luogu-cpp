/**
 * 洛谷cpp算法
 * 
 * @author: zhangMeng
 * @date: 2020-03-05 
 */
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 3005;
int n, m;
int k, a, c;
int dp[MAXN][MAXN];
int pay[MAXN]; // 支付
struct Node
{
    int y, cost;
};
vector<Node> d[MAXN];

int dfs(int r)
{
    if (r > n - m)
    {
        dp[r][1] = pay[r];
        return 1;
    }
    int num = 0;
    for (int i = 0; i < d[r].size(); i++)
    {
        int tk = dfs(d[r][i].y);
        num += tk;
        for (int j = num; j > 0; j--)
        {
            for (int k = 0; k <= tk; k++)
            {
                if (j >= k)
                    dp[r][j] = max(dp[r][j], dp[r][j - k] + dp[d[r][i].y][k] - d[r][i].cost);
            }
        }
    }
    return num;
}

int main()
{
    memset(dp, ~0x3f, sizeof(dp)); //初始化一个极大负值，因为dp可能为负
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        if (i <= n - m)
        {
            cin >> k;
            for (int j = 0; j < k; j++)
            {
                Node node;
                cin >> node.y >> node.cost;
                d[i].push_back(node);
            }
        }
        else
        {
            cin >> pay[i];
        }
    }
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    dfs(1);
    for (int i = m; i >= 1; i--)
        if (dp[1][i] >= 0)
        {
            printf("%d", i);
            break;
        }
    return 0;
}
