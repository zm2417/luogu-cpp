#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1,s2;
    cin >> s1 >> s2;
    string result;
    int p = 0;
    int j = min(s1.size(),s2.size());
    int i = 1;
    for (; i <= j; i++)
    {
        int x = s1[s1.size() - i] - '0' + s2[s2.size() - i] - '0';
        result.push_back(((x+p) % 10) + '0');
        p = (x+p) / 10;
    }
    // cout<< result.size() << result.c_str() << endl;
    while (i <= s1.size())
    {   
        int x = s1[s1.size() - i] - '0';
        result.push_back('0'+((x+p) % 10));
        p = (x+p) / 10;
        i++;
    }
    // cout << result.c_str() << endl;
    while (i <= s2.size())
    {
        // i++;
        int x = s2[s2.size() - i] - '0';
        result.push_back('0' + ((x+p) % 10));
        p = (x+p) / 10;
        i++;
    }
    if(p != 0)
        result.push_back(p+'0');
    // cout << result.c_str() << endl;
    for (int i = result.size() - 1; i>=0; i--)
    {
        cout << result[i];
    }
    return 0;
}