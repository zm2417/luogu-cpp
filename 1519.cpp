#include <iostream>
#include <cstdio>
#define LL unsigned long long
using namespace std;
int m, n, mm, i, j, k, ss, l, r;
int a[310][310];
int f[310][310] = {0};
int dx[5] = {0, -2, 2, 0, 0};
int dy[5] = {0, 0, 0, -2, 2};
int ddx[5] = {0, -1, 1, 0, 0};
int ddy[5] = {0, 0, 0, -1, 1};
struct he
{
    int x, y;
    int t;
} d[100000];
char x[500];

void bfs()
{
    while (l < r)
    {
        l++;
        for (i = 1; i <= 4; i++) //四个方向
        {
            if (a[d[l].x + ddx[i]][d[l].y + ddy[i]] == 0 &&   //没墙挡着
                d[l].x + dx[i] <= n && d[l].y + dy[i] <= m && //在范围内
                d[l].x + dx[i] >= 1 && d[l].y + dy[i] >= 1 && //在范围内
                f[d[l].x + dx[i]][d[l].y + dy[i]] == 0)       //没入队
            {
                r++; //入队
                ss--;
                d[r].x = d[l].x + dx[i]; //坐标
                d[r].y = d[l].y + dy[i];
                d[r].t = d[l].t + 1; //步数
                f[d[r].x][d[r].y] = 1;
                if (d[r].t > mm)
                    mm = d[r].t; //找最大步数
            }
        }
    }
}

int main()
{
    cin >> m >> n;
    cin.getline(x, 500);
    ss = n * m; //格子数量
    m = m * 2 + 1;
    n = n * 2 + 1;
    for (i = 0; i <= n + 3; i++)
    {
        for (j = 0; j <= m + 3; j++)
            a[i][j] = 1; //初始化
    }
    for (i = 1; i <= n; i++)
    {
        char c[500];
        cin.getline(c, 500); //读入
        for (j = 1; j <= m; j++)
        {
            if (c[j - 1] != '+' && c[j - 1] != '-' && c[j - 1] != '|')
                a[i][j] = 0;
        }
    }

    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            f[i][j] = 0; //初始化

    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            if ((i == 1) || (j == 1) || (i == n) || (j == m)) //在边框上
                if (a[i][j] == 0)                             //是出口
                {                                             //出口的外围赋初值的时候就变成墙了,所以保证只有一边为0
                    for (k = 1; k <= 4; k++)
                    {
                        if ((a[i + ddx[k]][j + ddy[k]] == 0) && //是格子
                            (i + ddx[k] >= 1) && (i + ddx[k] <= n) &&
                            (j + ddy[k] >= 1) && (j + ddy[k] <= m) &&
                            (f[i + ddx[k]][j + ddy[k]] == 0)) //没入队
                        {
                            r++;                 //入队
                            d[r].x = i + ddx[k]; //坐标
                            d[r].y = j + ddy[k];
                            d[r].t = 1;                    //步数
                            f[i + ddx[k]][j + ddy[k]] = 1; //标记
                            break;
                        }
                    }
                }
    mm = 1;
    bfs();
    printf("%d\n", mm); //输出
    return 0;
}