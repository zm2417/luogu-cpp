#include <iostream>
using namespace std;

int d[10000001];

void init(int n)
{
    d[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (d[i] == 0)
        {
            int j = i + i;
            while (j <= n)
            {
                d[j] = 1;
                j += i;
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    init(n);
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        if (d[x] == 0)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}