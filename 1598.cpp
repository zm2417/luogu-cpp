#include <iostream>
#include <string>
using namespace std;

int d[26];

int main()
{
    string s;
    int maxCount = 0;
    while (cin >> s)
    {
        for (int i = 0; i < s.size(); i++)
        {
            d[s[i] - 'A']++;
        }
    }
    for (int i = 0; i < 26; i++)
    {
        maxCount = max(maxCount, d[i]);
    }
    int t = maxCount;
    for (int i = 0; i < maxCount; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (d[j] >= t)
                cout << "* ";
            else
            {
                cout << "  ";
            }
        }
        t--;
        cout << endl;
    }
    for (int i = 0; i < 26; i++)
    {
        cout << (char)('A'+i) << ' ';
    }
}