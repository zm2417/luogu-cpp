#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int n, d;
string ans;
int p[100001], f = 999999999;

int main()
{
    cin >> n >> d;
    int t = n / d;
    while (1)
    {
        ans = (char)(t % 10 + '0') + ans;
        t /= 10;
        if (t == 0)
            break;
    }
    ans += '.';
    n %= d;
    while (1)
    {
        if (p[n] != 0)
        {
            f = p[n];
            break;
        }
        else
        {
            p[n] = ans.length();
        }
        n *= 10;
        t = n / d;
        ans += (t + '0');
        n %= d;
        if (n == 0)
            break;
    }
    if (f != 999999999)
    {
        ans += ')';
    }
    int s = 0;
    for (int i = 0; i < ans.length(); i++)
    {
        if (i == f)
        {
            cout << '(';
            s++;
        }
        cout << ans[i];
        s++;
        if (s % 76 == 0 && s != 0)
            cout << endl;
    }
    return 0;
}