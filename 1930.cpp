#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int r, c;
int d[45][30][45][30];

struct Node
{
    int r, c;
    int d;
} node[2000], ki;

int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
queue<Node> q;
int vis[45][30];
int ans = 1000000000;

bool yuejie(int x, int y)
{
    return (x <= 0 || x > r || y <= 0 || y > c);
}

void bfs(int x, int y)
{
    memset(vis, 0, sizeof(vis));
    q.push((Node){x, y, 0});
    vis[x][y] = 1;
    d[x][y][x][y] = 0;
    while (!q.empty())
    {
        int tx = q.front().r, ty = q.front().c;
        d[tx][ty][x][y] = q.front().d;
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            int xx = tx + dx[i], yy = ty + dy[i];
            if (!yuejie(xx, yy) && vis[xx][yy] == 0)
            {
                vis[xx][yy] = 1;
                q.push((Node){xx, yy, d[tx][ty][x][y] + 1});
            }
        }
    }
}

int get(int x)
{
    return (x > 0) ? x : -x;
}

int main()
{
    cin >> r >> c;
    memset(d, 0x10f, sizeof(d));
    char a;
    int b;
    int st = 0;
    while (cin >> a >> b)
    {
        if (st == 0)
        {
            ki.c = a - 'A' + 1;
            ki.r = b;
        }
        else
        {
            node[st].r = b;
            node[st].c = a - 'A' + 1;
        }
        st++;
    }
    if (st < 2)
    {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            bfs(i, j);

    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
        {
            int sum = 0;
            for (int k = 1; k < st; k++)
                sum += d[node[k].r][node[k].c][i][j];
            for (int k = 1, summ = sum; k < st; k++, summ = sum)
            {
                summ -= d[node[k].r][node[k].c][i][j];
                for (int ii = max(1, ki.r - 3); ii <= min(r, ki.r + 3); ii++)
                    for (int jj = max(1, ki.c - 3); jj <= min(c, ki.c + 3); jj++)
                        ans = min(
                            summ + d[node[k].r][node[k].c][ii][jj] +
                                max(get(ii - ki.r), get(jj - ki.c)) + d[ii][jj][i][j],
                            ans);
            }
        }

    cout << ans << endl;
    return 0;
}