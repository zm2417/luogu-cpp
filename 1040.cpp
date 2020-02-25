#include <iostream>
using namespace std;

int num[30][30], root[30][30];

void dfs(int i, int j)
{
    if (i <= j)
    {
        cout << root[i][j] << ' ';
        dfs(i, root[i][j] - 1);
        dfs(root[i][j] + 1, j);
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i <= n + 1; i++)
    {
        root[i][i] = i;
        for (int j = 0; j <= n + 1; j++)
        {
            num[i][j] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> num[i][i];
    }
    for (int j = 1; j <= n; j++)
    {
        for (int i = j - 1; i >= 1; i--)
        {
            for (int k = i; k <= j; k++)
            {
                if (num[i][j] < (num[i][k - 1] * num[k + 1][j] + num[k][k]))
                {
                    num[i][j] = num[i][k - 1] * num[k + 1][j] + num[k][k];
                    root[i][j] = k;
                }
            }
        }
    }
    cout << num[1][n] <<endl;
    dfs(1, n);
}