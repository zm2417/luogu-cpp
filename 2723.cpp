#include <iostream>
using namespace std;

const int max_n = 100005;
int k, n;
int d[105];
long long f[max_n];
int s[max_n];

int main()
{
    cin >> k >> n;
    for (int i = 0; i < k; i++)
    {
        cin >> d[i];
    }
    f[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        long long MIN = 99999999999999;
        for (int j = 0; j < k; j++)
        {
            while (f[i - 1] >= f[s[j]] * d[j])
            {
                s[j]++;
            }
            MIN = min(MIN, f[s[j]] * d[j]);
        }
        f[i] = MIN;
    }
    cout << f[n] << endl;
    return 0;
}