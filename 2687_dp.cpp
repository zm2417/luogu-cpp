#include <iostream>
using namespace std;

const int MAXN = 5005;
int n;
double d[MAXN];
int dpLen[MAXN];
int maxLen = 0;
double maxNum = 0, dpNum[MAXN];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> d[i];
    // dp求最长下降子序列
    for (int i = 1; i <= n; i++)
    {
        dpLen[i] = 1;
        for (int j = 1; j < i; j++)
            if (d[i] < d[j])
                dpLen[i] = max(dpLen[i], dpLen[j] + 1);
        maxLen = max(maxLen, dpLen[i]);
    }
    // dp求方案数
    for (int i = 1; i <= n; i++)
    {
        if (dpLen[i] == 1)
            dpNum[i] = 1;
        for (int j = 1; j < i; j++)
            if (dpLen[i] == dpLen[j] + 1 && d[i] < d[j])
                dpNum[i] += dpNum[j];
            else if (dpLen[i] == dpLen[j] && d[i] == d[j])
                dpNum[i] = 0;
        if (dpLen[i] == maxLen)
            maxNum += dpNum[i];
    }
    cout << maxLen << ' ';
    printf("%.0lf\n", maxNum);
    return 0;
}