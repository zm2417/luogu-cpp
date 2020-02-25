#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

double n, x1, ya, x2, y2, d[6][2], r[6], pi = 3.1415926535, maxSize;
int used[6];

double cal(int p)
{
    double s1 = min(abs(x1 - d[p][0]), abs(x2 - d[p][0]));
    double s2 = min(abs(ya - d[p][1]), abs(y2 - d[p][1]));
    double s = min(s1, s2);
    for (int i = 0; i < n; i++)
    {
        if (used[i] == 1 && i != p)
        {
            double t = sqrt((d[i][0] - d[p][0]) * (d[i][0] - d[p][0]) + (d[i][1] - d[p][1]) * (d[i][1] - d[p][1]));
            s = min(s, max(t - r[i], 0.0));
        }
    }
    return s;
}

void dfs(int k, double sum)
{
    if (k > n)
    {
        maxSize = max(maxSize, sum);
    }
    for (int i = 0; i < n; i++)
    {
        if (used[i] == 0)
        {
            used[i] = 1;
            r[i] = cal(i);
            dfs(k + 1, sum + r[i] * r[i] * pi);
            used[i] = 0;
        }
    }
}

int main()
{
    cin >> n >> x1 >> ya >> x2 >> y2;
    for (int i = 0; i < n; i++)
    {
        cin >> d[i][0] >> d[i][1];
    }
    dfs(1, 0);
    double ss = abs(x1 - x2) * abs(ya - y2);
    printf("%d", int(ss - maxSize + 0.5));
    return 0;
}