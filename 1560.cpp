#include <iostream>
using namespace std;

int n, b;
int d[130][130];
int mask[130][130][4];
int ans;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(int x, int y, int p, int c);

bool check(int x)
{
    return x > 0 && x <= n;
}

void deal(int x, int y, int p, int c)
{
    if (mask[x][y][p] == 0 && d[x + dx[p]][y + dy[p]] == 0)
    {
        mask[x][y][p] = 1;
        dfs(x, y, p, c);
        mask[x][y][p] = 0;
    }
}

void dfs(int x, int y, int p, int c)
{
    ans = max(ans, c);
    int xx = x + dx[p], yy = y + dy[p];
    if (d[xx][yy] == 2)
    {
        return;
    }
    if (!check(xx) || !check(yy) || d[xx][yy] == 1)
    {
        if (p < 2)
        {
            deal(x, y, 2, c);
            deal(x, y, 3, c);
        }
        else
        {
            deal(x, y, 0, c);
            deal(x, y, 1, c);
        }
    }
    else
    {
        d[xx][yy] = 2;
        dfs(xx, yy, p, c + 1);
        d[xx][yy] = 0;
    }
}

int main()
{
    cin >> n >> b;
    for (int i = 0; i < b; i++)
    {
        char a;
        int c;
        cin >> a >> c;
        d[c][a - 'A' + 1] = 1;
    }
    if (d[1][1] == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    d[1][1] = 2;
    dfs(1, 1, 1, 1);
    dfs(1, 1, 3, 1);
    cout << ans << endl;
    return 0;
}