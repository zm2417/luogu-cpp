#include <iostream>
using namespace std;

int d[5020], sum[5020], len[5020];
int maxLen = 0, maxSum = 0;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
        sum[i] = 1;
        len[i] = 1;
        for (int j = i - 1; j > 0; j--)
        {
            if (d[j] > d[i])
            {
                if (len[i] == len[j] + 1)
                {
                    sum[i] += sum[j];
                }
                else if (len[i] < len[j] + 1)
                {
                    len[i] = len[j] + 1;
                    sum[i] = sum[j];
                }
            }
            if (d[j] == d[i])
            {
                if (len[i] == 1)
                {
                    sum[i] = 0;
                }
                break;
            }
        }
        maxLen = max(maxLen, len[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        if (len[i] == maxLen)
            maxSum += sum[i];
    }
    cout << maxLen << ' ' << maxSum << endl;
    return 0;
}