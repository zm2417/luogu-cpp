#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    n -= 4;
    int match[2010] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    for (int i = 10; i < 2010; i++)
    {
        int j = 0;
        int k = i;
        while (k != 0)
        {
            j += match[k % 10];
            k /= 10;
        }
        match[i] = j;
    }

    int ans = 0;
    for (int i = 0; i <= 1000; i++)
    {
        for (int j = i; j <= 1000; j++)
        {
            int x = i + j;
            int m = n - match[i] - match[j];
            if (m == match[x])
            {
                if (i != j)
                {
                    ans += 2;
                }
                else
                {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}