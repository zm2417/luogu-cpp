/**
 * 洛谷cpp算法
 * 
 * @author: zhangMeng
 * @date: 2020-03-09 
 */
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100 * 100 + 5;
int s;
int mask;
struct Node
{
    int l = 0, r = 0;
    int y = 0, w = 0;
} node[MAXN];
int dp[105][10 * 60 + 5];

int build()
{
    mask++;
    int m = mask;
    Node temp;
    cin >> temp.y >> temp.w;
    temp.y *= 2;
    if (temp.w == 0)
    {
        int l = build();
        int r = build();
        temp.l = l, temp.r = r;
    }
    node[m] = temp;
    return m;
}

// f[i][j]表示当前节点为i用掉j秒所取得的最大值
// 转移的时候 如果当前节点是子节点，就判断能取多少
// 如果不是就枚举当前节点所分配给左树的时间，由左右子树的和转移来。
void dfs(int x, int t)
{
    if (dp[x][t] || !t)
        return;
    if (node[x].l == 0)
    {
        dp[x][t] = min((t - node[x].y) / 5, node[x].w);
    }
    else
    {
        for (int i = 0; i <= t - node[x].y; i++)
        {
            dfs(node[x].l, i);
            dfs(node[x].r, t - node[x].y - i);
            dp[x][t] = max(dp[x][t], dp[node[x].l][i] + dp[node[x].r][t - node[x].y - i]);
        }
    }
}

void print(int x)
{
    // cout << x << ' ' <<  << ' ' << node[x].w << endl;
    // if (node[x].l == 0)
    //     return;
    // print(node[x].l);
    // print(node[x].r);
    cout << x << endl;
    for (int i = 0; i <= s; i++)
    {
        cout << i << ':' << dp[x][i] << endl;
    }
    if (node[x].l == 0)
        return;
    print(node[x].l);
    print(node[x].r);
}

int main()
{
    cin >> s;
    s--;
    build();
    // print(1);
    dfs(1, s);
    // print(1);
    cout << dp[1][s] << endl;
    return 0;
}
