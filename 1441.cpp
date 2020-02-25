#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
const int maxNum = 120;
int d[25], sum[2010], used[25], ans, maxSum, last = -1;

void dp()
{
    for (int i = 0; i <= maxSum; i++)
        sum[i] = 0;
    sum[0] = 1;
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        if (used[i] == 0)
        {
            for (int j = maxSum - d[i]; j >= 0; j--)
            {
                if (sum[j] == 1)
                {
                    if (sum[j + d[i]] == 0)
                        temp++;
                    sum[j + d[i]] = 1;
                }
            }
        }
    }
    ans = max(ans, temp);
}

void dfs(int c)
{
    if (c > m)
    {
        dp();
        return;
    }
    for (int i = last + 1; i < n; i++)
    {
        if (used[i] == 0)
        {
            used[i] = 1;
            last = i;
            dfs(c + 1);
            used[i] = 0;
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
        maxSum += d[i];
    }
    dfs(1);
    cout << ans;
    return 0;
}