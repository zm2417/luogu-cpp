#include <iostream>
#include <map>
// #include <algorithm>
using namespace std;

int s, b;
map<int, int> priceMap, countMap;

int mask[6];

int dp[6][6][6][6][6];

struct YH
{
    int num[1000];
    int p;
} yh[100];
int error[100];

void dealError()
{
    for (int i = 0; i < s; i++)
    {
        YH t = yh[i];
        for (int j = 0; j < 1000; j++)
        {
            if (t.num[j] > 0 && countMap[j] == 0)
            {
                error[i] = 1;
                break;
            }
        }
    }
}

void initDP()
{
    for (int a = 0; a <= 5; a++)
    {
        for (int b = 0; b <= 5; b++)
        {
            for (int c = 0; c <= 5; c++)
            {
                for (int d = 0; d <= 5; d++)
                {
                    for (int e = 0; e <= 5; e++)
                    {
                        dp[a][b][c][d][e] = a * priceMap[mask[0]] + b * priceMap[mask[1]] + c * priceMap[mask[2]] + d * priceMap[mask[3]] + e * priceMap[mask[4]];
                    }
                }
            }
        }
    }
}

void helpDP()
{
    for (int i = 0; i < s; i++)
    {
        if (error[i])
        {
            continue;
        }
        YH t = yh[i];
        for (int a = t.num[mask[0]]; a <= countMap[mask[0]]; a++)
        {
            for (int b = t.num[mask[1]]; b <= countMap[mask[1]]; b++)
            {
                for (int c = t.num[mask[2]]; c <= countMap[mask[2]]; c++)
                {
                    for (int d = t.num[mask[3]]; d <= countMap[mask[3]]; d++)
                    {
                        for (int e = t.num[mask[4]]; e <= countMap[mask[4]]; e++)
                        {
                            dp[a][b][c][d][e] = min(
                                dp[a - t.num[mask[0]]][b - t.num[mask[1]]][c - t.num[mask[2]]][d - t.num[mask[3]]][e - t.num[mask[4]]] + t.p,
                                dp[a][b][c][d][e]);
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    cin >> s;
    for (int i = 0; i < s; i++)
    {
        int n;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            int c, k;
            cin >> c >> k;
            yh[i].num[c] = k;
        }
        cin >> yh[i].p;
    }
    cin >> b;
    for (int i = 0; i < b; i++)
    {
        int c, k, p;
        cin >> c >> k >> p;
        countMap[c] = k;
        priceMap[c] = p;
        mask[i] = c;
    }
    dealError();
    initDP();
    helpDP();
    cout << dp[countMap[mask[0]]][countMap[mask[1]]][countMap[mask[2]]][countMap[mask[3]]][countMap[mask[4]]] << endl;
    return 0;
}