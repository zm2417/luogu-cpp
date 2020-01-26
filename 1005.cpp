#include <iostream>
#include <cstdio>
using namespace std;

const int maxInf = 85, MOD = 10000;
int n, m, d[maxInf];

struct Node
{
    int p[505], len;
    Node()
    {
        for (int i = 0; i < 505; i++)
        {
            p[i] = 0;
        }
        len = 0;
    }

    void print()
    {
        // cout << p[len];
        printf("%d",p[len]);
        for (int i = len - 1; i > 0; i--)
        {
            if (p[i] == 0)
            {
                printf("0000");
            }
            else
            {
                for (int j = 1000; j > p[i];j /= 10)
                {
                    printf("0"); 
                }
                printf("%d",p[i]);
            }
        }
    }
} dp[maxInf][maxInf], baseTwo[maxInf], ans;

Node operator+(Node n1, Node n2)
{
    Node c;
    c.len = max(n1.len, n2.len);
    int jw = 0;
    for (int i = 1; i <= c.len; i++)
    {
        c.p[i] = n1.p[i] + n2.p[i] + jw;
        jw = c.p[i] / MOD;
        c.p[i] %= MOD;
    }
    while (jw > 0)
    {
        c.p[++c.len] = jw % MOD;
        jw /= MOD;
    }
    return c;
}

Node operator*(Node n1, int x)
{
    Node c;
    c.len = n1.len;
    int jw = 0;
    for (int i = 1; i <= n1.len; i++)
    {
        c.p[i] += n1.p[i] * x + jw;
        jw = c.p[i] / MOD;
        c.p[i] %= MOD;
    }
    while (jw > 0)
    {
        c.p[++c.len] = jw % MOD;
        jw /= MOD;
    }
    return c;
}

Node max(Node n1, Node n2)
{
    if (n1.len > n2.len)
    {
        return n1;
    }
    else if (n1.len < n2.len)
    {
        return n2;
    }
    for (int i = n1.len; i > 0; i--)
    {
        if (n1.p[i] > n2.p[i])
            return n1;
        if (n1.p[i] < n2.p[i])
            return n2;
    }
    return n1;
}

void two()
{
    baseTwo[0].p[1] = 1;
    baseTwo[0].len = 1;
    for (int i = 1; i <= m + 2; i++)
    {
        baseTwo[i] = baseTwo[i - 1] * 2;
    }
}

void init()
{
    for (int i = 0; i < maxInf; i++)
    {
        for (int j = 0; j < maxInf; j++)
        {
            for (int k = 0; k < 505; k++)
            {
                dp[i][j].p[k] = 0;
            }
            dp[i][j].len = 0;
        }
    }
}

int main()
{
    cin >> n >> m;
    two();
    for (int i = 1; i <= n; i++)
    {
        init();
        for (int j = 1; j <= m; j++)
        {
            // cin >> d[j];
            scanf("%d",&d[j]);
        }

        for (int j = 1; j <= m; j++)
        {
            for (int k = m; k >= j; k--)
            {
                dp[j][k] = max(dp[j - 1][k] + baseTwo[m - k + j - 1] * d[j - 1], dp[j][k]);
                dp[j][k] = max(dp[j][k], dp[j][k + 1] + baseTwo[m - k + j - 1] * d[k + 1]);
            }
        }
        Node temp;
        for (int j = 1; j <= m; j++)
        {
            temp = max(temp, dp[j][j] + baseTwo[m] * d[j]);
        }
        ans = ans + temp;
    }
    ans.print();
    return 0;
}