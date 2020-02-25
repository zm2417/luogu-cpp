#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int d[11][11];

int main()
{
    cout << 10 << ' ' << 10 << endl;
    cout << 80 << endl;
    int p = 0;
    for (int i = 0; p < 80; i++)
    {
        int x = rand() % 11, y = rand() % 11;
        if (d[x][y] == 0)
        {
            d[x][y] = 1;
            cout << x << ' ' << y << endl;
            p++;
        }
    }
    cout << 3 << endl;
}