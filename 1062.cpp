#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
using namespace std;
long long dp[1001];
int len = 0, k, n;

void p(int ki)
{
    long long t = pow(k, ki);
    dp[len] = t;
    int len_temp = len;
    for (int i = 0; i < len; i++)
    {
        if (len + i + 1 >= n)
        {
            break;
        }
        dp[len + i + 1] = dp[i] + t;
        len_temp++;
    }
    len = len_temp + 1;
}

int main()
{
    cin >> k >> n;

    // int i = 0;
    // while (true)
    // {
    //     p(i++);
    //     if(len >= n)
    //     {
    //         break;
    //     }
    // }

    // cout << dp[n-1];
    // return 0;

    stack<int> s;
    while (n)
    {
        s.push(n & 1);
        n >>= 1;
    }
    int i = 0;
    long long ans = 0;
    while (!s.empty())
    {
        ans += s.top() * pow(k, s.size() - 1);
        s.pop();
    }
    cout << ans;
    return 0;
}