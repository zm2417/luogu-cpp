#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int maxInf = 205;
int m,s,c;
int ans;
priority_queue<int>q;
int d[maxInf];

int main()
{
    cin >> m >> s >> c;
    ans = c;
    int num = c - m;
    
    for (int i = 0; i < c; i++)
    {
        cin >> d[i];
    }
    if(num <= 0)
    {
        cout << c << endl;
        return 0;
    }
    sort(d,d+c);
    for (int i = 1; i < c; i++)
    {
        q.push(d[i] - d[i-1] - 1);
        if(q.size() > num){
            q.pop();
        }
    }
    while (!q.empty())
    {
        ans += q.top();
        q.pop();
    }
    cout << ans << endl;
    return 0;
    
}