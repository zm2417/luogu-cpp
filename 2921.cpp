#include <iostream>
using namespace std;

const int maxInf = 100010;
int n, d[maxInf];
int head[maxInf], huan[maxInf], dis[maxInf], in[maxInf];

void help()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = i, cnt = 0;; j = d[j], cnt++)
        {
            if (head[j] == 0)
            {
                head[j] = i;
                dis[j] = cnt;
            }
            else if (head[j] == i)
            {
                huan[i] = cnt - dis[j];
                in[i] = dis[j];
                cout << cnt << endl;
                break;
            }
            else
            {
                huan[i] = huan[head[j]];
                in[i] = cnt + max(0,in[head[j]] - dis[j]);
                cout << in[i] + huan[i] << endl;
                break;
            }
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
    }
    help();
    return 0;
}