#include <iostream>
using namespace std;

const int MAX = 5005;
int D, a, b, c;
int sx[4][MAX];
int t, ans;
int head[MAX], match[MAX], vis[MAX];
int height[MAX], cnt;

struct Node
{
    int too, next;
} node[MAX];

void add(int x, int y)
{
    node[++cnt].next = head[x];
    node[cnt].too = y;
    head[x] = cnt;
}

bool dfs(int x)
{
    for (int i = head[x]; i; i = node[i].next)
    {
        int j = node[i].too;
        if (vis[j] == 0)
        {
            vis[j] = 1;
            if (match[j] == 0 || dfs(match[j]))
            {
                match[j] = x;
                return true;
            }
        }
    }
    return false;
}

void work(int x)
{
    for (int i = 1; i <= b; i++)
        head[i] = 0;
    for (int i = 1; i <= c; i++)
        match[i] = 0;
    int tmp = 0;
    cnt = 0;
    for (int i = 0; i < a; i++)
    {
        if (x & (1 << i))
        {
            // 直接切掉
            height[i + 1] = 0;
            tmp++;
        }
        else
        {
            height[i + 1] = 1;
        }
    }
    // 压扁成2维
    for (int i = 1; i <= t; i++)
        if (height[sx[1][i]])
            add(sx[2][i], sx[3][i]);
    for (int i = 1; i <= b; i++)
    {
        for (int j = 1; j <= c; j++)
            vis[j] = 0;
        if (dfs(i))
            tmp++;
    }
    ans = min(ans, tmp);
}

int main()
{
    cin >> D;
    while (D--)
    {
        t = 0;
        ans = 0x3f3f3f3f;
        cin >> a >> b >> c;
        for (int i = 1; i <= a; i++)
            for (int j = 1; j <= b; j++)
                for (int k = 1; k <= c; k++)
                {
                    int l;
                    cin >> l;
                    if (l == 0)
                        continue;
                    sx[1][++t] = i;
                    sx[2][t] = j;
                    sx[3][t] = k;
                }
        // 找a,b,c中最小的值
        int minn = min(a, min(b, c));
        if (minn == b)
            swap(a, b), swap(sx[1], sx[2]);
        else if (minn == c)
            swap(a, c), swap(sx[1], sx[3]);
        // 1<<a 枚举每一层（设为高） 是否切
        // 每一层两个可能 1。直接切掉该层 2.不切该层，最后将所有不切的层拍扁，拍成二维，再跑最大匹配
        for (int i = 0; i < (1 << a); i++)
            work(i);
        cout << ans << endl;
    }
    return 0;
}