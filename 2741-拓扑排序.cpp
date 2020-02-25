#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

const int N = 500001;
int h, w;
char d[33][33];
int letter[30];
int num;                            // num个数
int into[N];                        // 入度
int node[N], head[27], nxt[N], cnt; // 链表
int ans[27];                        // dfs中答案
string ans2[N];                     // 所有可能答案
int aa;                             // 可能数量
int q[N], r, vis[N];                // 入度0的节点数组 长度 判重

struct POS
{
    int x1 = 1e9, x2, y1 = 1e9, y2;
} pos[27];

void add(int l, int t)
{
    node[++cnt] = t;
    nxt[cnt] = head[l];
    head[l] = cnt;
}

void dfs(int dep)
{
    if (dep > num)
    {
        aa++;
        for (int i = num; i >= 1; i--)
        {
            ans2[aa] += (char)(ans[i] + 'A' - 1);
        }
        return;
    }
    for (int i = 1; i <= r; i++)
    {
        if (vis[i] == 0)
        {
            int rr = r;
            int x = q[i];
            for (int j = head[x]; j; j = nxt[j])
            {
                into[node[j]]--;
                if (into[node[j]] == 0)
                    q[++r] = node[j];
            }
            vis[i] = 1;
            ans[dep] = x;
            dfs(dep + 1);
            vis[i] = 0;
            for (int j = head[x]; j; j = nxt[j])
            {
                into[node[j]]++;
            }
            r = rr;
        }
    }
}

int main()
{
    cin >> h >> w;
    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++)
        {
            cin >> d[i][j];
            if (d[i][j] != '.')
            {
                int k = d[i][j] - 'A' + 1;
                if (letter[k] == 0)
                    num++;
                letter[k] = 1;
                if (i < pos[k].x1)
                    pos[k].x1 = i;
                if (i > pos[k].x2)
                    pos[k].x2 = i;
                if (j < pos[k].y1)
                    pos[k].y1 = j;
                if (j > pos[k].y2)
                    pos[k].y2 = j;
            }
        }
    for (int i = 1; i <= 26; i++)
    {
        if (letter[i] != 0)
        {
            for (int j = pos[i].x1; j <= pos[i].x2; j++)
            {
                int k1 = d[j][pos[i].y1] - 'A' + 1;
                if (k1 != i)
                {
                    add(k1, i);
                    into[i]++;
                }
                int k2 = d[j][pos[i].y2] - 'A' + 1;
                if (k2 != i)
                {
                    add(k2, i);
                    into[i]++;
                }
            }
            for (int j = pos[i].y1; j <= pos[i].y2; j++)
            {
                int k1 = d[pos[i].x1][j] - 'A' + 1;
                if (k1 != i)
                {
                    add(k1, i);
                    into[i]++;
                }
                k1 = d[pos[i].x2][j] - 'A' + 1;
                if (k1 != i)
                {
                    add(k1, i);
                    into[i]++;
                }
            }
        }
    }
    for (int i = 1; i <= 26; i++)
        if (letter[i] != 0 && into[i] == 0)
            q[++r] = i;
    dfs(1);
    sort(ans2 + 1, ans2 + 1 + aa);
    for (int i = 1; i <= aa; i++)
    {
        cout << ans2[i] << endl;
    }
    return 0;
}