#include <iostream>
using namespace std;

int dp[300001][300001];

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        dp[u][v] = 1;
        dp[v][u] = 1;
    }

}