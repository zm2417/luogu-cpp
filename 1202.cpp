#include <iostream>
using namespace std;

int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int num[7];

int judge(int x)
{
    if (x % 100 == 0)
    {
        if (x % 400 == 0)
        {
            return 29;
        }
        else
        {
            return 28;
        }
    }
    else
    {
        return x % 4 == 0 ? 29 : 28;
    }
}

int main()
{
    int n;
    cin >> n;
    long long d = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            int t = (d + 13) % 7;
            num[t]++;
            if (j == 1)
            {
                d += judge(1900 + i);
            }
            else
            {
                d += day[j];
            }
        }
    }
    cout << num[6] << ' ' << num[0] << ' ';
    for (int i = 1; i <= 5; i++)
    {
        cout << num[i] << ' ';
    }
    
}