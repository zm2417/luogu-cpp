#include <iostream>
#include <string>
using namespace std;

int N, L;
long long I;
long long c[32][32];
string ans;

void init_c()
{
    for (int i = 1; i < 32; i++)
    {
        c[i][0] = 1;
        c[0][i] = 1;
        for (int j = 1; j <= i; j++)
        {
            if (i == j)
                c[i][j] = 1;
            else
                c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        }
    }

    for (int i = 1; i < 32; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            c[i][j] += c[i][j - 1];
        }
    }
}

void dfs(int l, int num, long long count)
{
    if (l == 0)
    {
        for (int i = 0; i < N - ans.length(); i++)
        {
            cout << '0';
        }
        cout << ans.c_str() << endl;
        exit(0);
    }
    // 0开头
    long long t = c[l - 1][num > 0 ? min(num, l - 1) : 0];
    if (l == 1)
        t = 1;
    if (count + t >= I)
    {
        ans += '0';
        dfs(l - 1, num, count);
    }
    else
    {
        ans += '1';
        dfs(l - 1, num - 1, count + t);
    }
}

int main()
{
    cin >> N >> L >> I;
    if (I == 1)
    {
        printf("%0*d", N, 0);
        return 0;
    }
    long long count = 1;
    init_c();
    for (int l = 1; l <= N; l++)
    {
        long long t = 0;
        if (l == 1)
        {
            t++;
        }
        else
        {
            t = c[l - 1][min(l - 1, L - 1)];
        }
        if (count + t >= I)
        {
            ans += '1';
            dfs(l - 1, L - 1, count);
        }
        else
        {
            count += t;
        }
        // cout << l << ' ' << count << ' ' << t << endl;
    }
    return 0;
}