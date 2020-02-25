#include <iostream>
using namespace std;

const int maxInf = 120;
const int MOD = 1000000007;
long long n, k;
struct Mat
{
    long long m[maxInf][maxInf];
} ans, d;

Mat operator*(Mat a, Mat b)
{
    Mat c;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c.m[i][j] = 0;
            for (int l = 0; l < n; l++)
            {
                c.m[i][j] += (a.m[i][l] * b.m[l][j]) % MOD;
            }
            c.m[i][j] %= MOD;
        }
    }
    return c;
}

Mat mul(Mat a, long long x)
{
    Mat c;
    // 初始化单位矩阵
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c.m[i][j] = (i == j);
        }
    }
    while (x)
    {
        if (x % 2 == 1)
        {
            c = c * a;
        }
        a = a * a;
        x >>= 1;
    }
    return c;
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> d.m[i][j];
        }
    }
    ans = mul(d, k);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ans.m[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}