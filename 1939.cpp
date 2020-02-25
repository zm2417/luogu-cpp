#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const long long MOD = 1000000007;

struct Mat
{
    long long m[3][3];
} ans, base;

void init()
{
    memset(ans.m, 0, sizeof(ans.m));
    ans.m[0][0] = ans.m[0][1] = ans.m[0][2] = 1;
    memset(base.m, 0, sizeof(base.m));
    base.m[0][0] = base.m[0][1] = base.m[1][2] = base.m[2][0] = 1;
}
// 矩阵加速
Mat operator*(Mat a, Mat b)
{
    Mat c;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            c.m[i][j] = 0;
            for (int k = 0; k < 3; k++)
            {
                c.m[i][j] += (a.m[i][k] * b.m[k][j]) % MOD;
            }
            c.m[i][j] %= MOD;
        }
    }
    return c;
}

Mat operator^(Mat a, long long k)
{
    while (k)
    {
        if (k & 1)
            ans = ans * base;
        base = base * base;
        k >>= 1;
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        long long n;
        cin >> n;
        if (n <= 3)
        {
            cout << 1 << endl;
            continue;
        }
        init();
        ans = ans ^ (n - 3);
        cout << ans.m[0][0] << endl;
    }
    return 0;
}