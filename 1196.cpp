#include <iostream>
using namespace std;

const int maxInf = 30020;

// 所谓带权并查集
// 本题所求的不止是两个编号之间是否有关系，还要求两个编号之间有什么关系，这就要求我们维护多个数组，fa[]数组维护两个编号之间的连通性，dis[]维护编号为i的战舰到fa[i]之间的距离，num[]维护编号为i的战舰所在的那一列有多少战舰。
// parent 父节点 d集合的点数量 s节点到根的距离
int parent[maxInf], d[maxInf], s[maxInf];
void init()
{
    for (int i = 0; i < maxInf; i++)
        parent[i] = i, d[i] = 1, s[i] = 0;
}
int findP(int x)
{
    if (x == parent[x])
        return x;
    int f = parent[x];
    parent[x] = findP(parent[x]);
    s[x] += s[f];
    d[x] = d[parent[x]];
    return parent[x];
}
void join(int i, int j)
{
    int xp = findP(i);
    int yp = findP(j);
    parent[xp] = yp;
    s[xp] += d[yp];
    d[xp] += d[yp];
    d[yp] = d[xp];
}

int main()
{
    int t;
    cin >> t;
    init();
    while (t > 0)
    {
        t--;
        char order;
        int i, j;
        cin >> order >> i >> j;
        if (order == 'M')
        {
            join(i, j);
        }
        else
        {
            if (findP(i) != findP(j))
                cout << "-1" << endl;
            else
            {
                cout << abs(s[i] - s[j]) - 1 << endl;
            }
        }
    }
    return 0;
}