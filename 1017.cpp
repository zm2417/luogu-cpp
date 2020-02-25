#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, r;
    cin >> n >> r;
    cout << n << '=';
    char d[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J'};

    vector<char> v;
    while (n)
    {
        int a = n % r;
        n /= r;
        if (a < 0)
        {
            a -= r;
            n++;
        }
        v.push_back(d[a]);
    }
    for (int i = v.size() - 1; i >= 0; i--)
    {
        cout << v[i];
    }
    cout << "(base" << r << ")";
    return 0;
}