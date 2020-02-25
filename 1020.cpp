#include <iostream>
using namespace std;

int d[100000], low[100000], up[100000], i = 0, len1 = 0, len2 = 0;

int t1(int x)
{
    int l = 0, r = len1 - 1;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (low[mid] >= x)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return r;
}

int t2(int x)
{
    int l = 0, r = len2 - 1;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (up[mid] > x)
            r = mid - 1;
        else if (up[mid] == x)
        {
            return mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    return l;
}

int main()
{
    while (cin >> d[i])
    {
        if (i != 0)
        {
            if (low[len1 - 1] >= d[i])
            {
                low[len1++] = d[i];
            }
            else
            {
                int lp = t1(d[i]);
                low[lp + 1] = d[i];
            }

            if (up[len2 - 1] < d[i])
                up[len2++] = d[i];
            else if (up[len2 - 1] > d[i])
            {
                int lp = t2(d[i]);
                up[lp] = d[i];
            }
        }
        else
        {
            low[len1++] = d[i];
            up[len2++] = d[i];
        }
        i += 1;
    }

    cout << len1 << endl
         << len2;
    return 0;
}