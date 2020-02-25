#include <iostream>
#include <cstring>
using namespace std;

const int maxINf = 165;
int n;
int d[maxINf];
int temp[2];

bool getMin(int i, int j, int x, int y)
{
    return i * y > j * x;
}

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    cin >> n;
    cout << "0/1" << endl;
    for (int i = 1; i <= n; i++)
    {
        d[i] = n;
    }
    int prex = -1, prey = -1;
    while (true)
    {
        temp[0] = 1;
        temp[1] = d[1];
        int p = 1;
        for (int i = 2; i <= n; i++)
        {
            if (getMin(temp[0], temp[1], i, d[i]))
            {
                temp[0] = i;
                temp[1] = d[i];
                p = i;
            }
        }
        d[p]--;
        int g = gcd(temp[0], temp[1]);
        temp[0] /= g, temp[1] /= g;
        if (temp[0] == prex && temp[1] == prey)
        {
            continue;
        }
        prex = temp[0], prey = temp[1];
        cout << prex << '/' << prey / g << endl;
        if (temp[0] == temp[1])
        {
            return 0;
        }
    }
    // cout << "1/1" << endl;
    return 0;
}