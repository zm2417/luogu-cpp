#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n;
int used[72][72], d[72][72], num[72];
string ans;

int index(char c)
{
    if (c >= 'a' && c <= 'z')
        return c - 'a' + 26;
    return c - 'A';
}
char getC(int p)
{
    if (p < 26)
    {
        return (char)(p + 'A');
    }
    return (char)(p + 'a' - 26);
}

void dfs(int p)
{
    for (int i = 0; i < 72; i++)
    {
        if (d[p][i] > 0)
        {
            d[p][i]--;
            d[i][p]--;
            dfs(i);
        }
    }
    ans.push_back(getC(p));
    return;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string t;
        cin >> t;
        int x = index(t[0]), y = index(t[1]);
        d[x][y]++;
        d[y][x]++;
        num[x]++;
        num[y]++;
    }
    int jishu = 0, h = -1;
    for (int i = 0; i < 72; i++)
    {
        if (num[i] % 2 == 1)
        {
            jishu++;
            if (h == -1)
                h = i;
        }
    }
    if (h == -1)
    {
        for (int i = 0; i < 72; i++)
        {
            if (num[i])
            {
                h = i;
                break;
            }
        }
    }
    if (jishu && jishu != 2)
    {
        cout << "No Solution";
        return 0;
    }
    dfs(h);
    if(ans.size() !=  n + 1)
    {
        cout << "No Solution";
        return 0;
    }
    for (int i = ans.size()-1; i >=0; i--)
    {
        cout << ans[i];
    }
    
    return 0;
}