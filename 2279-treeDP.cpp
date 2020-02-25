#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxInf = 1005;
const int INF = 2000000000;
vector<int> tree[maxInf];
int n;
// F[i][0]表示可以覆盖到从节点i向上2层的最小消防站个数
// F[i][1]表示可以覆盖到从节点i向上1层的最小消防站个数
// F[i][2]表示可以覆盖到从节点i向上0层的最小消防站个数
// F[i][3]表示可以覆盖到从节点i向上-1层的最小消防站个数
// F[i][4]表示可以覆盖到从节点i向上-2层的最小消防站个数
int dp[maxInf][5];
int used[maxInf];

// p:当前节点 f:父节点
void dfs(int p, int f)
{
    dp[p][0] = 1;
    int s2 = 0, s3 = 0;
    int s0 = INF, s1 = INF;
    for (int i = 0; i < tree[p].size(); i++)
    {
        int j = tree[p][i];
        if (f == j)
            continue;
        dfs(j, p);
        if (p == 5 || p == 2)
        {
            int x = 0;
        }
        dp[p][0] += dp[j][4];
        s2 += dp[j][2];
        s3 += dp[j][3];

        s0 = min(s0, dp[j][0] - dp[j][3]);
        s1 = min(s1, dp[j][1] - dp[j][2]);
    }
    dp[p][1] = s3 + s0;
    dp[p][2] = s2 + s1;
    dp[p][3] = s2;
    dp[p][4] = s3;

    dp[p][1] = min(dp[p][1], dp[p][0]);
    dp[p][2] = min(dp[p][2], dp[p][1]);
    dp[p][3] = min(dp[p][3], dp[p][2]);
    dp[p][4] = min(dp[p][4], dp[p][3]);
}

// 树状dp
int main()
{
    cin >> n;
    // memset(dp, maxInf, sizeof(dp));
    for (int i = 2; i <= n; i++)
    {
        int j;
        cin >> j;
        tree[i].push_back(j);
        tree[j].push_back(i);
    }
    dfs(1, -1);
    cout << dp[1][2] << endl;
    // for (int i = 0; i < tree[5].size(); i++)
    // {
    //     int j = tree[5][i];
    //     cout << "j=" << j << ' ' << dp[j][0] << ' ' << dp[j][1] << ' ' << dp[j][2] << ' ' << dp[j][3] << ' ' << dp[j][4] << endl;
    // }
    // for (int i = 1; i <= n; i++)
    //     cout << dp[i][0] << ' ' << dp[i][1] << ' ' << dp[i][2] << ' ' << dp[i][3] << ' ' << dp[i][4] << endl;
    return 0;
}