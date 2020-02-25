#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
bool d[12][12], vis[11][11][4][11][11][4];
int fx, fy, fi, fj;
int ct, ft;

void dfs(int p)
{
    if (fx == fi && fy == fj)
    {
        cout << p << endl;
        exit(0);
    }
    if (vis[fx][fy][ct][fi][fj][ft] == false)
    {
        cout << 0 << endl;
        exit(0);
    }
    vis[fx][fy][ct][fi][fj][ft] = false;
    if (!d[fx + dx[ct]][fy + dy[ct]])
    {
        ct++;
        if (ct == 4)
            ct = 0;
    }
    else
    {
        fx += dx[ct], fy += dy[ct];
    }

    if (!d[fi + dx[ft]][fj + dy[ft]])
    {
        ft++;
        if (ft == 4)
            ft = 0;
    }
    else
    {
        fi += dx[ft], fj += dy[ft];
    }
    dfs(p + 1);
}

int main()
{
    memset(d, false, sizeof(d));
    for (int i = 1; i <= 10; i++)
    {
        string t;
        cin >> t;
        for (int j = 0; j < 10; j++)
        {
            if (t[j] == '.')
                d[i][j + 1] = true;
            else if (t[j] == '*')
            {
                d[i][j + 1] = false;
            }
            else if (t[j] == 'F')
            {
                fx = i, fy = j + 1, d[i][j + 1] = true;
            }
            else
            {
                fi = i, fj = j + 1, d[i][j + 1] = true;
            }
        }
    }
    ct = ft = 0;
    memset(vis, true, sizeof(vis));
    dfs(0);
    return 0;
}