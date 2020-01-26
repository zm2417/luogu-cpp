#include <iostream>
using namespace std;

int main()
{
    int d[10];
    for (int i = 0; i <= 9; i++)
    {
        cin >> d[i];
    }
    int h, ans = 0;
    cin >> h;
    h += 30;
    for (int i = 0; i <= 9; i++)
    {
        if (d[i] <= h)
            ans++;
    }
    cout << ans;
}