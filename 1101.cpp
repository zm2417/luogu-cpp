#include <iostream>
#include <string>
using namespace std;

string target = "yizhong";
char ret[100][100];

bool dfs(string d[], int i, int j, int p1, int p2, int c)
{
    if (c == target.size())
    {
        return true;
    }
    if (i >= 0 && i < d->size() && j >= 0 && j < d->size() && d[i][j] == target[c] && ret[i][j] == '*')
    {
        ret[i][j] = target[c];
        bool r = dfs(d, i + p1, j + p2, p1, p2, c + 1);
        if (!r)
        {
            ret[i][j] = '*';
        }
        return r;
    }
    else
    {
        return false;
    }
}

int main()
{
    int n;
    cin >> n;

    string d[n];
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ret[i][j] = '*';
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dfs(d, i, j, -1, 0, 0);
            dfs(d, i, j, -1, -1, 0);
            dfs(d, i, j, -1, 1, 0);
            dfs(d, i, j, 0, -1, 0);
            dfs(d, i, j, 0, 1, 0);
            dfs(d, i, j, 1, -1, 0);
            dfs(d, i, j, 1, 0, 0);
            dfs(d, i, j, 1, 1, 0);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ret[i][j];
        }
        cout << endl;
    }

    return 0;
}