#include <iostream>
#include <cstring>
using namespace std;

int v, g;
int d[30], s[30][30];
int used[30];
bool mask = false;
int temp[30];

void dfs(int p, int c, int k)
{
    if (p == 0)
    {
        memset(temp, 0, sizeof(temp));
        for (int i = 1; i <= g; i++)
        {
            if (used[i] == 1)
            {
                for (int j = 1; j <= v; j++)
                {
                    temp[j] += s[i][j];
                }
            }
        }
        for (int i = 1; i <= v; i++)
        {
            if (temp[i] < d[i])
                return;
        }
        cout << c << ' ';
        for (int j = 1; j <= g; j++)
        {
            if (used[j] == 1)
            {
                cout << j << ' ';
            }
        }
        exit(0);
    }
    for (int i = k + 1; i <= g; i++)
    {
        if (used[i] == 0)
        {
            used[i] = 1;
            dfs(p - 1, c, i);
            used[i] = 0;
        }
    }
}

int main()
{
    cin >> v;
    for (int i = 1; i <= v; i++)
    {
        cin >> d[i];
    }
    cin >> g;
    for (int i = 1; i <= g; i++)
    {
        for (int j = 1; j <= v; j++)
        {
            cin >> s[i][j];
        }
    }
    for (int i = 1; i <= g; i++)
    {
        dfs(i, i, 0);
    }
    return 0;
}