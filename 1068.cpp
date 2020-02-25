#include <iostream>
#include <algorithm>
using namespace std;

bool comp(int a[], int b[])
{
    if (a[1] != b[1])
    {
        return a[1] > b[1];
    }
    else
    {
        return a[0] < b[0];
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    int users = m * 1.5;
    int **d = new int *[n];
    for (int i = 0; i < n; i++)
    {
        int *t = new int[2];
        cin >> t[0] >> t[1];
        d[i] = t;
    }
    sort(d, d + n, comp);
    while (users < n && d[users - 1][1] == d[users][1])
    {
        users++;
    }
    cout << d[users - 1][1] << ' ' << users << endl;
    for (int i = 0; i < users; i++)
    {
        cout << d[i][0] << ' ' << d[i][1] << endl;
    }

    return 0;
}