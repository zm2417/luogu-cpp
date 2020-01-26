#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

double N, d[16][2], used[16];
double len[16][16], ans = 1231234424.0;

void dfs(int step, int p, double l)
{
    if (l >= ans)
    {
        return;
    }
    if (step == N)
    {
        ans = min(ans, l);
        return;
    }
    for (int i = 1; i <= N; i++) 
        if (!used[i])            
        {
            used[i] = 1;                     
            dfs(step + 1, i, l + len[p][i]); 
            used[i] = 0;                     
        }
}

int main()
{
    cin >> N;
    d[0][0] = 0, d[0][1] = 0;
    for (int i = 1; i <= N; i++)
    {
        cin >> d[i][0] >> d[i][1];
    }

    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            len[i][j] = sqrt((d[i][0] - d[j][0]) * (d[i][0] - d[j][0]) + (d[i][1] - d[j][1]) * (d[i][1] - d[j][1]));
        }
    }

    dfs(0,0,0.0);   
    printf("%.2f",ans);
    return 0;
}