#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int d[n][3];
    for (int i = 0; i < n; i++)
    {
        cin >> d[i][0] >> d[i][1] >> d[i][2];
    }
    // m = 2000;

    int ans = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int x = abs(d[0][0] - i) ^ abs(d[0][1] - j) ^ 9;
            int k1 = d[0][2] - x,k2 = d[0][2] + x;

            if(k1 > 0 && k1 <=m)
            {
                bool mask = true;
                for (int l = 1; l < n; l++)
                {
                    if((abs(d[l][0] - i) ^ abs(d[l][1] - j) ^ abs(d[l][2] - k1) )!= 9)
                    {
                        mask = false;
                        break;
                    }
                }
                if(mask)
                {
                    ans++;
                }
            }

            if(k2 > 0 && k2 <=m && k1 != k2)
            {
                bool mask = true;
                for (int l = 1; l < n; l++)
                {
                    if((abs(d[l][0] - i) ^ abs(d[l][1] - j) ^ abs(d[l][2] - k2) )!= 9)
                    {
                        mask = false;
                        break;
                    }
                }
                if(mask)
                {
                    ans++;
                }
            }

            // for (int k = 1; k <= m; k++)
            // {
            //     bool mask = true;
            //     for (int l = 0; l < n; l++)
            //     {
            //         if((abs(d[l][0] - i) ^ abs(d[l][1] - j) ^ abs(d[l][2] - k) )!= 9)
            //         {
            //             mask = false;
            //             break;
            //         }
            //     }
            //     if(mask)
            //     {
            //         ans++;
            //     }
            //     // if(i ^ j ^ k == 9)
            //     // {
            //     //     cout << i << ' ' << j <<' ' << k <<endl;
            //     // }
            // }
        }
    }
    cout << ans;
    return 0;
}