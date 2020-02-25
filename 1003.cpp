#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int d[n][4];
    for (int i = 0; i < n; i++)
    {
        int a, b, g, k;
        cin >> a >> b >> g >> k;
        d[i][0] = a;
        d[i][1] = b;
        d[i][2] = g;
        d[i][3] = k;
        // for (int j = 0; j <= g; j++)
        // {
        //     for (int l = 0; l <= k; l++)
        //     {
        //         d[a + j][b + l] = i;
        //     }
        // }
    }
    int x, y;
    cin >> x >> y;
    int res = -1;
    bool mask = false;
    for (int i = n-1; i >=0; i--)
    {
        if(x>=d[i][0] && x <= d[i][2]+d[i][0] && y >= d[i][1] && y <= d[i][1]+d[i][3]){
            res = i+1;
            mask = true;
            break;
        }
    }
    if(mask)
        cout << res;
    else
    {
        cout << -1;
    }
    
    return 0;
}