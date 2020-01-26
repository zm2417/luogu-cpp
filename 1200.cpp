#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s1,s2;
    cin >> s1 >> s2;
    int ans1 = 1,ans2 = 1;
    for (int i = 0; i < s1.size(); i++)
    {
        ans1 *= (s1[i] - 'A' + 1);
    }
    for (int i = 0; i < s2.size(); i++)
    {
        ans2 *= (s2[i] - 'A' + 1);
    }
    // cout << ans1 << ' ' << ans2 << endl;
    if(ans1 % 47 == ans2 % 47)
        cout << "GO";
    else
    {
        cout << "STAY";
    }
    
}