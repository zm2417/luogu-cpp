#include <iostream>
using namespace std;

int main()
{
    int n,m,k;
    cin >> n >> m >> k;
    int a[k];
    for (int i = 0; i < k; i++)
    {
        cin >> a[i];
    }
    int p = 0;
    int j = 0;
    int second = 0;
    while (p < n)
    {
        p += m;
        while (a[j] < p)
        {
            j++;
        }
        if(a[j] == p)
        {
            m++;
        }
        second++;
    }
    cout << second;
    return 0;
}