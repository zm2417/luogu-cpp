#include <iostream>
using namespace std;

int n;
int d[25];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
    }
    for (int i = 1; i <= n; i++)
        if (d[i] == 0)
        {
            if (i % 2 == 0)
                return puts("YES"), 0;
            break;
        }
    for (int i = n; i >= 1; i--)
        if (d[i] == 0)
        {
            if ((n - i + 1) % 2 == 0)
                return puts("YES"), 0;
            break;
        }
    puts("NO");
    return 0;
}