#include <iostream>
#include <algorithm>
using namespace std;

int a,b,d[100000];

bool judge(int x)
{
    int ret = 1,last = d[0];
    for (int i = 1; i < a; i++)
    {
        if(d[i] - last >= x)
            last = d[i],ret++;
        if(ret >= b)
            return true;
    }
    return ret >= b;
}

int main()
{
    cin >> a >> b;

    for (int i = 0; i < a; i++)
    {
        cin >> d[i];
    }
    sort(d,d+a);
    int l = 0,r = d[a-1] - d[0];
    while (l<=r)
    {
        int mid = (l+r) >> 1;
        if(judge(mid)) 
            l = mid+1;
        else 
            r = mid-1;
    }
    cout << r << endl;
    return 0;
}