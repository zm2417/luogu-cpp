#include <iostream>
using namespace std;

int main()
{
    int m, s, t;
    cin >> m >> s >> t;

    int s1 = 0, s2 = 0; // s1:闪,s2:跑
    for (int i = 1; i <= t; i++)
    {
        s2 += 17;
        if (m >= 10)
        {
            s1 += 60;
            m -= 10;
        }
        else
        {
            m += 4;
        }
        if (s1 > s2)
        {
            s2 = s1;
        }
        if (s2 >= s)
        {
            cout << "Yes" << endl
                 << i;
            return 0;
        }
    }
    cout << "No" << endl
         << max(s1, s2);
    return 0;
}