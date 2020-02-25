#include <iostream>
using namespace std;

int n;

int main()
{
    cin >> n;
    double t, ans;
    t = 420000.0 / n;
    for (int i = 1; i <= n; i++)
    {
        ans += t;
        t *= (1 - 0.5 / i);
    }
    printf("%.2lf\n", ans);
    return 0;
}