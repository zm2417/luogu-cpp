#include <iostream>
#include <string>
using namespace std;

int main()
{
    int s,t,w;
    cin >> s >> t >> w;
    string jam;
    cin >> jam;
    for (int i = 0; i < 5; i++)
    {
        for (int j = w-1;j >= 0; j--)
        {
            if(jam[j] + 1 <= ('a' + t - w+j))
            {
                jam[j]++;
                for (int k = j+1; k < w; k++)
                {
                    jam[k] = jam[j] + k - j;
                }
                cout << jam.c_str() << endl;
                break;
            }
        }
    }
    return 0;
}