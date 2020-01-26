#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int d[n];
    string s[n];
    for (int i = 0; i < n; i++)
    {
        cin >> d[i] >> s[i];
    }
    int p = 0;
    for (int i = 0; i < m; i++)
    {
        int j, k;
        cin >> j >> k;

        if ((d[p] == 0 && j == 1) || d[p] == 1 && j == 0)
        {
            p = (p + k) % n;
        }
        else
        {
            p = (n + p - k) % n;
        }
    }

    cout << s[p].c_str();

    return 0;
}