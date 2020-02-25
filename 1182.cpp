#include <iostream>
using namespace std;

// 判断d数组连续子数组之和可以是x
bool judge(int x, int d[], int size, int m)
{
    int tol = 0, num = 0;
    for (int i = 0; i < size; i++)
    {
        if (tol + d[i] <= x)
            tol += d[i];
        else
            tol = d[i], num++;
    }
    return m > num;
}

int main()
{
    int n, m, Max = 0, sum = 0;
    cin >> n >> m;
    int d[n] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
        Max = max(Max, d[i]);
        sum += d[i];
    }

    // 二分
    int l = Max, r = sum;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (judge(mid, d, n, m))
            r = mid - 1;
        else
        {
            l = mid + 1;
        }
    }
    cout << l;
    return 0;
}