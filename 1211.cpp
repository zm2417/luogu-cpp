#include <iostream>
using namespace std;

int n;
int d[10], mark[10];
int ans;

bool check(int a, int s)
{
    while (a > 0)
    {
        if (d[a % 10] == 0)
            return false;
        s--;
        a /= 10;
    }
    return s == 0;
}

void dfs()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int l = 0; l < n; l++)
            {
                for (int k = 0; k < n; k++)
                {
                    for (int a = 0; a < n; a++)
                    {
                        int b = mark[i] * 100 + mark[j] * 10 + mark[l];
                        int c = mark[k] * 10 + mark[a];
                        if(check(b*c,4) && check(b*mark[k],3) && check(b*mark[a],3))
                            ans++;
                    }
                }
            }
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> mark[i];
        d[mark[i]] = 1;
    }
    dfs();
    cout << ans<<endl;
    return 0;
}