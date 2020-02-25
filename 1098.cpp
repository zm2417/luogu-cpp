#include <iostream>
#include <string>
using namespace std;

bool isNumber(char t)
{
    return t >= '0' && t <= '9';
}

bool isLetter(char t)
{
    return t >= 'a' && t <= 'z';
}

int main()
{
    int p1, p2, p3;
    cin >> p1 >> p2 >> p3;
    string d;
    cin >> d;
    for (int i = 0; i < d.size(); i++)
    {
        char t = d[i];
        if (isNumber(t) || isLetter(t))
        {
            cout << t;
        }
        else
        {
            if (i == 0 || i == d.size() - 1 || d[i - 1] == '-' || d[i + 1] == '-' || (isNumber(d[i - 1]) && isLetter(d[i + 1])) || (isLetter(d[i - 1]) && isNumber(d[i + 1])) || d[i - 1] >= d[i + 1])
                cout << t;
            else if (d[i - 1] + 1 < d[i + 1])
            {
                if (p3 == 1)
                {
                    for (char c = d[i - 1] + 1; c < d[i + 1]; c++)
                    {
                        char t = c;
                        if (p1 == 2 && isLetter(t))
                        {
                            t -= 32;
                        }
                        else if (p1 == 3)
                        {
                            t = '*';
                        }

                        for (int i = 0; i < p2; i++)
                        {
                            cout << t;
                        }
                    }
                }
                else
                {
                    // cout << endl
                    //      << d[i + 1] << ' ' << d[i - 1] << endl;
                    for (char c = d[i + 1] - 1; c > d[i - 1]; c--)
                    {
                        char t = c;
                        if (p1 == 2 && isLetter(t))
                        {
                            t -= 32;
                        }
                        else if (p1 == 3)
                        {
                            t = '*';
                        }
                        for (int i = 0; i < p2; i++)
                        {
                            cout << t;
                        }
                    }
                }
            }
        }
    }
    return 0;
}