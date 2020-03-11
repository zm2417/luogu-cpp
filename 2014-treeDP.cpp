/**
 * 洛谷cpp算法
 * 
 * @author: zhangMeng
 * @date: 2020-03-09 
 */
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 305;
int n, m, ki, si;
int root[MAXN];

int grade[MAXN];
vector<int> d[MAXN];
int dp[MAXN][MAXN]; // dp[i][j]:j根节点选择i门课最大分数

void deal(int x, int f)
{
    for (int i = m + 1; i > 0; i--)
    {
        for (int j = 1; j < i; j++)
            dp[i][f] = max(dp[i][f], dp[j][x] + dp[i - j][f]);
    }
}

void dfs(int x)
{
    for (int i = 0; i < d[x].size(); i++)
    {
        int j = d[x][i];
        dfs(j);
        deal(j, x);
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> ki >> grade[i];
        dp[1][i] = grade[i];
        d[ki].push_back(i);
    }
    // 使用0作为根节点,选课变成m+1
    dfs(0);
    cout << dp[m + 1][0] << endl;
    return 0;
}
