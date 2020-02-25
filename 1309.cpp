#include <iostream>
#include <algorithm>
using namespace std;

bool comp(int i[], int j[])
{
    if (i[1] != j[1])
    {
        return i[1] > j[1];
    }
    else
    {
        return i[0] < j[0];
    }
}

int main()
{
    int n, r, q;
    cin >> n >> r >> q;
    int **win = new int *[n], **lose = new int *[n];
    for(int i = 0;i<n;i++)
    {
        int *t1 = new int[3];
        int *t2 = new int[3];
        win[i] = t1;
        lose[i] = t2;
    }
    n = 2 * n;
    int **d = new int *[n];
    for (int i = 0; i < n; i++)
    {
        int *t = new int[3];
        t[0] = i;
        cin >> t[1];
        d[i] = t;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> d[i][2];
    }

    sort(d, d + n, comp);
    for (int i = 0; i < r; i++)
    {
        int w = 0, l = 0;
        for (int j = 0; j < n; j = j + 2)
        {
            if (d[j][2] > d[j + 1][2] || (d[j][2] == d[j + 1][2] && d[j][0] < d[j+1][0]))
            {
                win[w] = d[j];
                win[w++][1]++;
                lose[l++] = d[j + 1];
            }
            else
            {
                win[w] = d[j + 1];
                win[w++][1]++;
                lose[l++] = d[j];
            }
        }

        //归并排序思想（快排时间过高）
        int a = 0, b = 0;
        int x = 0;
        while (a < n / 2 && b < n / 2)
        {
            if (win[a][1] > lose[b][1] || (win[a][1] == lose[b][1] && win[a][0] < lose[b][0]))
            {
                d[x++] = win[a++];
            }
            else
            {
                d[x++] = lose[b++];
            }
        }
        while (a < n / 2)
        {
            d[x++] = win[a++];
        }
        while (b < n / 2)
        {
            d[x++] = lose[b++];
        }
    }
    cout << d[q - 1][0] + 1;
    return 0;
}