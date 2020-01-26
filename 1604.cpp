#include <iostream>
#include <string>
using namespace std;

int n;

int getInt(char c)
{
    if(c >= '0' && c <= '9')
    {
        return c -'0';
    }else
    {
        return c - 'A' + 10;
    }
    
}

char getChar(int x)
{
    if(x >=0 && x <= 9)
    {
        return x + '0';
    }else
    {
        return x - 10 + 'A';
    }
    
}

int add(char c1,char c2)
{
    return getInt(c1) + getInt(c2);
}

int main()
{
    string s1, s2;
    cin >> n >> s1 >> s2;
    int p = 1;
    string ans;
    int jinwei = 0;
    int size1 = s1.size(),size2 = s2.size();
    while (p <= s1.size() || p <= s2.size())
    {
        int x = 0;
        if(p <= s1.size() && p <= s2.size())
        {
            x = add(s1[size1 - p],s2[size2 - p]);
        }else if (p <= s1.size())
        {
            x = getInt(s1[size1 - p]);
        }else
        {
            x = getInt(s2[size2 - p]);
        }
        x += jinwei;
        ans.push_back(getChar(x % n));
        jinwei = x / n;
        p++;
    }
    while (jinwei != 0)
    {
        ans.push_back(getChar(jinwei % n));
        jinwei /= n;
    }
    for (int i = ans.size() - 1; i >=0; i--)
    {
        cout << ans[i];
    }
    return 0;
}