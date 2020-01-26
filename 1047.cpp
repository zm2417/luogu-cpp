#include <iostream>
using namespace std;

int main()
{
    int l,m;
    cin >> l >> m;
    int d[l+1] = {0};
    for (int i = 0; i < m; i++)
    {
        int start,end;
        cin >> start >> end;
        for (int j = start; j <= end; j++)
        {
            d[j] = 1;
        }
        
    }
    int ans = 0;
    for (int i = 0; i <= l; i++)
    {
        if(d[i] ==0 )
            ans++;
    }
    cout << ans;
}