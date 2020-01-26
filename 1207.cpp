#include <iostream>
#include <vector>
using namespace std;

int n, s;

int transform(int k, int j)
{
    vector<int> v;
    while (j > 0)
    {
        v.push_back(j % k);
        j /= k;
    }

    for (int i = 0, j = v.size() - 1; i < j; i++, j--)
    {
        if (v[i] != v[j])
            return 0;
    }
    return 1;
}

int main()
{
    cin >> n >> s;
    for (int i = s+1; ; i++)
    {
        int num = 0;
        for (int j = 2; j <= 10; j++)
        {
            num += transform(j,i);
        }
        if(num >= 2)
        {
            cout << i << endl;
            n--;
        }
        if(n <=0 )
            return 0;
    }
    
}