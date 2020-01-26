#include <iostream>
using namespace std;

int n, m;
char d[20];

void check()
{
    // for (int i = 1; i <= m; i++)
    //     {
    //         cout << d[i];
    //     }
    //     cout << endl;
    int pre = 0, cur = 0;
    int op = 1;
    for (int i = 1; i <= m; i++)
    {
        if (d[i] >= '0' && d[i] <= '9')
        {
            cur += (d[i] - '0');
        }
        else if (d[i] == ' ')
        {
            cur *= 10;
        }
        else
        {
            pre += op * cur;
            cur = 0;
            if (d[i] == '+')
                op = 1;
            else if (d[i] == '-')
            {
                op = -1;
            }
        }
    }
    pre += op * cur;
    // cout << pre;
    if (pre == 0)
    {
        for (int i = 1; i <= m; i++)
        {
            cout << d[i];
        }
        cout << endl;
    }
}

void dfs(int p)
{
    if (p > n + n - 1)
    {
        check();
        return;
    }
    if (p % 2 == 0)
    {
        d[p] = ' ';
        dfs(p + 1);
        d[p] = '+';
        dfs(p + 1);
        d[p] = '-';
        dfs(p + 1);
    }
    else
    {
        d[p] =(char)( '0' + (p / 2 + 1));
        dfs(p+1);
    }
}

int main()
{
    cin >> n;
    m = n + n - 1;
    d[1] = '1';
    dfs(2);

    // check();
    return 0;
}