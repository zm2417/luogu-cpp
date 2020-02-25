#include <iostream>
using namespace std;

int n, m;
char c[1500][1500];
int used[1500][1500][3];
int op[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool dfs(int x, int y, int tx, int ty)
{
    if (used[x][y][0] == 1)
    {
        cout << "Yes" << endl;
        return true;
    }
    else
    {
        used[x][y][0] = 1, used[x][y][1] = tx, used[x][y][2] = ty;
        for (int i = 0; i < 4; i++)
        {
            int tx1 = tx + op[i][0], ty1 = ty + op[i][1];
            int j = (x + op[i][0] + n) % n, k = (y + op[i][1] + m) % m;
            if (c[j][k] == '.' && (used[j][k][1] != tx1 || used[j][k][2] != ty1))
            {
                if (dfs(j, k, tx1, ty1))
                {
                    return true;
                }
            }
        }
        // used[x][y][0] = 0;
    }
    return false;
}

int main()
{
    while (cin >> n)
    {
        cin >> m;
        int startN, startM;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                cin >> c[i][j];
                if (c[i][j] == 'S')
                {
                    startN = i;
                    startM = j;
                    c[i][j] = '.';
                }
                used[i][j][0] = 0;
                used[i][j][1] = 0;
                used[i][j][2] = 0;
            }
        bool mask = dfs(startN, startM, startN, startM);
        if (!mask)
        {
            cout << "No" << endl;
        }
    }
    return 0;
}