#include <iostream>
using namespace std;

const int maxInf = 100010;
int n, len;
int d1[maxInf], d2[maxInf], dp[maxInf];

// LCS + LIS
// O(nlogn)
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int j;
        cin >> j;
        d1[j] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        int j;
        cin >> j;
        d2[i] = d1[j];
    }
    for (int i = 1; i <= n; i++)
    {
        if (dp[len] < d2[i])
            dp[++len] = d2[i];
        else
        {
            int l = 0, r = len;
            while (l < r)
            {
                int mid = (l + r) / 2;
                if (dp[mid] > d2[i])
                    r = mid;
                else
                {
                    l = mid + 1;
                }
            }
            dp[l] = min(dp[l], d2[i]);
        }
    }

    cout << len;
    return 0;
}