#include <iostream>
using namespace std;

const long long MOD = 1000000007;
long long n, m, k, ans;
int lim;
struct node
{
    long long t[64][64];
} re, x;
int ok[64], bin[6]; //ok：是否是合法状态

void work(int zt, int num)
{
    ok[zt] = 1;
    int kl = zt >> 1;
    x.t[kl][zt] = 1;
    // 判断后面能否为1
    if (num == k && !(zt & 1))
        return;
    x.t[kl + bin[m]][zt] = 1;
}
void dfs(int x, int num, int zt)
{
    if (x == m + 1)
    {
        work(zt, num);
        return;
    }
    dfs(x + 1, num, zt);
    if (num < k)
        dfs(x + 1, num + 1, zt | bin[x]);
}

node operator*(node a, node b)
{
    int i, j, k;
    node c;
    for (i = 0; i <= lim; ++i)
        for (j = 0; j <= lim; ++j)
        {
            c.t[i][j] = 0;
            for (k = 0; k <= lim; ++k)
                c.t[i][j] += a.t[i][k] * b.t[k][j] % MOD, c.t[i][j] %= MOD;
        }
    return c;
}
// 快速幂
void ksm()
{
    int bj = 0;
    while (n)
    {
        if (n & 1)
        {
            if (!bj)
                re = x, bj = 1;
            else
                re = re * x;
        }
        x = x * x;
        n >>= 1;
    }
}

int main()
{
    bin[1] = 1;
    for (int i = 2; i <= 5; ++i)
        bin[i] = bin[i - 1] << 1;
    cin >> n >> m >> k;
    lim = (1 << m) - 1;
    dfs(1, 0, 0);
    ksm();
    // 由于所有的花圃是一个环，所以第1～m个花圃就是第n+1~n+m个花圃，所以我们求的答案就是一个合法状态转移n次，转移回原状态的方案数之和。
    for (int i = 0; i <= lim; ++i)
        if (ok[i])
            ans += re.t[i][i], ans %= MOD;
    cout << ans << endl;
    return 0;
}