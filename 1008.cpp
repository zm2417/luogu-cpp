#include <iostream>
using namespace std;
int used[10];

bool h(int a)
{
    while (a != 0)
    {
        if(used[a % 10] == 1)
            return false;
        used[a%10] = 1;
        a /= 10;
    }
    return true;
}
int main()
{
    used[0] = 1;
    for (int i = 123; i < 333; i++)
    {
        for (int i = 1; i < 10; i++)
        {
            used[i] = 0;
        }
        
        int a = i;
        int j = i*2;
        int k = i*3;
        if(h(a) && h(j) && h(k))
            cout << a << ' ' << j << ' ' << k << endl;
    }
    
}