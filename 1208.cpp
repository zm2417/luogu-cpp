#include <iostream>
#include <algorithm>
using namespace std;

bool comp(int a[], int b[])
{
    return a[0] < b[0];
}

int main()
{
    int n, m;
    cin >> n >> m;
    int **d = new int *[m];
    for (int i = 0; i < m; i++)
    {
        int *t = new int[2];
        cin >> t[0] >> t[1];
        d[i] = t;
    }

    sort(d, d + m, comp);
    int pay = 0, r = 0;
    for (int i = 0; i < m; i++)
    {
        if (r + d[i][1] >= n)
        {
            pay += d[i][0] * (n - r);
            cout << pay;
            return 0;
        }
        else
        {
            pay += d[i][0] * d[i][1];
            r += d[i][1];
        }
    }
    cout << pay;
}