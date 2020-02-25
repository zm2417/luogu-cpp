#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int m = INT32_MIN, dp[n + 1] = {0};
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        dp[i] = max(x, dp[i - 1] + x);
        m = max(m, dp[i]);
    }
    cout << m;
    return 0;
}