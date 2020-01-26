#include <iostream>
using namespace std;

const int maxInf = 100005;
int n;
int tree[maxInf], e[maxInf], ans;

int lowbit(int x)
{
    return x & (-x);
}

void add(int x, int k)
{
    while (x < maxInf)
    {
        tree[x] += k;
        x += lowbit(x);
    }
}

int query(int x)
{
    // int a = 0;
    // while (x > 0)
    // {
    //     a += tree[x];
    //     x -= lowbit(x);
    // }
    // return a;
    int sum = 0;
    for (; x; x &= x - 1)
        sum += tree[x];
    return sum;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        if (c == 'A')
        {
            int start, end, del = 0;
            cin >> start >> end;
            while (true)
            {
                int l = 0, r = end;
                int p = query(end);

                while (l < r)
                {
                    int mid = (l + r) / 2;
                    if (query(mid) + 1 <= p)
                        l = mid + 1;
                    else
                        r = mid;
                }
                if (e[l] >= start)
                {
                    add(l, -1);
                    del++;
                    ans--;
                }
                else
                {
                    break;
                }
            }
            add(start, 1);
            e[start] = end;
            ans++;
            cout << del << endl;
        }
        else
        {
            cout << ans << endl;
        }
    }
    return 0;
}