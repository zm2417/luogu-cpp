#include <iostream>
#include <string>
#include <set>
#include <queue>
using namespace std;

int n, count = 0;
string a, b, ans = "NO ANSWER!";
string A[6], B[6];
set<string> s;
queue<string> q;

void bfs()
{
    int p = 1;
    int temp = 0;
    while (!q.empty())
    {
        string t = q.front();
        if (t.compare(b) == 0)
        {
            cout << count;
            return;
        }
        for (int i = 0; i < n; i++)
        {
            int position = 0;
            while ((position = t.find(A[i], position)) != string::npos)
            {
                string t1;
                t1.assign(t);
                t1.replace(position, A[i].size(), B[i]);
                if (t1.compare(b) == 0)
                {
                    cout << count + 1;
                    return;
                }
                if (s.find(t1) == s.end())
                {
                    q.push(t1);
                    temp++;
                    s.insert(t1);
                }
                position++;
            }
        }
        q.pop();
        p--;
        if (p == 0)
        {
            p = temp;
            temp = 0;
            count++;
            if (count > 10)
            {
                cout << ans.c_str();
                return;
            }
        }
    }
    cout << ans.c_str();
}

int main()
{
    cin >> a >> b;
    while (cin >> A[n] >> B[n])
    {
        n++;
    }
    q.push(a);
    s.insert(a);

    bfs();
    return 0;
}