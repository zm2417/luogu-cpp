#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(pair<int, int> &a, pair<int, int> &b)
{
    return a.second > b.second;
}

int main()
{
    // M行N列 K条横向的通道，L条纵向的通道
    int m, n, k, l, d;
    cin >> m >> n >> k >> l >> d;

    int row[m + 1] = {0}, colum[n + 1] = {0};
    for (int i = 0; i < d; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a == c)
        {
            //行一样，列差1
            int t = min(b, d);
            colum[t]++;
        }
        else
        {
            row[min(a, c)]++;
        }
    }
    vector<pair<int, int>> rv, cv;
    for (int i = 0; i < m + 1; i++)
    {
        // cout << row[i] << ' ';
        rv.push_back({i, row[i]});
    }
    // cout << endl;
    for (int i = 0; i < n + 1; i++)
    {
        // cout << colum[i] << ' ';
        cv.push_back({i, colum[i]});
    }
    // cout << endl;
    sort(rv.begin(), rv.end(), comp);
    sort(cv.begin(), cv.end(), comp);

    vector<int> rtemp;
    for (int i = 0; i < k; i++)
    {
        rtemp.push_back(rv[i].first);
    }

    vector<int> ctemp;
    for (int i = 0; i < l; i++)
    {
        ctemp.push_back(cv[i].first);
    }

    sort(rtemp.begin(), rtemp.end(), less<int>());
    sort(ctemp.begin(), ctemp.end(), less<int>());

    for (int i = 0; i < k; i++)
    {
        if(i != k-1){
            cout <<rtemp[i]<<' ';
        }else
        {
            cout << rtemp[i];
        }
    }
    cout << endl;

    for (int i = 0; i < l; i++)
    {
        if(i != l-1){
            cout <<ctemp[i]<<' ';
        }else
        {
            cout << ctemp[i];
        }
    }

    return 0;
}
