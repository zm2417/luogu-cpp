#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 10010;
int n, d[MAX];
int t[2][MAX];
int match[MAX], vis[MAX], to[MAX];

bool dfs(int x)
{
    for (int i = 0; i < 2; i++)
    {
        int v = t[i][x];
        if (vis[v] == 0)
        {
            vis[v] = 1;
            if (match[v] == -1 || dfs(match[v]))
            {
                match[v] = x;
                to[x] = v;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> d[i];
    for (int i = 0; i < n; i++)
    {
        int a = (i - d[i] + n) % n, b = (i + d[i] + n) % n;
        if (a > b)
            swap(a, b);
        t[0][i] = a;
        t[1][i] = b;
    }
    memset(match, -1, sizeof(match));
    int ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        memset(vis, 0, sizeof(vis));
        if (dfs(i))
            ++ans;
    }
    if (ans < n)
        cout << "No Answer" << endl;
    else
        for (int i = 0; i < n; i++)
            cout << to[i] << ' ';
    return 0;
}