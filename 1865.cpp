#include <iostream>
using namespace std;

int d[1000001];

void init(int m)
{
    d[1] = 0;
    for (int i = 2; i <= m; i++)
    {
        if (d[i] == 0)
        {
            int x = i+i;
            while (x <= m)
            {
                d[x] = 1;
                x += i;
            }
        }
    }
    d[1] = 0;
    for (int i = 2; i <= m; i++)
    {
        if (d[i] == 0)
        {
            d[i] = d[i-1] + 1;
        }else
        {
            d[i] = d[i-1];
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    init(m);
    for(int i = 0;i<n;i++)
    {
        int l,r;
        cin >> l >>r;
        if(l > m || l < 1 || r > m || r < 1)
        {
            cout << "Crossing the line" << endl;
        }else
        {
            cout << d[r] - d[l-1] << endl;
        }
        
    }
    return 0;
}