#include <iostream>
#include <cmath>
#include <string>
using namespace std;

const int maxInf = 512;
string c[maxInf][maxInf];
int k, w;
int p, t;

// 高精度加
string add(string a, string b)
{
    string ans;
    int jw = 0;
    for (int i = 0; i < max(a.size(), b.size()); i++)
    {
        int x = jw;
        if (i < a.size())
        {
            x += a[i] - 48;
        }
        if (i < b.size())
        {
            x += b[i] - 48;
        }
        jw = x / 10;
        x %= 10;
        ans.push_back(x + 48);
    }
    if (jw != 0)
    {
        ans.push_back(jw + 48);
    }
    return ans;
}

int main()
{
    cin >> k >> w;
    p = w / k;
    t = (1 << k);
    c[0][0] = "1";
    for (int i = 1; i < t; i++)
    {
        c[i][0] = "1";
        c[i][i] = "1";
    }
    // 杨辉三角形
    // 递推公式𝐶𝑚𝑛=𝐶𝑚𝑛−1+𝐶𝑚−1𝑛−1 可理解为：含特定元素的组合有𝐶𝑚−1𝑛−1，不含特定元素的排列为𝐶𝑚𝑛−1
    for (int i = 1; i < t; i++)
    {
        for (int j = 1; j < i; j++)
        {
            c[i][j] = add(c[i - 1][j - 1], c[i - 1][j]);
        }
    }
    string ans = "0";
    for (int i = 2; i <= p; i++)
    {
        if (i > t - 1)
            break;
        ans = add(ans, c[t - 1][i]);
    }
    int res = w % k;
    int pp = (1 << res) - 1;
    for (int i = 1; i <= pp; i++)
    {
        if (p > t - 1 - i)
            break;
        ans = add(ans, c[t - 1 - i][p]);
    }
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i];
    }
    return 0;
}
