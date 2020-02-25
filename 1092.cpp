#include <iostream>
#include <string>
using namespace std;
int num[26], Next[26], nextUsed[26], used[26], n, Size = 0;
string s[3];

void dfs(int x)
{
    if (num[s[0][0] - 'A'] + num[s[1][0] - 'A'] >= n)
    {
        return;
    }
    for (int i = Size - 1; i >= 0; i--)
    {
        int a = num[s[0][i] - 'A'], b = num[s[1][i] - 'A'], c = num[s[2][i] - 'A'];
        if (a == -1 || b == -1 || c == -1)
        {
            continue;
        }
        if ((a + b) % n != c && (a + b + 1) % n != c)
        {
            return;
        }
    }
    if (x == n)
    {
        int jin = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            int a = num[s[0][i] - 'A'], b = num[s[1][i] - 'A'], c = num[s[2][i] - 'A'];
            if ((a + b + jin) % n != c)
            {
                return;
            }
            jin = (a + b + jin) / n;
        }
        for (int i = 0; i < n; i++)
        {
            cout << num[i] << ' ';
        }
        exit(0);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        if (used[i] == 0)
        {
            used[i] = 1;
            num[Next[x]] = i;
            dfs(x + 1);
            used[i] = 0;
            num[Next[x]] = -1;
        }
    }
}

int main()
{
    cin >> n;
    cin >> s[0] >> s[1] >> s[2];
    Size = s[0].size();
    int p = 0;
    for (int i = Size-1; i >= 0; i--)
    {
        for (int j = 0; j < 3; j++)
        // for (int j = 2; j >= 0; j--)
        {
            if (nextUsed[s[j][i] - 'A'] == 0)
            {
                nextUsed[s[j][i] - 'A'] = 1;
                Next[p++] = s[j][i] - 'A';
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        num[i] = -1;
    }
    dfs(0);
}