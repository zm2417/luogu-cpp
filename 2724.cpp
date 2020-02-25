#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
const int N = 4096;
struct kk
{
    int x, y, z;
} b[500000];
int A, B, n, m, s[200003], v[N], k, c[13], i, j, t, cnt, to, k1;
char ch;
int cmp(kk x, kk y)
{
    return x.x > y.x || x.x == y.x && (x.z < y.z || x.z == y.z && x.y < y.y);
}
void chan(int x, int y)
{ //把十进制x转成二进制，y表示二进制位数
    int tot = 0;
    while (x)
    {
        c[tot++] = x % 2;
        x /= 2;
    }
    for (int i = 0; i <= y - tot; i++)
        putchar(48); //位数不够用0补
    for (int i = tot - 1; i >= 0; i--)
        putchar(c[i] | 48);
}
int main()
{
    cin >> A >> B >> n;
    while ((ch = getchar()) != EOF)
        if (ch == 48 || ch == 49)
            s[m++] = ch ^ 48; //读入，把'0'和'1'变成0和1，位运算更快
    B = min(B, m);            //最长也不能超过总长度
    for (i = 0; i < B; i++)
    {
        k = k << 1 | s[i]; //k记录0..i-1位的序列，k<<1|1相当于k*2+1，但这样更快
        if (i >= A - 1)
        {
            t = (1 << i + 1) - 1;
            memset(v, 0, sizeof(v));
            v[k]++;
            k1 = k;
            for (j = i + 1; j < m; j++)
            {
                k1 = (k1 << 1 | s[j]) & t; //这里是取k的二进制后i+1位 %(2^(i+1))相当于&(2^(i+1)-1)，常用技巧，不懂的话下面有解释
                v[k1]++;                   //记录
            }
            for (j = 0; j <= t; j++)
                if (v[j])
                    b[cnt].x = v[j], b[cnt].y = j, b[cnt++].z = i; //x记录频率，y记录值，z记录长度
        }
    }
    sort(b, b + cnt, cmp);
    j = 0;
    for (i = 0; i < n && j < cnt; i++)
    {
        printf("%d\n", b[j].x);
        to = 1;
        while (b[j + 1].x == b[j].x)
        {
            chan(b[j].y, b[j].z);
            j++;
            if (to == 6)
                putchar('\n'), to = 0; //没6个换1行
            else
                putchar(' ');
            to++;
        }
        chan(b[j].y, b[j].z);
        j++;
        if (to)
            putchar('\n');
    }
}