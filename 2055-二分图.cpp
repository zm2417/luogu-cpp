/**
 * 洛谷cpp算法
 * 
 * @author: zhangMeng
 * @date: 2020-02-28 
 */
#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 55;
int t, n;
int school[MAXN];  // 是否是在校学生 (0 表示不是，1 表示是)
int home[MAXN];    // 是否回家 (0 表示不回家，1 表示回家)
int d[MAXN][MAXN]; // 是否认识 (1 表示认识，0 表示不认识)
int bed[MAXN];     // 床上的人
int person[MAXN];  // 人对应的床
int vis[MAXN];

bool dfs(int x)
{
    for (int i = 1; i <= n; i++)
    {
        if (school[i] == 1 && vis[i] == 0 && (d[x][i] == 1 || x == i))
        {
            vis[i] = 1;
            if (bed[i] == 0 || dfs(bed[i]))
            {
                bed[i] = x;
                person[x] = i;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    cin >> t;
    while (t > 0)
    {
        cin >> n;
        t--;
        for (int i = 1; i <= n; i++)
            cin >> school[i];
        for (int i = 1; i <= n; i++)
            cin >> home[i];
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                cin >> d[i][j];
                if (i == j)
                    d[i][j] = 1;
            }
        int ans = 0;
        memset(bed, 0, sizeof(bed));
        for (int i = 1; i <= n; i++)
        {
            memset(vis, 0, sizeof(vis));
            if (home[i] == 1 && school[i] == 1)
                ans++;
            else if (dfs(i))
            {
                ans++;
            }
            else
            {
                break;
            }
        }
        if (ans < n)
        {
            cout << "T_T" << endl;
        }
        else
        {
            cout << "^_^" << endl;
        }
    }
    return 0;
}
