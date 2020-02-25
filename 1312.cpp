#include <iostream>
using namespace std;

int n;
int d[7][5], ans[6][3], last[10][10][10], used[10][10];
bool mask = false;

bool check()
{
    for (int j = 0; j < 5; j++)
        if (d[6][j] != 0)
            return false;
    return true;
}
void copy(int x)
{
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 5; j++)
            last[x][i][j] = d[i][j];
}
// bool checkCanRemove(int i, int j)
// {
//     if (i > 1 && i + 1 < 7 && d[i - 1][j] == d[i][j] && d[i][j] == d[i + 1][j])
//     {
//         used[i - 1][j] = 1, used[i][j] = 1, used[i + 1][j] = 1;
//     }
// }
bool remove()
{
    bool flag = true;
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 5; j++)
        {
            if (d[i][j] == 0)
                continue;
            if (i > 1 && i + 1 < 7 && d[i - 1][j] == d[i][j] && d[i][j] == d[i + 1][j])
            {
                used[i - 1][j] = 1, used[i][j] = 1, used[i + 1][j] = 1;
                flag = false;
            }
            if (j - 1 >= 0 && j + 1 < 5 && d[i][j - 1] == d[i][j] && d[i][j] == d[i][j + 1])
            {
                used[i][j - 1] = 1, used[i][j] = 1, used[i][j + 1] = 1;
                flag = false;
            }
        }
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 5; j++)
        {
            if (used[i][j] == 1)
            {
                d[i][j] = 0;
                used[i][j] = 0;
            }
        }
    return flag;
}
void update()
{
    // for (int i = 0; i < 7; i++)
    // {
    //     for (int j = 0; j < 5; j++)
    //     {
    //         cout << d[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    for (int i = 0; i < 5; i++)
    {
        int wow = 0;
        for (int j = 6; j >= 0; j--)
        {
            if (d[j][i] == 0)
                wow++;
            else
            {
                if (wow == 0)
                    continue;
                d[j + wow][i] = d[j][i];
                d[j][i] = 0;
            }
        }
    }
    // for (int i = 0; i < 7; i++)
    // {
    //     for (int j = 0; j < 5; j++)
    //     {
    //         cout << d[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
}
void move(int x, int y, int p)
{
    int temp = d[x][y];
    d[x][y] = d[x][y + p];
    d[x][y + p] = temp;
    int i = 1;
    update();
    while (!remove())
        update();
}

void dfs(int c)
{
    if (check())
    {
        for (int i = 1; i <= n; i++)
        {
            if (ans[i][2] == 0)
                break;
            cout << ans[i][1] << ' ' << 6 - ans[i][0] << ' ' << ans[i][2] << endl;
        }
        exit(0);
    }
    if (c > n)
        return;

    copy(c);
    for (int j = 0; j < 5; j++)
    {
        for (int i = 6; i >= 0; i--)
        {
            if (d[i][j] != 0)
            {
                //右移
                if (j + 1 < 5 && d[i][j] != d[i][j + 1])
                {
                    move(i, j, 1);
                    ans[c][0] = i, ans[c][1] = j, ans[c][2] = 1;
                    dfs(c + 1);
                    ans[c][0] = 0, ans[c][1] = 0, ans[c][2] = 0;
                    for (int i = 0; i < 7; i++)
                    {
                        for (int j = 0; j < 5; j++)
                        {
                            d[i][j] = last[c][i][j];
                        }
                    }
                }
                // 左移
                if (j - 1 >= 0 && d[i][j - 1] == 0)
                {
                    move(i, j, -1);
                    ans[c][0] = i, ans[c][1] = j, ans[c][2] = -1;
                    dfs(c + 1);
                    ans[c][0] = 0, ans[c][1] = 0, ans[c][2] = 0;
                    for (int i = 0; i < 7; i++)
                    {
                        for (int j = 0; j < 5; j++)
                        {
                            d[i][j] = last[c][i][j];
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 6;; j--)
        {
            int k;
            cin >> k;
            if (k != 0)
            {
                d[j][i] = k;
            }
            else
            {
                break;
            }
        }
    }
    dfs(1);
    cout << -1;
    return 0;
}