#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

struct Node
{
    int x;
    int y;
    int val;
};

bool comp(Node n1,Node n2)
{
    return n1.val > n2.val;
}

int main()
{
    int m,n,k;
    cin >> m >> n>>k;
    int d[m][n] = {0};
    vector<Node> v;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int t;
            cin >> t;
            if(t >0)
            {
                Node n = {j,i,t};
                v.push_back(n);
            }
        }
    }

    sort(v.begin(),v.end(),comp);
    int ans = 0,tiao = 2,lastx = 0,lasty = 0;
    bool start = true;
    for (int i = 0; i < v.size(); i++)
    {
        Node n = v[i];
        if(start)
        {
            start = false;
            tiao += n.y+1;
            lastx = n.x;
            lasty = n.y;
            if(tiao + n.y <= k)
            {
                ans += n.val;
                // cout << tiao << ' ' << n.y << ' ' << n.val << ' ' << ans << endl;
            }else
            {
                break;
            }
        }else
        {
            tiao += abs(n.x - lastx) + abs(n.y - lasty)+1;
            lastx = n.x;
            lasty = n.y;
            // cout << tiao << ' ' << n.y << ' ' << n.val << ' ' << ans << endl;
            if(tiao + n.y <= k)
            {
                
                ans += n.val;
                
            }else
            {
                break;
            }
        }
        
    }
    cout << ans << endl;
    return 0;
}