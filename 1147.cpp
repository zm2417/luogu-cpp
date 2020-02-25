#include <iostream>
using namespace std;

long long d[2000010];

int main()
{
    int m;
    cin >> m;
    d[1] = 1;
    for (int i = 2; i <= m; i++)
    {
        d[i] = i + d[i - 1];
    }
    for (int i = 2; i <= m-1; i++)
    {
        int l = 1, r = i - 1;
        long long t = d[i] - m;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (d[mid] == t)
            {
                cout << mid + 1 << ' ' << i << endl;
                break;
            }
            else if (d[mid] > t)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
    }
    return 0;
}