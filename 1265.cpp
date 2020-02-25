#include <iostream>
#include <cmath>
using namespace std;
// #define double long double

const int maxInf = 5010;
int n, d[maxInf][2], vis[maxInf];
double dis[maxInf];
double ans;

double cal(int i, int j)
{
    return sqrt((double)(d[i][0] - d[j][0]) * (d[i][0] - d[j][0]) + (double)(d[i][1] - d[j][1]) * (d[i][1] - d[j][1]));
}

void prime()
{
    for (int i = 1; i < n; i++)
    {
        dis[i] = cal(i, 0);
    }
    vis[0] = 1;
    int pos = -1;
    for (int j = 1; j < n; j++)
    {
        double minDis = 1e8;
        for (int i = 0; i < n; i++)
        {
            if (minDis > dis[i] && vis[i] == 0)
            {
                minDis = dis[i];
                pos = i;
            }
        }
        ans += minDis;
        // if (minDis > 92439881.37)
        // {
        //     cout << minDis << ' ' << pos << endl;
        // }
        vis[pos] = 1;
        for (int i = 0; i < n; i++)
        {
            double d = cal(pos, i);
            if (d < dis[i])
                dis[i] = d;
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> d[i][0] >> d[i][1];
    }
    prime();
    printf("%.2f", ans);
    return 0;
}