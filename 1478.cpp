#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

// 如果第一个参数比第二个小就返回true
bool comp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int main()
{
    int n, s, a, b;
    scanf("%d %d", &n, &s);
    scanf("%d %d", &a, &b);
    vector<pair<int, int> > v;
    for (int i = 0; i < n; i++)
    {
        int k, j;
        scanf("%d %d", &k, &j);
        v.push_back({k, j});
    }
    sort(v.begin(), v.end(), comp);
    int res = 0;
    int ab = a+b;
    for (pair<int,int> p : v)
    {
        if(ab >= p.first && s >= p.second){
            res++;
            s -= p.second;
        }
        if(s <=0){
            break;
        }
    }
    printf("%d" ,res);
    return 0;
}