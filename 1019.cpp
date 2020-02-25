#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Node
{
public:
    string a;
    int len = 0;
    int p = -1;
};

int visit[20];
int maxlen = 0;
unordered_map<string, vector<Node>> m;

void dfs(string s, int count)
{
    if (m.find(s) != m.end())
    {
        vector<Node> v = m[s];
        for (Node n : v)
        {
            if (visit[n.p] < 2)
            {
                visit[n.p]++;
                dfs(n.a, count + n.a.size() - n.len);
                visit[n.p]--;
            }
        }
    }
    maxlen = max(maxlen, count);
}

int main()
{
    int n;
    cin >> n;
    string s[n];
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    char start;
    cin >> start;

    for (int i = 0; i < n; i++)
    {
        vector<Node> v;
        for (int j = 0; j < n; j++)
        {
            int count = 0;
            for (int k = 1; k < min(s[i].size(), s[j].size()); k++)
            {
                bool flag = true;
                for (int l = 1; l <= k; l++)
                {
                    if (s[i][s[i].size() - l] != s[j][k - l])
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                {
                    Node n;
                    n.a = s[j];
                    n.len = k;
                    n.p = j;
                    v.push_back(n);
                    break;
                }
            }
        }
        m[s[i]] = v;
    }

    for (int i = 0; i < n; i++)
    {
        if (s[i][0] == start)
        {
            visit[i]++;
            dfs(s[i], s[i].size());
            visit[i]--;
        }
    }
    cout << maxlen;

    return 0;
}