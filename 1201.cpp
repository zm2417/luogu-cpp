#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    int np;
    cin >> np;
    map<string, int> m;
    string names[np];
    for (int i = 0; i < np; i++)
    {
        string name;
        cin >> name;
        m[name] = 0;
        names[i] = name;
    }
    for (int i = 0; i < np; i++)
    {
        string name;
        int money, person;
        cin >> name >> money >> person;
        int average = 0;
        if (money != 0 && person != 0)
        {
            average = money / person;
            m[name] += money % person;
            m[name] -= money;
        }

        for (int j = 0; j < person; j++)
        {
            string sendName;
            cin >> sendName;
            m[sendName] += average;
        }
    }
    for (int i = 0; i < np; i++)
    {
        cout << names[i] << ' ' << m[names[i]] << endl;
    }
    return 0;
}