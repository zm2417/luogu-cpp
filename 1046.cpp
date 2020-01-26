#include <iostream>
using namespace std;

int n, k, ans;
int d[20];

bool isPrime(int x)
{
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;
    return true;
}

void dfs(int i, int targetSum, int currentK)
{
    if (currentK == k)
    {
        if (isPrime(targetSum))
            ans++;
        return;
    }
    for (int j = i + 1; j < n; j++)
    {
        dfs(j, targetSum + d[j], currentK + 1);
    }
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
    }
    for (int i = 0; i < n; i++)
    {
        dfs(i, d[i], 1);
    }
    cout << ans << endl;
    return 0;
}