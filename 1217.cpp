#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

const int maxInf = 100000001;
int a, b;
bool prime[maxInf];
vector<int> d;

bool isprime(int x)
{
    if (x < 2)
        return false;
    if (x == 2)
        return true;
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

void get_prime()
{
    int n = sqrt(b);
    for (int i = 2; i <= n; i++)
    {
        if (prime[i] == 0)
        {
            for (int j = 2; j <= b / i; j++)
            {
                prime[i * j] = 1;
            }
        }
    }
}

int getNum1(int i)
{
    int ans = 0;
    for (int i = 0; i < d.size(); i++)
    {
        ans = ans * 10 + d[i];
    }
    ans = ans * 10 + i;
    for (int i = d.size() - 1; i >= 0; i--)
    {
        ans = ans * 10 + d[i];
    }
    return ans;
}

int getNum2()
{
    int ans = 0;
    for (int i = 0; i < d.size(); i++)
    {
        ans = ans * 10 + d[i];
    }
    for (int i = d.size() - 1; i >= 0; i--)
    {
        ans = ans * 10 + d[i];
    }
    return ans;
}

void dfs(int n, int p)
{
    if (n / 2 == p)
    {
        int ans = 0;
        if (n % 2 == 1)
        {
            for (int i = 0; i < 10; i++)
            {
                ans = getNum1(i);
                if (ans <= b && ans >= a && isprime(ans))
                {
                    printf("%d\n", ans);
                }
            }
        }
        else
        {
            ans = getNum2();
            if (ans <= b && ans >= a && isprime(ans))
            {
                printf("%d\n", ans);
            }
        }
        return;
    }
    for (int i = 0; i < 10; i++)
    {
        if (d.size() == 0 && i == 0)
            continue;
        d.push_back(i);
        dfs(n, p + 1);
        d.pop_back();
    }
}

int main()
{
    cin >> a >> b;
    // get_prime();

    for (int i = 1; i < 8; i++)
    {
        if (i == 1)
        {
            if (a <= 5 && b >= 5)
                cout << 5 << endl;
            if (a <= 7 && b >= 7)
                cout << 7 << endl;
        }
        else if (i == 2)
        {
            if (a <= 11 && b >= 11)
                cout << 11 << endl;
        }
        else if (i % 2 == 1)
            dfs(i, 0);
    }
    return 0;
}