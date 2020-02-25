#include <iostream>
using namespace std;

const int maxInf = 1000010;
int n, d[maxInf], cnt = 0;

int parent(int p)
{
    return p / 2;
}
int left(int p)
{
    return p * 2;
}
int right(int p)
{
    return p * 2 + 1;
}

void shiftUp(int p)
{
    while (p / 2 >= 1)
    {
        if (d[parent(p)] > d[p])
        {
            swap(d[parent(p)], d[p]);
            p /= 2;
        }
        else
        {
            break;
        }
    }
}
void shiftDown(int p)
{
    while (p * 2 <= cnt)
    {
        int t = left(p);
        if (t + 1 <= cnt && d[t] > d[t + 1])
        {
            t++;
        }
        if (d[t] < d[p])
        {
            swap(d[t], d[p]);
            p = t;
        }
        else
        {
            break;
        }
    }
}

void insert(int x)
{
    d[++cnt] = x;
    shiftUp(cnt);
}
void pop()
{
    d[1] = d[cnt--];
    shiftDown(1);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int j;
            cin >> j;
            insert(j);
        }
        else if (op == 2)
        {
            cout << d[1] << endl;
        }
        else
        {
            pop();
        }
    }
    return 0;
}