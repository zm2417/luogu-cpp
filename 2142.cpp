#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int n1 = s1.size(), n2 = s2.size();
    bool flag = true;
    if (n2 > n1)
    {
        swap(n1, n2);
        swap(s1, s2);
        flag = false;
    }
    else if (n1 == n2)
    {
        bool diff = false;
        for (int i = 0; i < n1; i++)
        {
            if (s1[i] < s2[i])
            {
                swap(n1, n2);
                swap(s1, s2);
                flag = false;
                diff = true;
                break;
            }else if(s1[i] > s2[i])
            {
                diff = true;
                break;
            }
        }
        if(!diff)
        {
            cout << '0';
            return 0;
        }
    }

    int p = 0;
    string result;
    int i = 1;
    for (; i <= min(n1, n2); i++)
    {
        int x = s1[n1 - i] - '0' - s2[n2 - i] + '0' + p;
        if (x < 0)
        {
            p = -1;
            if (i != n1)
                x += 10;
            else
            {
                x *= -1;
            }
        }
        else
        {
            p = 0;
        }
        result.push_back((char)(x + '0'));
    }
    while (i <= n1)
    {
        int x = s1[n1 - i] - '0' + p;
        if (x < 0)
        {
            p = -1;
            x += 10;
        }
        else
        {
            p = 0;
        }
        result.push_back((char)(x + '0'));
        i++;
    }
    while (i <= n2)
    {
        int x = s2[n2 - i] - '0';
        p = -1;
        result.push_back(x + '0');
        i++;
    }
    if (!flag)
        cout << '-';
    bool mask = true;
    for (int i = result.size() - 1; i >= 0; i--)
    {
        if (mask && result[i] == '0')
            continue;
        else
        {
            mask = false;
        }

        cout << result[i];
    }
}