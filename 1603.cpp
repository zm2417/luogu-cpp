#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    string d[6];

    unordered_map<string, int> b;
    int j = 1;
    b["one"] = 1;
    b["two"] = 2;
    b["three"] = 3;
    b["four"] = 4;
    b["five"] = 5;
    b["six"] = 6;
    b["seven"] = 7;
    b["eight"] = 8;
    b["nine"] = 9;
    b["ten"] = 10;
    b["eleven"] = 11;
    b["twelve"] = 12;
    b["thirteen"] = 13;
    b["fourteen"] = 14;
    b["fifteen"] = 15;
    b["sixteen"] = 16;
    b["seventeen"] = 17;
    b["eighteen"] = 18;
    b["nineteen"] = 19;
    b["twenty"] = 20;
    b["a"] = 1;
    b["both"] = 2;
    b["another"] = 1;
    b["second"] = 2;
    b["first"] = 1;
    b["third"] = 3;

    vector<int> v;
    for (int i = 0; i < 6; i++)
    {
        string t;
        cin >> t;
        if (b.find(t) != b.end())
        {
            v.push_back(b[t] * b[t] % 100);
        }
    }
    sort(v.begin(), v.end(), less<int>());
    string res;
    for(int i : v)
    {
        if(res.size() != 0 && i < 10)
        {
            res += "0";
        }
        res += to_string(i);
        
    }
    if(v.size() == 0)
        cout << 0;
    else
    {
        cout << res.c_str();
    }
    
}