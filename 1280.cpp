#include <iostream>
#include <algorithm>
using namespace std;

// 让我来讲一下这个题目为什么要倒着推！！！
// 这一题可是难死我了，个人认为此题最最最重要的就是看清楚题意，
// 也就是此时有任务（不在工作状态）就必须选，有很多个就选一个，
// 所以当这个时间只有一个状态开始的时候，我们是没有任何的话说的，
// 但是如果有很多的任务同时开始，我们要选取最优的那个取决这个任务结束后的情况，
// 但是任务结束后的情况我们之前有没有推过，所以我们要倒着推

struct Node
{
    int start;
    int js;
} node[10000];

int t[10010],num[10010];

bool comp(Node n1, Node n2)
{
    return n1.start > n2.start;
}

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> node[i].start >> node[i].js;
        num[node[i].start]++;
    }
    sort(node, node + k, comp);
    int cnt = 0;
    for (int i = n; i >= 1; i--)
    {
        if (num[i] == 0)
            t[i] = t[i + 1] + 1;
        else
        {
            for (int j = 1; j <= num[i]; j++)
            {
                t[i] = max(t[i], t[i + node[cnt].js]);
                cnt++;
            }
        }
    }
    cout << t[1];
    return 0;
}