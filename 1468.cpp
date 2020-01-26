#include <iostream>
#include <cstring>
#include <set>
#include <string>
using namespace std;

const int maxN = 105;
int n, c;
int open[maxN], close[maxN];
int d[maxN];
bool hava = false;

struct strComp
{
    bool operator()(const string &str1, const string &str2) const
    {
        for (int i = 1; i <= n; i++)
        {
            if (str1[i] != str2[i])
                return str1[i] < str2[i];
        }
        return str1.length() < str2.length();
    }
};
set<string> ans;

int change(int i)
{
    return i == 1 ? 0 : 1;
}
void b1()
{
    for (int i = 1; i <= n; i++)
        d[i] = change(d[i]);
}

void b2()
{
    for (int i = 1; i <= n; i += 2)
        d[i] = change(d[i]);
}

void b3()
{
    for (int i = 2; i <= n; i += 2)
        d[i] = change(d[i]);
}

void b4()
{
    for (int i = 1; i <= n; i += 3)
        d[i] = change(d[i]);
}

bool check()
{
    for (int i = 1; i <= n; i++)
    {
        if (open[i] == 1 && d[i] != 1)
            return false;
        if (close[i] == 1 && d[i] != 0)
            return false;
    }
    hava = true;
    string s;
    for (int i = 1; i <= n; i++)
    {
        s += to_string(d[i]);
    }
    if (ans.find(s) != ans.end())
        return true;
    ans.insert(s);
    // cout << s.c_str() << endl;
    return true;
}

void dfs(int p)
{
    if (p == 0)
    {
        check();
        return;
    }
    b1();
    dfs(p - 1);
    b1();

    b2();
    dfs(p - 1);
    b2();

    b3();
    dfs(p - 1);
    b3();

    b4();
    dfs(p - 1);
    b4();
}

int main()
{
    cin >> n >> c;
    int p;
    while (cin >> p)
    {
        if (p == -1)
            break;
        open[p] = 1;
    }
    while (cin >> p)
    {
        if (p == -1)
            break;
        close[p] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        d[i] = 1;
    }
    if (c <= 4)
        dfs(c);
    else
    {
        if (c % 2 == 0)
            dfs(4);
        else
        {
            dfs(3);
        }
    }
    if (!hava)
        cout << "IMPOSSIBLE" << endl;
    else
    {
        for (auto it = ans.cbegin(); it != ans.cend(); it++)
        {
            cout << *it << endl;
        }
    }

    return 0;
}