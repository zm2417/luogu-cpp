#include <iostream>
#include <cmath>
using namespace std;

int n, c[1000010],maxNum = INT32_MIN;

int main()
{
    cin >> n;
    for(int i = 0;i<n;i++)
    {
        int j;
        cin >> j;
        maxNum = max(maxNum,j);
        int m = sqrt(j);
        for (int k = 1; k <= m; k++)
        {
            if(j % k == 0)
            {
                c[k]++;
                if(j != k * k)
                    c[j / k]++;
            }
        }
    }
    int t = maxNum;
    for (int i = 1; i <= n; i++)
    {
        while (c[t] < i ) t--;
        cout << t << endl;
    }
    return 0;
}