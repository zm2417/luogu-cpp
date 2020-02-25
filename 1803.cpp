#include <iostream>
#include <algorithm>
using namespace std;

bool comp(int i[], int j[])
{
    return i[1] < j[1];
}

int main()
{
    int n;
    cin >> n;
    int **d = new int *[n];
    for (int i = 0; i < n; i++)
    {
        int *t = new int[2];
        cin >> t[0] >> t[1];
        d[i] = t;
    }

    sort(d, d + n, comp);

    int ans = 1,p = 0;;
    for (int i = 1; i < n; i++)
    {
        if (d[i][0] >= d[p][1])
        {
            ans++;
            p = i;
        }
    }
    cout << ans;

    return 0;
}