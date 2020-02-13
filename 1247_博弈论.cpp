#include <iostream>
using namespace std;

int k, d[500005];

int main()
{
    cin >> k;
    int check = 0;
    for (int i = 1; i <= k; i++)
    {
        cin >> d[i];
        check ^= d[i];
    }
    if (check == 0)
    {
        cout << "lose" << endl;
        return 0;
    }
    for (int i = 1; i <= k; i++)
    {
        if ((check ^ d[i]) < d[i])
        {
            cout << d[i] - (check ^ d[i]) << ' ' << i << endl;
            for (int j = 1; j <= k; j++)
            {
                if (i == j)
                    cout << (check ^ d[i]) << ' ';
                else
                    cout << d[j] << ' ';
            }
            break;
        }
    }
    return 0;
}