#include <iostream>
using namespace std;

int n, k;
const int maxInf = 100010;

int parent[maxInf * 3];
void init()
{
    for (int i = 1; i <= 3 * n; i++)
    {
        parent[i] = i;
    }
}
int find(int x)
{
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unionSet(int x, int y)
{
    int xp = find(x), yp = find(y);
    if (xp != yp)
    {
        parent[xp] = yp;
    }
}

int main()
{
    cin >> n >> k;
    init();
    int ans = 0;
    for (int i = 0; i < k; i++)
    {
        int j, x, y;
        cin >> j >> x >> y;
        if (x > n || y > n)
        {
            ans++;
        }
        else if (j == 1)
        {
            if (find(x + n) == find(y) || find(x + 2 * n) == find(y))
            {
                ans++;
            }
            else
            {
                unionSet(x, y);
                unionSet(x + n, y + n);
                unionSet(x + 2 * n, y + 2 * n);
            }
        }
        else if (j == 2)
        {
            if (x == y)
            {
                ans++;
            }
            else
            {
                if (find(x) == find(y) || find(y + n) == find(x))
                {
                    ans++;
                }
                else
                {
                    unionSet(x, y + 2 * n);
                    unionSet(x + n, y);
                    unionSet(x + 2 * n, y + n);
                }
            }
        }
    }
    cout << ans;
    return 0;
}