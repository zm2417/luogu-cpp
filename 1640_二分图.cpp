#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1000001;
const int MAX = 10010;
int n, n1, n2;
int ans;
int max_attribute, min_attribute = MAX;
int attribute[MAXN];
int vis[MAXN];
int id = 1;

struct Node
{
    int n1, n2;
} node[MAXN];
vector<int> v[MAX];

bool dfs(int x)
{
    for (int j = 0; j < v[x].size(); j++)
    {
        int i = v[x][j];
        if (vis[i] != id)
        {
            vis[i] = id;
            if (attribute[i] == 0 || dfs(attribute[i]))
            {
                attribute[i] = x;
                return true;
            }
        }
    }
    return false;
}

// void initVis()
// {
//     for (int i = 0; i < MAXN; i++)
//         vis[i] = 0;
// }

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> n1 >> n2;
        max_attribute = max(max_attribute, max(n1, n2));
        // node[i].n1 = n1;
        // node[i].n2 = n2;
        v[n1].push_back(i);
        v[n2].push_back(i);
    }
    for (int i = 1; i <= max_attribute; i++, id++)
    {
        // initVis();
        if (dfs(i))
            ans++;
        else
            break;
    }
    cout << ans << endl;
    return 0;
}