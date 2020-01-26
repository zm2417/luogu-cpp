#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int d[3][2];
    for (int i = 0; i < 3; i++)
    {
        cin >> d[i][0] >> d[i][1];
    }
    long long m = ceil(n*1.0/d[0][0]) * d[0][1];
    m = min(m,(long long)ceil(n*1.0/d[1][0]) * d[1][1]);
    m = min(m,(long long)ceil(n*1.0/d[2][0]) * d[2][1]);
    cout << m;
    return 0;
}