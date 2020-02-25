#include <iostream>
#include <algorithm>
using namespace std;

const int maxInf = 100005;
const long long MOD = 2147483648;
long long n, m;
int w, k;
long long c[maxInf][15];              // 组合数
long long tr[maxInf];                 //树状数组
long long numX[maxInf], numY[maxInf]; // x,y方向上树的数量
long long temp[maxInf];               // 辅助离散化
long long ans;                        // 结果
long long t[maxInf];                  // 统计当前节点左边节点数量
long long h[maxInf];
long long r[maxInf];

struct Node
{
    int xi, yi;
} node[maxInf];

// 按x排序
bool compX(Node n1, Node n2)
{
    if (n1.xi == n2.xi)
        return n1.yi < n2.yi;
    return n1.xi < n2.xi;
}

// 按y排序
bool compY(Node n1, Node n2)
{
    if (n1.yi == n2.yi)
        return n1.xi < n2.xi;
    return n1.yi < n2.yi;
}

// 预处理组合数
void dealC()
{
    for (int i = 0; i <= w; i++)
    {
        c[i][0] = 1;
    }
    for (int i = 1; i <= w; i++)
    {
        for (int j = 1; j <= min(i, k); j++)
        {
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
        }
    }
}

// 树状数组
int lowbit(int x)
{
    return x & (-x);
}

void update(int p, int x)
{
    x %= MOD;
    while (p <= w)
    {
        tr[p] += x;
        tr[p] %= MOD;
        p += lowbit(p);
    }
}

int ask(int p)
{
    long long res = 0;
    while (p > 0)
    {
        res += tr[p];
        res %= MOD;
        p -= lowbit(p);
    }
    return res;
}

int main()
{
    cin >> n >> m >> w;
    for (int i = 1; i <= w; i++)
    {
        cin >> node[i].xi >> node[i].yi;
    }
    cin >> k;
    dealC();
    sort(node + 1, node + w + 1, compX);

    // 处理X方向上的梳理
    int tt = 0;
    // 离散化
    for (int i = 1; i <= w; i++)
    {
        if (i == 1 || node[i].xi != node[i - 1].xi)
            tt++;
        // 相同的x变成相同的tt
        temp[i] = tt;
    }
    for (int i = 1; i <= w; i++)
    {
        numX[node[i].xi = temp[i]]++;
    }
    sort(node + 1, node + 1 + w, compY);
    // 处理y方向上的数量
    tt = 0;
    // 离散化
    for (int i = 1; i <= w; i++)
    {
        if (i == 1 || node[i].yi != node[i - 1].yi)
            tt++;

        // 相同的y变成相同的tt
        temp[i] = tt;
    }
    for (int i = 1; i <= w; i++)
    {
        numY[node[i].yi = temp[i]]++;
    }

    sort(node + 1, node + 1 + w, compX);

    // 当前节点下面(包括当前节点),上面有几个节点
    int down = 1, up = 0;
    for (int i = 1; i < w; i++)
    {
        // if (node[i].xi == node[i - 1].xi)
        // {
        //     down++;
        // }
        // else
        // {
        //     down = 1;
        // }
        // up = numX[node[i].xi] - down;
        // if (up)
        // {
        //     int ceil = node[i + 1].yi - 1;
        //     ans += (c[down][k] * c[up][k] % MOD * (ask(ceil) - ask(node[i].yi)) % MOD);
        // }
        // ++t[node[i].yi]; // 更新一下纵坐标为p[i].y的已经放了的处于左边的常青树
        // long long now = (c[t[node[i].yi]][k] * c[numY[node[i].yi] - t[node[i].yi]][k]) % MOD;
        // long long pre = ask(node[i].yi) - ask(node[i].yi - 1);
        // update(node[i].yi, now - pre);
        // cout << node[i].xi << ' ' << node[i].yi << ' ' << now << ' ' << pre << ' ' << ans << endl;

        if (i == 1 || node[i].xi != node[i - 1].xi)
            tt = 0;
        int le = node[i].yi, v = (++h[le]) >= k && numY[le] - h[le] >= k ? 1ll * c[h[le]][k] * c[numY[le] - h[le]][k] % 2147483648ll
                                                                         : 0;
        tt++;
        update(le, v - r[le]);
        r[le] = v;
        if (i == w || node[i].xi != node[i + 1].xi || node[i + 1].yi - node[i].yi <= 1 || tt < k || numX[node[i].xi] - tt < k)
            continue;
        ans += 1ll * c[tt][k] * c[numX[node[i].xi] - tt][k] % 2147483648ll * (ask(node[i + 1].yi - 1) - ask(node[i].yi)) % 2147483648ll;
    }
    cout << (ans % MOD + MOD) % MOD << endl;
    return 0;
}
