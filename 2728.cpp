#include <iostream>
#include <cstring>
using namespace std;

int speed[5], w[5];
int p[5][5], v[5][5];
int a[361];

int main()
{
    for (int i = 0; i < 5; i++)
    {
        cin >> speed[i] >> w[i];
        for (int j = 0; j < w[i]; j++)
        {
            cin >> p[i][j] >> v[i][j];
        }
    }

    for (int i = 0; i <= 360; i++)
    {
        memset(a, 0, sizeof(a));
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < w[j]; k++)
            {
                for (int l = p[j][k]; l <= p[j][k] + v[j][k]; l++)
                    a[l % 360]++;
                p[j][k] = (p[j][k] + speed[j]) % 360;
            }
        }

        for(int j = 0;j<=360;j++)
            if(a[j] == 5)
            {
                cout << i << endl;
                return 0;
            }
    }
    cout << "none" << endl;
    return 0;
}