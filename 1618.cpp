#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    bool flag = false;

    for (int i = 100; i <= 999; i++)
    {
        bool mask = true;
        int d[10] = {0};
        int j = i * b / a;
        int k = i * c / a;
        if (j > 100 && j < 999 && k > 100 && k < 999)
        {
            d[i / 100]++;
            d[i % 10]++;
            d[(i / 10) % 10]++;
            d[j / 100]++;
            d[j % 10]++;
            d[(j / 10) % 10]++;
            d[k / 100]++;
            d[k % 10]++;
            d[(k / 10) % 10]++;
        }
        for (int l = 1; l < 10; l++)
        {
            if (d[l] != 1)
            {
                mask = false;
                break;
            }
        }
        if (mask)
        {
            flag = true;
            cout << i << ' ' << j << ' ' << k << endl;
        }
    }
    if (!flag)
    {
        cout << "No!!!";
    }
}