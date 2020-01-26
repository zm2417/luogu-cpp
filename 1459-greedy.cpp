#include <iostream>
using namespace std;

int n;
int d[1005];
int s[4];

// 1、一个数字1跑到了区间2，同时区间2中的一个数字2跑到了区间1

// 2、一个数字1跑到了区间3，同时区间3中的一个数字3跑到了区间1

// 3、一个数字2跑到了区间3，同时区间3中的一个数字3跑到了区间2

// 4、一个数字1跑到了区间2，同时区间2中的一个数字2跑到了区间3，区间3中的一个数字3跑到了区间1

// 5、一个数字1跑到了区间3，同时区间3中的一个数字3跑到了区间2，区间2中的一个数字2跑到了区间1

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
        s[d[i]]++;
    }
    s[2] += s[1];
    int ans;
    for (int i = 0; i < s[1]; i++)
    {
        if (d[i] != 2)
            continue;
        for (int j = s[1]; j < s[2]; j++)
        {
            if (d[j] == 1)
            {
                swap(d[i], d[j]);
                ans++;
                break;
            }
        }
    }

    for (int i = 0; i < s[1]; i++)
    {
        if (d[i] != 3)
            continue;
        for (int j = s[2]; j < n; j++)
        {
            if (d[j] == 1)
            {
                swap(d[i], d[j]);
                ans++;
                break;
            }
        }
    }

    for (int i = s[1]; i < s[2]; i++)
    {
        if (d[i] != 3)
            continue;
        for (int j = s[2]; j < n; j++)
        {
            if (d[j] == 2)
            {
                swap(d[i], d[j]);
                ans++;
                break;
            }
        }
    }

    int ss = 0;
    for (int i = 0; i < s[1]; i++)
    {
        if (d[i] != 1)
            ss++;
    }
    for (int i = s[1]; i < s[2]; i++)
    {
        if (d[i] != 2)
            ss++;
    }
    for (int i = s[2]; i < n; i++)
    {
        if (d[i] != 3)
            ss++;
    }
    cout << ans + ss * 2 / 3;
    return 0;
}