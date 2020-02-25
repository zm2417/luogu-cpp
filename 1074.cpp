#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;

struct Cnt
{
    int h;
    int sum;
};

struct Node
{
    int x;
    int y;
    int cnt;
    int p;
};

int d[9][9], r[9][10], c[9][10], s[9][10], point = -1, nodeNumber = 0;
Node n[81];
Cnt cnt[9];

int pd[9][9] = {{1, 1, 1, 4, 4, 4, 7, 7, 7},
                {1, 1, 1, 4, 4, 4, 7, 7, 7},
                {1, 1, 1, 4, 4, 4, 7, 7, 7},
                {2, 2, 2, 5, 5, 5, 8, 8, 8},
                {2, 2, 2, 5, 5, 5, 8, 8, 8},
                {2, 2, 2, 5, 5, 5, 8, 8, 8},
                {3, 3, 3, 6, 6, 6, 9, 9, 9},
                {3, 3, 3, 6, 6, 6, 9, 9, 9},
                {3, 3, 3, 6, 6, 6, 9, 9, 9}};

int small(int i, int j)
{
    // return 3 * (i / 3) + j / 3;
    return pd[i][j] - 1;
}

int getPoint(int i, int j)
{
    if (i == 0 || i == 8 || j == 0 || j == 8)
        return 6;
    if (i == 1 || i == 7 || j == 1 || j == 7)
        return 7;
    if (i == 2 || i == 6 || j == 2 || j == 6)
        return 8;
    if (i == 3 || i == 5 || j == 3 || j == 5)
        return 9;
    if (i == 4 && j == 4)
        return 10;
    return 0;
}

void dfs(int p, int currentPoint)
{
    if (p == nodeNumber)
    {
        if (currentPoint > point)
            point = currentPoint;
        // point = max(point, currentPoint);
        return;
    }
    int i = n[p].x, j = n[p].y, g = small(i, j);
    if (d[i][j] == 0)
    {
        for (int k = 1; k <= 9; k++)
        {
            if (r[i][k] == 0 && c[j][k] == 0 && s[g][k] == 0)
            {
                r[i][k] = 1;
                c[j][k] = 1;
                s[g][k] = 1;
                dfs(p + 1, currentPoint + n[p].p * k);
                r[i][k] = 0;
                c[j][k] = 0;
                s[g][k] = 0;
            }
        }
    }
}

bool comp(Cnt x, Cnt y)
{
    return x.sum > y.sum;
}

int main()
{
    int temp[9] = {0};
    for (int i = 0; i < 9; i++)
    {
        Cnt cnt1 = {i, 0};
        for (int j = 0; j < 9; j++)
        {
            cin >> d[i][j];
            r[i][d[i][j]] = 1;
            c[j][d[i][j]] = 1;
            s[small(i, j)][d[i][j]] = 1;
            if (d[i][j] > 0)
                cnt1.sum++;
        }
        cnt[i] = cnt1;
    }

    sort(cnt, cnt + 9, comp);

    int source = 0;
    for (int k = 0; k < 9; k++)
    {
        int i = cnt[k].h;
        for (int j = 0; j < 9; j++)
        {
            if (d[i][j] != 0)
            {
                source += getPoint(i, j) * d[i][j];
            }
            else
            {
                int cnt = temp[i];
                Node temp = {i, j, cnt, getPoint(i, j)};
                n[nodeNumber++] = temp;
            }
        }
    }

    dfs(0, source);
    cout << point;
    return 0;
}