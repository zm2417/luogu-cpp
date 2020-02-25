#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int d[n] = {0};
    int up[n] = {1};
    int low[n] = {1};
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
        up[i] = 1;
        low[i] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (d[j] < d[i])
                up[i] = max(up[i], up[j] + 1);
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (d[j] < d[i])
                low[i] = max(low[i], low[j] + 1);
        }
    }

    int maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        maxLen = max(maxLen, low[i] + up[i] - 1);
    }
    cout << n - maxLen;
    return 0;
}