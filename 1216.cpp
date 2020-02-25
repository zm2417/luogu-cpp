#include <iostream>
using namespace std;

int r, m;

int main()
{
    cin >> r;
    int dp[1001] = {0};
    for (int i = 0; i < r; i++)
    {
        int temp[1001] = {0};
        for (int j = 0; j <= i; j++)
        {
            int x;
            cin >> x;
            if (j == 0)
                temp[j] = dp[0] + x;
            else if (j == i)
                temp[j] = dp[i - 1] + x;
            else
                temp[j] = max(dp[j - 1] + x, dp[j] + x);
        }
        for (int j = 0; j <= i; j++)
        {
            dp[j] = temp[j];
            m = max(m, dp[j]);
        }
    }
    cout << m;
    return 0;
}