#include <iostream>
#include <string>
using namespace std;

int judge(string &s1,string &s2)
{
    int size1 = s1.size(),size2 = s2.size();
    int ans = 1;
    if(s1[0] == '-'){
        ans *= -1;
        s1 = s1.substr(1);
    }
    if(s2[0] == '-'){
        ans *= -1;
        s2 = s2.substr(1);
    }
    return ans;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    if(s1[0] =='0' || s2[0] == '0')
    {
        cout << '0';
        return 0;
    }

    string ans;
    int p = 1;
    int fh = judge(s1,s2);
    while (p <= s2.size())
    {
        int j = 1;
        int jinwei = 0;
        string t;
        while (j <= s1.size())
        {
            int i = (s1[s1.size() - j] - '0') * (s2[s2.size() - p] - '0') + jinwei;
            t.push_back((i % 10) + '0');
            jinwei = i / 10;
            j++;
        }
        if (jinwei != 0)
        {
            while (jinwei != 0)
            {
                t.push_back((jinwei % 10)+'0');
                jinwei /= 10;
            }
        }
        int k = 0;
        int jinwei2 = 0;
        while (k < t.size() || k + p -1 < ans.size())
        {
            int i = 0;
            if (k < t.size() && k + p -1 < ans.size())
                i = (ans[k + p-1] - '0') + t[k] - '0' + jinwei2;
            else if (k < t.size())
            {
                i = t[k] - '0' + jinwei2;
            }
            else
            {
                i = (ans[k + p-1] - '0') + jinwei2;
            }
            if(k + p-1 < ans.size())
                ans[k + p-1] = (i % 10) + '0';
            else
            {
                ans.push_back((i % 10) + '0');
            }
            
            jinwei2 = i / 10;
            k++;
        }
        while (jinwei2 != 0)
        {
            ans.push_back((jinwei2 % 10) + '0');
            jinwei2 /= 10;
        }
        p++;
    }
    if(fh == -1)
        cout << '-';
    for (int i = ans.size() - 1; i>=0; i--)
    {
        cout << ans[i];
    }
    
    // cout << ans.c_str() << endl;
    return 0;
}
