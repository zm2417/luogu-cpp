#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int d[55][55];
int vis[55];
vector<int> d1, d2;

int main()
{
    // for (int i = 0; i < 55; i++)
    //     for (int j = 0; j < 55; j++)
    //         d[i][j] = -1;
    int p;
    int n = 0;
    while (cin >> p)
    {
        if (p == -1)
            break;
        if (p == -2)
        {
            n++;
            continue;
        }
        d[n][p] = 1;
    }
    n--;
    // vis[0] = 1;
    // 枚举去掉一个点能否到达n
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
            vis[j] = 0;
        queue<int> q;
        q.push(0);
        while (q.size())
        {
            int j = q.front();
            q.pop();
            if (vis[j])
                continue;
            vis[j] = 1;
            for (int k = 0; k <= n; k++)
                if (d[j][k] && vis[k] == 0 && k != i)
                    q.push(k);
        }
        if (vis[n] == 0)
        {
            d1.push_back(i);
            bool mask = true;
            // vis中等于1的是第一部分,0为第二部分,判断第二部分中的能否连到第一部分
            for (int v = 0; v <= n; v++)
            {
                if (vis[v] == 0)
                    for (int w = 0; w <= n; w++)
                        if (vis[w] && d[v][w])
                        {
                            mask = false;
                            break;
                        }
                if (!mask)
                {
                    break;
                }
            }
            if (mask)
                d2.push_back(i);
        }
    }
    cout << d1.size() << ' ';
    for (int i = 0; i < d1.size(); i++)
        cout << d1[i] << ' ';
    cout << endl
         << d2.size() << ' ';
    for (int i = 0; i < d2.size(); i++)
        cout << d2[i] << ' ';
    cout << endl;
}