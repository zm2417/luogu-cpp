#include <iostream>
using namespace std;

int n;
int d[105][105];
int con[105];
int used[105];
int own[105];

void dfs(int p)
{
    if(used[p] == 1)
        return;
    used[p] = 1;
    for (int i = 1; i <= 100; i++)
    {
        con[i] += d[p][i];
        if(con[i] > 50)
        {
            own[i] = 1;
            dfs(i);
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
            used[j] = 0;
            con[j] = 0;
            own[j] = 0;
        }
        dfs(i);
        for (j = 1;j<=100;j++)
        {
            if(own[j] == 1&& i != j)
                cout << i << ' ' << j << endl;
        }
    }
    
    return 0;
}