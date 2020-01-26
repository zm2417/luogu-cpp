#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    for (int i = 1; i <= 7; i++)
    {
        int a,b;
        cin >> a >> b;
        if(a+b > 8)
        {
            cout << i;
            return 0;
        }
    }
    
}