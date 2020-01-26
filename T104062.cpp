#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    unordered_map<string, string> m;
    for (int i = 0; i < n; i++)
    {
        string t1, t2;
        cin >> t1 >> t2;
        m[t1] = t2;
    }
    for (int i = 0; i < q; i++)
    {
        string t, t1, t2, t3, t4;
        cin >> t >> t1 >> t2 >> t3 >> t4;
        string ans = m[t];
        if (ans.compare(t1) == 0)
            cout << 'A' << endl;
        else if (ans.compare(t2) == 0)
            cout << 'B' << endl;
        else if (ans.compare(t3) == 0)
            cout << 'C' << endl;
        else if (ans.compare(t4) == 0)
            cout << 'D' << endl;
    }
    return 0;
}