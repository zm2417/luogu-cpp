#include <iostream>
#include <unordered_map>
#include <set>
using namespace std;

int ans = 0;
set<int> used;

void dfs(int key, unordered_map<int, set<int>> mp)
{
    if (used.find(key) == used.end())
    {
        ans++;
        used.insert(key);
        if (mp.find(key) != mp.end())
            for (int i : mp[key])
            {
                dfs(i, mp);
            }
        // cout << "ans " << key << ' ' << mp[key].size() << endl;
        
    }
    // cout << ans << endl;
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    std::unordered_map<int, set<int>> mp;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        if (mp.find(u) == mp.end())
        {
            set<int> s;
            mp[u] = s;
        }
        if (mp.find(v) == mp.end())
        {
            set<int> s1;
            mp[v] = s1;
        }
        mp[u].insert(v);
        mp[v].insert(u);
    }
    int ki = 1;
    for (int i = k; i > 0; i--)
    {
        ki *= i;
    }
    long long result = 0;
    for (int key = 1; key <= n; key++)
    {
        if (mp.find(key) != mp.end() && used.find(key) == used.end())
        {
            dfs(key, mp);
            long long kl = 1;
            for (int i = 0; i < k; i++)
            {
                kl *= (ans - i);
                kl %= 998244353;
            }
            result += (kl / ki) % 998244353;
            // cout << key << ' ' << ans << ' ' << kl << ' ' << result << endl;
        }
        ans = 0;
    }
    cout << result % 998244353;
    return 0;
}