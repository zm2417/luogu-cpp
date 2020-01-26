#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 全排序算法
int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> v;
    for(int i = 0;i<n;i++){
        int j;
        cin >> j;
        v.push_back(j);
    }
    for(int i =0;i<m;i++)
    {
        next_permutation(v.begin(),v.end());
    }
    for(int i : v)
    {
        cout << i << ' ';
    }
}