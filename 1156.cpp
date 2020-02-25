#include <iostream>
#include <algorithm>
using namespace std;

// dp[i][j]:前i个垃圾到达j高度最大生存时间
int d, g, dp[120][1200];

struct Node
{
    int t, f, h;
} node[110];

bool comp(Node n1, Node n2)
{
    return n1.t < n2.t;
}

int main()
{
    cin >> d >> g;
    for (int i = 1; i <= g; i++)
    {
        cin >> node[i].t >> node[i].f >> node[i].h;
    }

    sort(node + 1, node + g + 1, comp);
    dp[0][0] = 10;
    for (int i = 1; i <= g; i++)
    {
        for (int j = 0; j <= d; j++)
        {
            // 吃
            if (dp[i - 1][j] >= node[i].t)
                dp[i][j] = max(dp[i][j], dp[i - 1][j] + node[i].f);
            // 堆
            if (j - node[i].h >= 0 && dp[i - 1][j - node[i].h] >= node[i].t)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - node[i].h]);
        }
    }
    int maxH = 0, maxD = 0;
    for (int i = 1; i <= g; i++)
    {
        for (int j = 0; j <= d; j++)
        {
            if (dp[i][j] >= node[i].t)
                maxH = max(maxH, j);
            maxD = max(maxD, dp[i][j]);
        }
        if (maxH == d)
        {
            cout << node[i].t;
            return 0;
        }
    }
    cout << maxD;
    return 0;
}