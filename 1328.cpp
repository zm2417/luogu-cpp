#include <iostream>
using namespace std;

int helpe(int i, int j)
{
    if (i == j)
    {
        return 0;
    }
    if (i == 0)
    {
        if (j == 1 || j == 4)
            return -1;
    }
    else if (i == 1)
    {
        if (j == 2 || j == 4)
            return -1;
    }
    else if (i == 2)
    {
        if (j == 0 || j == 3)
            return -1;
    }
    else if (i == 3)
    {
        if (j == 0 || j == 1)
            return -1;
    }
    else if (i == 4)
    {
        if (j == 2 || j == 3)
            return -1;
    }
    return 1;
}

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    int ad[a], ab[b];
    for (int i = 0; i < a; i++)
    {
        cin >> ad[i];
    }
    for (int i = 0; i < b; i++)
    {
        cin >> ab[i];
    }

    int va = 0, vb = 0;
    int p1 = 0, p2 = 0;
    for (int i = 0; i < n; i++)
    {
        p1 %= a;
        p2 %= b;
        int t = helpe(ad[p1++],ab[p2++]);
        if( t == 1) va++;
        else if (t == -1)
        {
            vb++;
        }
    }
    cout << va << ' ' << vb;

    return 0; 
}