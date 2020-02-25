#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

bool comp(int a[], int b[])
{
    return a[1] < b[1];
}

int main()
{
    int n;
    cin >> n;
    int **d = new int *[n];
    for (int i = 0; i < n; i++)
    {
        int *t = new int[2];
        cin >> t[1];
        t[0] = i;
        d[i] = t;
    }

    sort(d, d + n, comp);

    int ans = 0;
    long long time = 0;
    long long sum = 0;
    cout << d[0][0] + 1 << ' ';
    for (int i = 1; i < n; i++)
    {
        cout << d[i][0] + 1 << ' ';
        sum += d[i-1][1];
        time += sum;
    }
    cout << endl;
    printf("%.2f", (double)time*1.0 / n);

    return 0;
}