// #include<iostream>
// using namespace std;
// double x,n,l,k=0;
// int main()
// {
//     cin>>n>>x;k=0;l=7.0;//设置初始值。 
//     while(k<n-x)//当小鱼不危险时。 
//     {
//        k+=l;l*=0.98;//每次步数*0.98 
//     }
//     if(k+l>n+x)cout<<"n";else cout<<"y";
//     return 0;//输出； 
// }

#include <cstdio>
using namespace std;

int main()
{
    double s, x;
    scanf("%lf%lf", &s, &x);
    double distant = 0.0;
    double d = 7.0;
    while (distant < (s - x))
    {
        distant += d;
        d *= 0.98;
    }
    if (distant + d <= s + x)
    {
        printf("%s", "y");
        return 0;
    }
    printf("%s", "n");
    return 0;
}