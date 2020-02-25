#include <iostream>
using namespace std;

int main()
{
    // V:箱子容量为V n:有n个物品
    int V, n;
    cin >> V >> n;
    int v[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    int dp[V + 1] = {0};
    for (int i = 1; i <= n; i++)
    {
        for (int j = V; j >= v[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - v[i]] + v[i]);
        }
    }
    cout << V-dp[V];
    return 0;
}