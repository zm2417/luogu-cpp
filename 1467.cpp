#include <iostream>
#include <cstring>
using namespace std;

long long m;
int d[40], used[40];
int dplicate[10];

bool check(int x)
{
    int p = 0;
    while (x)
    {
        if(dplicate[x % 10] == 1)
            return false;
        dplicate[x % 10] = 1;
        d[p++] = x % 10;
        x /= 10;
    }
    int i = p-1;
    while (true)
    {
        if (used[i] != 0)
            break;
        used[i] = 1;
        i = ((i - d[i]) % p + p) % p;
    }
    if(i != p-1)
        return false;
    for (int j = 0; j < p; j++)
    {
        if (used[j] == 0)
            return false;
    }
    return true;
}

int main()
{
    cin >> m;
    while (true)
    {
        m++;
        memset(used, 0, sizeof(used));
        memset(dplicate,0,sizeof(dplicate));
        dplicate[0] = 1;
        if (check(m))
        {
            cout << m << endl;
            return 0;
        }
    }
}