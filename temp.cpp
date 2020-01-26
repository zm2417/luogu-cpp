#include <iostream>
#include <algorithm>
using namespace std;

int a,b,l,r,mid;
int A[1000001];
inline bool check(int x)
{
    int rgt=A[1]+x;
    int sum=1;
    for(int i=2;i<=a;i++)
    {
        if(A[i]>=rgt)
        {
            sum++;
            rgt=A[i]+x;
        }
    }
    return sum>=b;
}
int main()
{
    cin>>a>>b;
    for(int i=1;i<=a;i++)
       cin>>A[i];
    std::sort(A+1,A+1+a);
    l=0,r=A[a]-A[1];
    while(l<=r)
    {
        mid=(l+r)/2;
        if(check(mid))l=mid+1;
        else r=mid-1;
    }
    cout<<r<<endl;
    return 0;
}