#include <string>
#include <iostream>
using namespace std;
int dp[10][10];
const int MAXN = 100;
int ans[MAXN];
int len = 1;

//floyd + 高精度

void multiplication(int x)
{
    len += 10;
    int temp[MAXN] = {0};
    for (int i = 0; i < len; i++)
    {
        temp[i] += ans[i] * x;
        temp[i + 1] += temp[i] / 10;
        temp[i] = temp[i] % 10;
    }
    for (int i = 0; i <= len; i++)
    {
        ans[i] = temp[i];
    }
    while (len > 0 && ans[len - 1] == 0)
    {
        len--;
    }
}

int main()
{
    int k;
    string n;
    cin >> n >> k;
    for (int i = 0; i < k; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        dp[t1][t2] = 1;
    }

    // floyd
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (i == j)
                continue;
            for (int k = 0; k < 10; k++)
            {
                if (i == k || j == k)
                    continue;
                if (dp[j][i] == 1 && dp[i][k] == 1)
                    dp[j][k] = 1;
            }
        }
    }

    //统计可以转化的字符数量
    int da[10] = {0};
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (dp[i][j] != 0)
            {
                da[i]++;
            }
        }
    }

    // 高精度乘法
    ans[0] = 1;
    for (int i = 0; i < n.size(); i++)
    {
        multiplication(da[n[i] - '0'] + 1);
    }

    for (int i = len - 1; i >= 0; i--)
    {
        cout << to_string(ans[i]);
    }

    return 0;
}