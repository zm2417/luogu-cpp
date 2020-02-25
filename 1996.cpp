#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }
    int p = 0;
    while (!q.empty())
    {
        int i = q.front();
        q.pop();
        p++;
        if(p == m)
        {
            cout << i << ' ';
            p = 0;
        }else
        {
            q.push(i);
        }
    }
    return 0;
}