#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    string res;
    cin >> n;
    for (int i = n; i >= 0; i--)
    {
        int a;
        cin >> a;
        if (a != 0)
        {
            if (a > 0 && res.size() > 0)
                res += "+";
            if (i == 0)
            {
                res += to_string(a);
            }else if(i == 1)
            {
                if (a == 1)
                {
                    res += "x";
                }
                else if (a == -1)
                {
                    res += "-x";
                }
                else
                {
                    res += to_string(a) + "x";
                }
            }
            
            else
            {
                if (a == 1)
                {
                    res += "x^" + to_string(i);
                }
                else if (a == -1)
                {
                    res += "-x^" + to_string(i);
                }
                else
                {
                    res += to_string(a) + "x^" + to_string(i);
                }
            }
        }
    }
    cout << res.c_str();
    return 0;
}