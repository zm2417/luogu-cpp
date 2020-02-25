#include <iostream>
using namespace std;
int ans = 0;

void dfs(int i, int n, int s[], int m[], int d[], int cd[])
{
    if (i >= n)
    {
        if (ans < 3)
        {
            for (int j = 0; j < n; j++)
            {
                cout << s[j] + 1 << ' ';
            }
            cout << endl;
        }
        ans++;
        return;
    }
    for (int j = 0; j < n; j++)
    {
        if (m[j] == 0 && d[i - j + n] == 0 && cd[i + j] == 0)
        {
            s[i] = j, m[j] = 1, d[i - j + n] = 1, cd[i + j] = 1;
            dfs(i + 1, n, s, m, d, cd);
            m[j] = 0, d[i - j + n] = 0, cd[i + j] = 0;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    //行，对角线，斜对角线
    int m[n] = {0}, diagonal[2 * n] = {0}, clinodiagonal[2 * n] = {0}, s[n] = {0};
    dfs(0, n, s, m, diagonal, clinodiagonal);
    cout << ans;
    return 0;
}