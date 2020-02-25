#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
    int n, j = 0;
    cin >> n;
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        s.insert(t);
    }
    cout << s.size()<<endl;
    set<int>::iterator iter = s.begin();
    while (iter != s.end())
    {
        cout << *iter << ' ';
        iter++;
    }
    return 0;
}