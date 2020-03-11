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

const int MAXN = 505;
int n, a, b, m;
vector<int> d[MAXN];

int dfn[MAXN], low[MAXN], vis[MAXN], parent[MAXN], num;
int cut[MAXN]; // 是否是割点
int root;      // 根
int rs;
int group;
long long ans1, ans2;
long long cutNum;

// 求割点
void tarjan(int x, int f)
{
    int child = 0;
    dfn[x] = low[x] = ++num;
    for (int i = 0; i < d[x].size(); i++)
    {
        int j = d[x][i];
        if (dfn[j] == 0)
        {
            tarjan(j, x);
            low[x] = min(low[x], low[j]);
            if (low[j] >= dfn[x])
            {
                if (x != root)
                    cut[x] = 1;
                else
                    child++;
            }
        }
        low[x] = min(low[x], dfn[j]);
        if (child >= 2 && x == root)
            cut[x] = 1;
    }
}

void dfs(int x)
{
    int v;
    vis[x] = group;
    num++;
    for (int i = 0; i < d[x].size(); i++)
    {
        v = d[x][i];
        if (cut[v] && vis[v] != group)
        {
            cutNum++;
            vis[v] = group;
        }
        if (!vis[v])
            dfs(v);
    }
}

int main()
{
    for (int i = 1;; i++)
    {
        cin >> n;
        if (n == 0)
            break;
        memset(dfn, 0, sizeof(dfn));
        memset(low, 0, sizeof(low));
        memset(vis, 0, sizeof(vis));
        memset(parent, 0, sizeof(parent));
        memset(cut, 0, sizeof(cut));
        for (int j = 1; j <= m; j++)
            d[j].clear();
        m = 0;
        num = 0;
        ans1 = 0;
        ans2 = 1;
        group = 0;
        for (int j = 0; j < n; j++)
        {
            cin >> a >> b;
            d[a].push_back(b);
            d[b].push_back(a);
            m = max(m, max(a, b));
        }
        for (int j = 1; j <= m; j++)
            if (dfn[j] == 0)
            {
                root = j;
                tarjan(j, j);
            }
        for (int j = 1; j <= m; j++)
        {
            if (cut[j] == 0 && vis[j] == 0)
            {
                group++;
                num = cutNum = 0;
                dfs(j); //搜索这个分组

                if (cutNum == 0) //如果没有割点
                {
                    ans1 += 2;                   //至少需要建立两个出口
                    ans2 *= (num - 1) * num / 2; //从任意非割点的地方选择两个点建立
                }

                if (cutNum == 1) //如果这个分组只有一个割点
                {
                    ans1 += 1;   //只需要在分组内设立一个出口
                    ans2 *= num; //可以设立在任意一个非割点的地方
                }

                // if (cutNum >= 2) //如果有两个及以上个割点，则无需建立，可以直接到达其他联通块
                // {
                //     ;
                // }
            }
        }
        cout << "Case " << i << ": " << ans1 << " " << ans2 << endl; //输出结果
    }
    return 0;
}
