#include <iostream>
#include <string>
using namespace std;

int dl[700][2], dr[700][2];

int main()
{
    int n;
    string s;
    cin >> n >> s;
    s += s;

    for (int i = 0; i < 2 * n; i++)
    {
        int r = 0, b = 0;
        if (i != 0)
        {
            r = dl[i - 1][0], b = dl[i - 1][1];
        }
        if (s[i] == 'w')
        {
            dl[i][0] = r + 1, dl[i][1] = b + 1;
        }
        else if (s[i] == 'r')
        {
            dl[i][0] = r + 1, dl[i][1] = 0;
        }
        else
        {
            dl[i][1] = b + 1;
        }
    }

    for (int i = 2*n-1; i >= 0; i--)
    {
        int r = 0, b = 0;
        if (i != 2*n-1)
        {
            r = dr[i + 1][0], b = dr[i + 1][1];
        }
        if (s[i] == 'w')
        {
            dr[i][0] = r + 1, dr[i][1] = b + 1;
        }
        else if (s[i] == 'r')
        {
            dr[i][0] = r + 1, dr[i][1] = 0;
        }
        else
        {
            dr[i][1] = b + 1;
        }
    }

    int ans = 0;
    for (int i = 0; i < 2*n-1; i++)
    {
        int t = max(dl[i][0],dl[i][1]) + max(dr[i+1][0],dr[i+1][1]);
        ans = max(ans,t);
    }
    if(ans > n)
    {
        cout << n;
    }else
    {
        cout << ans;
    }
    
    // cout << ans;
    return 0;
}