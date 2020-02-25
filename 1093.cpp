#include <iostream>
#include <algorithm>
using namespace std;

bool comp(int i[], int j[])
{
    if (i[3] != j[3])
    {
        return i[3] > j[3];
    }
    else if (i[0] != j[0])
    {
        return i[0] > j[0];
    }
    else
    {
        return i[4] < j[4];
    }
}

int main()
{
    int n;
    cin >> n;

    int **d= new int*[n];
    for (int i = 0; i < n; i++)
    {
        d[i] = new int[5];
        cin >> d[i][0] >> d[i][1] >> d[i][2];
        d[i][3] = d[i][0] + d[i][1] + d[i][2];
        d[i][4] = i;
    }

    sort(d, d + n, comp);
    for (int i = 0; i < 5; i++)
    {
        cout << d[i][4] + 1 << ' ' << d[i][3] << endl;
    }

    return 0;
}