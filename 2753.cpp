#include <iostream>
#include <cstdio>
#include <string>
#include <string>
#include <cstring>
using namespace std;

int point[] = {2, 5, 4, 4, 1, 6, 5, 5, 1, 7, 6, 3, 5, 2, 3, 5, 7, 2, 1, 2, 4, 6, 6, 7, 5, 7};
int w[28];
int w1[28];
int w2[28];

string word[40003]; //存每个单词,下标从1开始
int lw[40003], n;
int va[40003]; //存每个单词的价值

string s;
int ans[40003][2], num, ans1; //ans：下标0开始
void qm(int x, int y)
{
    if (va[x] + va[y] < ans1)
        return;
    if (va[x] + va[y] > ans1) //价值更大
    {
        ans1 = va[x] + va[y]; //更新
        num = 0;
    }
    num++; //相当于价值和max相等，所以统计
    ans[num][0] = x;
    ans[num][1] = y;
}

int main()
{
    // freopen("lgame.in", "r", stdin);
    cin >> s;
    for (int i = 0; i < s.size(); i++)
        w[s[i] - 'a']++;
    // freopen("lgame.dict", "r", stdin);
    // freopen("lgame.out", "w", stdout);
    while (cin >> s)
    {
        if (s[0] == '.')
            break;
        memset(w1, 0, sizeof(w1));
        for (int i = 0; i < s.size(); i++)
        {
            w1[s[i] - 'a']++;
        }
        bool mask = true;
        for (int i = 0; i < 28; i++)
            if (w1[i] > w[i])
            {
                mask = false;
                break;
            }
        if (mask)
        {
            n++;
            lw[n] = s.size();
            word[n] = s;
            // 计算价值
            for (int i = 0; i < s.size(); i++)
                va[n] += point[s[i] - 'a'];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        qm(i, 0);
        memcpy(w1, w, sizeof(w1));
        for (int j = 0; j < lw[i]; j++)
        {
            w1[word[i][j] - 'a']--;
        }
        for (int j = i; j <= n; j++) //j从i开始去重
        {
            int flag = 0;
            memcpy(w2, w1, sizeof(w2));
            for (int k = 0; k < lw[j]; k++) //看i和j两个串拼一起符不符合条件
            {
                w2[word[j][k] - 'a']--;
                if (w2[word[j][k] - 'a'] < 0)
                {
                    flag = 1; //标记
                    break;
                }
            }
            if (flag == 0)
            {
                qm(i, j);
            }
        }
    }
    printf("%d\n", ans1);
    for (int i = 1; i <= num; i++) //输出
    {
        cout << word[ans[i][0]];
        // printf("%s", word[ans[i][0]]);
        if (ans[i][1] != 0)
            cout << ' ' << word[ans[i][1]];
        // printf(" %s", word[ans[i][1]]);
        cout << endl;
    }
    return 0;
}