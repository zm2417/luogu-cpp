#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int e;
    cin >> e;
    if(e <= 150)
    {
        printf("%0.1f",e*0.4463);
    }else if (e <= 400)
    {
        printf("%0.1f",150*0.4463+(e-150)*0.4663);
    }else
    {
        printf("%0.1f",150*0.4463+(250)*0.4663+(e-400)*0.5663);
    }
}