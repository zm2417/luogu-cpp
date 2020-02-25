#include <iostream>
using namespace std;

char d[2048][2048];

int main()
{
    int n;
    cin >> n;
    n--;

    for (int i = 0; i != 2048; i++)
        for (int j = 0; j != 2048; j++)
            d[i][j] = ' ';

    d[0][0] = d[0][3] = ' ';
    d[0][1] = d[1][0] = '/';
    d[0][2] = d[1][3] = '\\';
    d[1][1] = d[1][2] = '_';

    int h = 2, w = 4;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < h; j++)
        {
            for (int k = 0; k < w; k++)
            {
                d[j + h][k] = d[j + h][k + w] = d[j][k];
                d[j][k] = ' ';
            }
        }
        for (int j = 0; j < h; j++)
        {
            for (int k = w / 2; k < 3 * w / 2; k++)
            {
                d[j][k] = d[j + h][k + w / 2];
            }
        }
        h *= 2, w *= 2;
    }

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cout << d[i][j];
        }
        cout << endl;
    }
    return 0;
}