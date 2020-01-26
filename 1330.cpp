#include <iostream>
#include <vector>
using namespace std;

const int maxInf = 100005;
int n, m, ans = 0;
int d[maxInf][2];
int used[maxInf];
vector<int> g[maxInf];
int sum[2];
bool mask = false;

//1.大的图分成小的连通图，各自计算，某一个小图无法染色即可得出不可能成功的结果
//2.染色法处理相邻的节点
//3.染色法中节点的颜色可以想换转换，即颜色1与颜色2可以整体转换而不影响结果（只选择少的一种颜色即可）
bool dfs(int p, int color)
{
    if (used[p] != 0)
    {
        if (used[p] == color)
            return true;
        else
        {
            return false;
        }
    }
    used[p] = color;
    sum[color - 1]++;
    int otherColor = color == 1 ? 2 : 1;
    bool ret = true;
    for (int i = 0; i < g[p].size(); i++)
    {
        ret = ret & dfs(g[p][i], otherColor);
    }
    return ret;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
    {
        if (used[i] != 0)
            continue;
        sum[0] = sum[1] = 0;
        if(!dfs(i,1))
        {
            cout << "Impossible";
            return 0;
        }
        ans += min(sum[0],sum[1]);
    }
    cout << ans;
    return 0;
}