#include <iostream>
using namespace std;

int n;
int d[105][105];
int con[105][105];
int used[105];

void dfs(int p)
{
    used[p] = 1;
    for (int i = 1; i <= 100; i++)
    {
        if (con[p][i] = 1 && used[i] != 1)
        {
            dfs(i);
            for (int j = 1; j <= 100; j++)
            {
                d[p][j] += d[i][j];
            }
        }
    }
}

int main()
{
    cin >> n;
    int i, j, p;
    for (int l = 0; l < n; l++)
    {
        cin >> i >> j >> p;
        d[i][j] = p;
    }
    for (i = 1; i <= 100; i++)
    {
        for (j = 1; j <= 100; j++)
        {
            if (d[i][j] > 50)
                con[i][j] = 1;
        }
    }
    for (i = 1; i <= 100; i++)
    {
        dfs(i);
    }
    for (i = 1; i <= 100; i++)
    {
        for (j = 1; j <= 100; j++)
        {
            if (d[i][j] > 50)
                cout << i << ' ' << j << endl;
        }
    }
    return 0;
}