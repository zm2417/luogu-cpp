#include <iostream>
#include <algorithm>
using namespace std;

const int maxM = 255;
const int maxN = 30;
int d[maxM * maxM];
int s[200010];
int n, m;

struct Node
{
    int a, b;
} w[200010];

bool comp(Node n1, Node n2)
{
    if (n1.b == n2.b)
        return n1.a < n2.a;
    return n1.b < n2.b;
}

int main()
{
    cin >> n >> m;
    int p = 0;
    for (int i = 0; i <= m; i++)
    {
        for (int j = i; j <= m; j++)
        {
            if(s[i * i + j * j] == 0)
                d[p++] = i * i + j * j;
            s[i * i + j * j] = 1;
        }
    }
    sort(d, d + p);
    bool ans = false;
    int num = 0;
    // 确定数列只需要前两个元素
    for (int i = 0; i < p; i++)
    {
        for (int j = i + 1; j < p; j++)
        {
            int a = d[j], b = d[j] - d[i];
            if(d[i] + (n-1) * b > d[p-1])
                break;
            bool flag = false;
            for (int k = 3; k <= n; k++)
            {
                a += b;
                if(s[a] == 0)
                {
                    flag = true;
                    break;
                }
            }
            if(!flag)
            {
                ans = true;
                w[num].a = d[i];
                w[num].b = b;
                num++;
            }
        }
    }
    if (!ans)
        cout << "NONE" << endl;
    sort(w,w+num,comp);
    for (int i = 0; i < num; i++)
    {
        cout << w[i].a << ' ' << w[i].b << endl;
    }
    
    return 0;
}