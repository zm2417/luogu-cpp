#include <iostream>
#include <string>
#include <set>
using namespace std;

const int maxP = 505;
set<string> p[11];
string s;
int dp[200005];
int m;
int ans;

int main()
{
    int i = 0;
    string t;
    while (cin >> t)
    {
        if (t.size() == 1 && t[0] == '.')
            break;
        p[t.size()].insert(t);
        m = max(m, (int)t.size());
    }
    dp[0] = 1;
    s = " ";
    while (cin >> t)
    {
        s += t;
    }
    for (int i = 1; i < s.size(); i++)
    {
        for (int j = 1; j <= m && i >= j; j++)
        {
            t = s.substr(i - j + 1, j);
            if(p[j].find(t) != p[j].end() && dp[i-j] == 1)
            {
                dp[i] = 1;
                ans = max(ans,i);
                break;
            }
        }
    }
    cout << ans;
    return 0;
}