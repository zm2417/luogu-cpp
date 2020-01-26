#include <iostream>
#include <string>
using namespace std;

void help(string mid, string after)
{
    int size = mid.size();
    char root = after[size - 1];
    cout << root;
    if (size == 1)
        return;
    for (int i = 0; i < mid.size(); i++)
    {
        if (root == mid[i])
        {
            if(i != 0)
                help(mid.substr(0, i), after.substr(0, i));
            if(i != size-1)
                help(mid.substr(i+1, size), after.substr(i, size - 1));
        }
    }
}

int main()
{
    string mid, after;
    cin >> mid >> after;
    help(mid, after);
}