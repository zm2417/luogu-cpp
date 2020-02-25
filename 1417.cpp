#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    long long a, b, c;
} node[50];

long long dp[51][100010];

bool comp(Node n1, Node n2)
{
    return n2.b * n1.c < n1.b * n2.c;
}

int main()
{
    int T, n;
    cin >> T >> n;
    for (int j = 0; j < n; j++)
    {
        int k;
        cin >> k;
        node[j].a = k;
    }
    for (int j = 0; j < n; j++)
    {
        int k;
        cin >> k;
        node[j].b = k;
    }
    for (int j = 0; j < n; j++)
    {
        int k;
        cin >> k;
        node[j].c = k;
    }
    sort(node, node + n, comp);
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= T; j++)
        {
            if (j >= node[i - 1].c)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - node[i - 1].c] + node[i - 1].a - node[i - 1].b * j);
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}