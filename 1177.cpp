#include <iostream>
#include <cstdio>
using namespace std;
int d[100000];
int len;

void quickSort(int low, int top)
{
    if (low >= top)
    {
        return;
    }
    int t1 = (low + top) / 2;
    // k:统计与基准数一样的个数
    int i = low, k = low, j = top, temp = d[top];
    d[top] = d[t1];
    d[t1] = temp;
    temp = d[top];
    while (i < j)
    {
        while (i < j && d[i] <= temp)
        {
            i++;
        }
        while (i < j && d[j] >= temp)
        {
            j--;
        }
        if (i < j)
        {
            int t = d[i];
            d[i] = d[j];
            d[j] = t;
            // 如果加上下面的代码，数据: 3 1 2，输出 2 3 1
            // i++;
            // j--;
        }
    }
    d[top] = d[j];
    d[j] = temp;
    quickSort(low, i - 1);
    quickSort(i + 1, top);
}

int main()
{
    scanf("%d", &len);
    for (int i = 0; i < len; i++)
    {
        scanf("%d", &d[i]);
        // cin >> d[i];
    }
    quickSort(0, len - 1);
    for (int i = 0; i < len - 1; i++)
    {
        cout << d[i] << ' ';
    }
    cout << d[len - 1] << endl;
}