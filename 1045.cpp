#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> v;
int P, a[1001];

void cf()
{
    int c[1001] = {0};
    for (int i = 1; i <= 500; i++)
        for (int j = 1; j <= 500; j++)
        {
            c[i + j - 1] += a[i] * a[j];
        }
    for (int i = 1; i <= 500; i++)
    {
        if (c[i] / 10 != 0)
        {
            c[i + 1] += c[i] / 10;
            c[i] = c[i] % 10;
        }
    }
    for (int i = 1; i <= 500; i++)
        a[i] = c[i];
}

void chen2()
{
    for (int i = 1; i <= 500; i++)
        a[i] *= 2;
    for (int i = 1; i <= 500; i++)
    {
        if (a[i] / 10 != 0)
        {
            a[i + 1] += a[i] / 10;
            a[i] = a[i] % 10;
        }
    }
}

void pow(int p)
{
    if (p / 2 != 1)
        pow(p / 2);
    cf();
    if (p % 2 == 1)
        chen2();
}

int main()
{
    cin >> P;
    cout << ceil(P * log10(2)) << endl;
    a[1] = 2;
    pow(P);
    a[1]--;
    for (int i = 500; i >= 1; i--)
    {
        cout << a[i];
        if ((i - 1) % 50 == 0)
            cout << endl;
    }
    return 0;
}