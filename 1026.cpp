#include <iostream>
#include <string>
using namespace std;

int dp[50][250], sum[210][210];
int p, k, w;
string s = " ", letter[10];

bool check(int l, int r)
{                                      //判断是否有单词以s[l]为开头
    string x = s.substr(l, r - l + 1); //取出字符串
    for (int i = 0; i < w; i++)
        if (x.find(letter[i]) == 0)
            return true; //查找
    return false;
}

int main()
{
    cin >> p >> k;
    for (int i = 0; i < p; i++)
    {
        string t;
        cin >> t;
        s += t;
    }
    cin >> w;
    for (int i = 0; i < w; i++)
        cin >> letter[i];

    // 倒序首字母只会使用一次,所以不需要考虑首字母重复
    for (int i = s.size() - 1; i >= 1; i--)
        for (int j = i; j >= 1; j--)
        { //预处理出sum[i][j]
            sum[j][i] = sum[j + 1][i];
            if (check(j, i))
                sum[j][i]++;
        }

    for (int i = 1; i <= k; i++)
        dp[i][i] = dp[i - 1][i - 1] + sum[i][i];
    for (int i = 2; i < s.size(); i++)
        dp[1][i] = sum[1][i]; //初始化

    for (int i = 1; i <= k; i++)
    {
        for (int j = i; j < s.size(); j++)
        {
            for (int k = i; k < j; k++)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][k] + sum[k + 1][j]);
            }
            // if (i == 4)
            //     cout << "dp " << i << ' ' << j << ' ' << dp[i][j] << ' ' << endl;
        }
        // if (i == 4)
        //     cout << endl;
    }
    cout << dp[k][s.size() - 1];
    return 0;
}