#include <iostream>
#include <algorithm>
using namespace std;

int n, d[70];
int realN;
int sum;
int num;                 // 根数
int mask = 0;            // 成功标志
int len;                 //每根的长度
int used[70], nextP[70]; //nextP:排序后每根木棍后面的最后一根与这根木棍长度相等的木棍

bool comp(int i, int j)
{
    return i > j;
}
//c为正在拼的木棍的编号，last为正在拼的木棍的前一节编号，rest为该木棍还未拼的长度
void dfs(int c, int last, int rest)
{
    if (rest == 0) //未拼的长度为0，说明这根原始长棍拼完了，准备拼下一个
    {
        if (c == num)
        {
            mask = 1;
            return;
        }
        int i;
        for (i = 1; i < realN; i++)
        {
            if (used[i] == 0)
            {
                break;
            }
        }
        used[i] = 1;
        dfs(c + 1, i, len - d[i]);
        used[i] = 0;
        if (mask == 1)
            return;
    }
    //二分找最大可满足不大于剩余的长度
    int l = last + 1, r = realN, mid;
    while (l < r)
    {
        mid = (l + r) / 2;
        if (d[mid] <= rest)
            r = mid;
        else
            l = mid + 1;
    }
    for (int i = l; i <= realN; i++)
    {
        if (used[i] == 0)
        {
            used[i] = 1;
            dfs(c, i, rest - d[i]);
            used[i] = 0;
            if (mask == 1)
                return;
            if (rest == d[i] || rest == len)
                return;
            i = nextP[i];
            if (i == realN)
                return;
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int j;
        cin >> j;
        if (j <= 50 && j > 0)
        {
            d[++realN] = j;
            sum += j;
        }
    }
    sort(d + 1, d + realN + 1, comp);
    nextP[realN] = realN;
    for (int i = realN - 1; i > 0; i--)
    {
        if (d[i] == d[i + 1])
        {
            nextP[i] = nextP[i + 1];
        }
        else
        {
            nextP[i] = i;
        }
    }
    for (len = d[1]; len <= sum / 2; len++)
    {
        if (sum % len != 0)
            continue;
        num = sum / len;
        mask = 0;
        used[1] = 1;
        dfs(1, 1, len - d[1]);
        used[1] = 0;
        if (mask == 1)
        {
            cout << len;
            return 0;
        }
    }
    cout << sum;
    return 0;
}