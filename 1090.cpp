#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int d[n];
    priority_queue<int, vector<int>, greater<int> > q;
    for (int i = 0; i < n; i++)
    {
        int j;
        cin >> j;
        q.push(j);
    }
    long long ans = 0;
    while (q.size() > 1)
    {
        int i = q.top();
        q.pop();
        int j = q.top();
        q.pop();
        ans += (i+j);
        q.push(i+j);
    }

    cout << ans;
    return 0;
}