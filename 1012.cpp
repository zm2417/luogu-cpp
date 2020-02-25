#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool comp(string a, string b)
{
    return a + b > b + a;
}

int main()
{
    int n;
    cin >> n;
    string d[n];
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
    }
    sort(d, d + n, comp);
    string ans;
    for(int i =0;i<n;i++)
    {
        ans += d[i];
    }
    cout << ans.c_str();
    return 0;
}