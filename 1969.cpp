#include <iostream>
using namespace std;

int main()
{
    int n,res = 0;
    cin >> n;
    int d[n];
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
    }

    res = d[0];
    for (int i = 1; i < n; i++)
    {
        if(d[i] > d[i-1])
        {
            res += d[i] - d[i-1];
        }
    }
    cout << res;
    return 0;

}