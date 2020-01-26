#include <iostream>
#include <stack>
using namespace std;

int f;
int d[1300][1300];
int du[1300];
int n;
stack<int> s;

void dfs(int start)
{
    for (int i = 1; i <= n; i++)
    {
        if (d[start][i] > 0)
        {
            d[start][i]--;
            d[i][start]--;
            dfs(i);
        }
    }
    s.push(start);
}

int main()
{
    cin >> f;
    for (int i = 0; i < f; i++)
    {
        int k, l;
        cin >> k >> l;
        n = max(n, max(k, l));
        d[k][l]++;
        d[l][k]++;
        du[k]++;
        du[l]++;
    }
    // 查找开始节点
    int start = 1;
    for (int i = 1; i <= n; i++)
    {
        if (du[i] % 2 == 1)
        {
            start = i;
            break;
        }
    }
    dfs(start);
    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}