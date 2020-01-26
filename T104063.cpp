#include <iostream>
#include <algorithm>
using namespace std;

bool comp(int i,int j)
{
    return i > j;
}

int main()
{
    int n;
    cin >> n;
    int d[n];
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
    }
    sort(d,d+n,comp);
    long double e = 0.0;
    long double all = 0.0;
    for (int i = 0; i < n; i++)
    {
        all += d[i];
        // long double t = all * all /(i+1);
        // if(t >= e)
        // {
        //     e = t;
        // }else
        // {
        //     cout << e;
        //     return 0;
        // }
    }
    e = all * all / n * 1.0;
    cout << e;
    return 0;
}