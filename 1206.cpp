#include <iostream>
#include <vector>
using namespace std;

int b;
int d[301];

void print(vector<int> v)
{
    for (int i = v.size() - 1; i >=0; i--)
    {
        if (v[i] < 10)
            cout << v[i];
        else
        {
            cout << (char)(v[i] - 10 + 'A');
        }
    }
}

void transform(int k, int j)
{
    vector<int> v;
    while (j > 0)
    {
        v.push_back(j % b);
        j /= b;
    }

    for (int i = 0, j = v.size() - 1; i < j; i++, j--)
    {
        if (v[i] != v[j])
            return;
    }
    vector<int> v1;
    while (k > 0)
    {
        v1.push_back(k % b);
        k /= b;
    }
    print(v1);
    cout << ' ';
    print(v);
    cout << endl;
}



int main()
{
    cin >> b;
    for (int i = 1; i <= 300; i++)
    {
        transform(i, i * i);
    }
    return 0;
}