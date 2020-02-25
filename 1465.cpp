#include <iostream>
#include <string>
using namespace std;

int n;
int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
string strs[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
int d[7];

void init(string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        switch (s[i])
        {
        case 'I':
            d[0]++;
            break;
        case 'V':
            d[1]++;
            break;
        case 'X':
            d[2]++;
            break;
        case 'L':
            d[3]++;
            break;
        case 'C':
            d[4]++;
            break;
        case 'D':
            d[5]++;
            break;
        case 'M':
            d[6]++;
            break;
        default:
            break;
        }
    }
}

void IntTorRoma(int num)
{
    // string res;
    for (int i = 0; i < 13; i++)
    {
        while (num >= values[i])
        {
            init(strs[i]);
            // res += strs[i];
            num -= values[i];
        }
    }
    // cout << res.c_str() << endl;
    // return res;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        IntTorRoma(i);
    }
    if (d[0] > 0)
        cout << "I " << d[0] << endl;
    if (d[1] > 0)
        cout << "V " << d[1] << endl;
    if (d[2] > 0)
        cout << "X " << d[2] << endl;
    if (d[3] > 0)
        cout << "L " << d[3] << endl;
    if (d[4] > 0)
        cout << "C " << d[4] << endl;
    if (d[5] > 0)
        cout << "D " << d[5] << endl;
    if (d[6] > 0)
        cout << "M " << d[6] << endl;
}