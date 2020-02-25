#include <iostream>
using namespace std;

// 求最低位的1
int lowbit(int x)
{
    return x & (-1 * x);
}

// 统计1的个数
int countOne(int x)
{
    int ans = 0;
    while (x > 0)
    {
        x -= lowbit(x);
        ans++;
    }
    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int ans = 0;
    while (true)
    {
        if (countOne(n) <= k)
        {
            cout << ans;
            return 0;
        }
        else
        {
            int j = lowbit(n);
            n += j;
            ans += j;
        }
    }
}