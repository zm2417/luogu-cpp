#include <iostream>
using namespace std;

int d[5001][5001];

int main()
{
    int n;
    cin >> n;
    int len = 1;
    d[1][0] = 1;
    d[2][0] = 2;
    for (int i = 3; i <= n; i++)
    {
        int jinwei = 0;
        for (int j = 0;j < len; j++)
        {
            d[i][j] = d[i-1][j] + d[i-2][j] + jinwei;
            jinwei = d[i][j] / 10;
            d[i][j] %= 10;
        }
        if(jinwei != 0)
        {
            d[i][len] = jinwei;
            len++;
        }
    }
    for (int i = len - 1; i >= 0; i--)
    {
        cout << d[n][i];
    }
    return 0;
}