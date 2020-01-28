#include <iostream>
using namespace std;

// Kmax = a*b - a - b

// 1.数论：设自然数a，b互质，则不能表示成ax+by（x，y为非负整数）的最大整数是ab - a - b
// 证明：
// a或者b是1的情况下容易证明。
// 以下情况都是a>1且b>1的情况。
// 首先证明ab-a-b不能表示成ax+by
// 假设ab-a-b=ax+by，那么ab=am+bn (m,n都大于等于1)
// 左边是a的倍数，右边am是a的倍数，那么要求bn也要是a的倍数
// b不是a的倍数，只能要求n是a的倍数，这样的话，bn=b(n*a)>=ba
// 那么am=ab-bn所以am<=0与m>1矛盾。
// 接着证明ab-a-b+i能表示成ax+by(i>0)
// 因为ab互质，最大公约数就是1，根据费蜀(Bezout)定理的方法知ma+nb=1，
// 不妨假设m>0,n<0，于是ab-a-b+i=ab-a-b+i(ma+nb)
// 因为m>1(m=0意味着nb=1不可能的)，所以ab-a-b+i(ma+nb)=(im-1)a+(a+in-1)b
// im-1>0，现在只要证明a+in-1>=0，因为ima+inb=i
// 如果，|in|>ja其中j>0，那么ima=i+|in|b>jab，所以im>jb
// 所以ima+inb=(im-jb)a-(|in|-ja)b=i，说明|in|>ja时，我们就能调整im,in使得|in|<a
// 因此|in|<=a-1, 所以a+in-1>=0于是得证

// 拓展：
// 费蜀(Bezout)定理：若有整数a、b和其最大公因子d，必存在整数x、y使得：
// ax + by = d

const int MAX = 256 * 256 - 2 * 256 + 1;
int n;
int d[15];
int dp[MAX + 1];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> d[i];
    dp[0] = 1;

    for (int i = 0; i < n; i++)
        for (int j = d[i]; j <= MAX; j++)
            dp[j] = dp[j] || dp[j - d[i]];

    int ans = 0;
    for (int i = MAX; i >= 0; i--)
        if (dp[i] == 0)
        {
            ans = i;
            break;
        }
    if (ans > 65024)
        ans = 0;
    cout << ans << endl;
    return 0;
}