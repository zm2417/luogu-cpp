#include <iostream>
#include <unordered_set>
#include <queue>
using namespace std;

int main()
{
    int m, n, res = 0;
    cin >> m >> n;
    unordered_set<int> w;
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        int j;
        cin >> j;
        if (w.find(j) == w.end())
        {
            res++;
            w.insert(j);
            q.push(j);
            if (w.size() > m)
            {
                int k = q.front();
                w.erase(k);
                q.pop();
            }
        }
    }
    cout << res;

    return 0;
}