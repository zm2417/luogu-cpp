#include <iostream>
#include <algorithm>
using namespace std;

const int maxInf = 1005;
int n, d[maxInf];
int minAns = INT32_MAX;

int sqr(int x)
{
    return x * x;
}

// 先枚举山的高度，然后再去带进去算费用，求min，简单粗暴。
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
    }
    sort(d, d + n);
    int temp = 0;
    for (int i = d[0]; i <= d[n-1]; i++)
    {
        temp = 0;
        for (int j = 0; j < n; j++)
        {
            if (i > d[j])
            {
                temp += sqr(i - d[j]);
            }
            else if (i + 17 < d[j])
            {
                temp += sqr(d[j] - 17 - i);
            }
        }
        // cout << temp << endl;
        minAns = min(minAns, temp);
    }
    cout << minAns << endl;
    return 0;
}