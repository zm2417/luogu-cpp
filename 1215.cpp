#include <iostream>
using namespace std;

const int maxInf = 22;
int a, b, c;
int d[maxInf][maxInf][maxInf];

void dfs(int i, int j, int k)
{
    if (i < 0 || i > a || j < 0 || j > b || k < 0 || k > c)
        return;
    if (d[i][j][k] == 1)
        return;
    d[i][j][k] = 1;
    // b -> a
    dfs(i + j, 0, k);
    dfs(a, i + j - a, k);
    // c -> a
    dfs(i + k, j, 0);
    dfs(a, j, k + i - a);

    // a -> b
    dfs(0, i + j, k);
    dfs(i + j - b, b, k);
    // c -> b
    dfs(i, j + k, 0);
    dfs(i, b, j + k - b);

    // a -> c
    dfs(0, j, i + k);
    dfs(i + k - c, j, c);
    // b -> c
    dfs(i, 0, j + k);
    dfs(i, j + k - c, c);
}

int main()
{
    cin >> a >> b >> c;
    dfs(0, 0, c);
    for (int i = 0; i <= c; i++)
    {
        if(d[0][c-i][i] == 1)
        {
            cout << i << ' ';
        }
    }
    return 0;
}