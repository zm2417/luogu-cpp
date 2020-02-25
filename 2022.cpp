#include <iostream>
#include <vector>
using namespace std;

const int maxINf = 10;
int k, m;
int d[maxINf];
int num;
vector<long long> s;

int main()
{
    cin >> k >> m;
    if (k % 10 == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    int t = k;
    while (t > 0)
    {
        d[++num] = t % 10;
        t /= 10;
    }
    long long j = 1;
    for (int i = 1; i <= num; i++)
    {
        s[i] = d[i];
        if (i == 0)
            j = d[i];
        else if (i == num)
        {
            j *= d[i];
            s[i]--;
        }
        else
        {
            j *= (d[i] + 1);
        }
    }
    if (j == m)
    {
        cout << k << endl;
        return 0;
    }
    else if (j > m)
    {
        cout << 0 << endl;
        return 0;
    }
}