#include<iostream>
using namespace std;

int n,d[105][105],ans,dis[105],used[105];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for(int j = 0;j<n;j++)
            cin >> d[i][j];
    }
    dis[0] = INT32_MAX;
    used[0] = 1;
    for (int i = 1; i < n; i++)
    {
        dis[i] = d[0][i];
    }
    int tot = n-1;
    while (tot-- > 0)
    {
        int minDis = INT32_MAX;
        int  p;
        for (int i = 0; i < n; i++)
        {
            if(minDis > dis[i])
            {
                minDis = dis[i];
                p = i;
            }
        }
        ans += minDis;
        dis[p] = INT32_MAX;
        used[p] = 1;
        for (int i = 0; i < n; i++)
        {
            if(dis[i] > d[i][p] && used[i] == 0)
            {
                dis[i] = d[i][p];
            }
        }
    }
    cout << ans;
    return 0;
}