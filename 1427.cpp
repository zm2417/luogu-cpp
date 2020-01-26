#include <iostream>
using namespace std;

int main()
{
    int d[100],num = 0,i;
    while (cin >> i)
    {
        if(i == 0)
            break;
        d[num++] = i;
    }
    for (int i = num - 1; i >= 0; i--)
    {
        cout << d[i] <<' ';
    }
    
}