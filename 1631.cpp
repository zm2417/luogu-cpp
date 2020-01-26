#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int maxInf = 100005;
int n, d[maxInf], b[maxInf];
priority_queue<int> q;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    sort(d, d + n);
    sort(b, b + n);
    int x;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            x = d[i] + b[j];
            if (q.size() >= n)
            {
                if(q.top() <= x)
                    break;
                q.pop();
                q.push(x);
            }else
            {
                q.push(x);
            }
        }
    }

    int ans[n];
    for (int i = 0; i < n; i++)
    {
        ans[i] = q.top();
        q.pop();
    }
    for (int i = n - 1; i >= 0; i--)
    {
        cout << ans[i] << ' ';
    }
    return 0;
}