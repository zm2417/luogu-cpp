#include <iostream>
using namespace std;

int parent[10001];

// 路径压缩
int findParent(int x)
{
    if (parent[x] != x)
    {
        parent[x] = findParent(parent[x]);
    }
    return parent[x];
}

bool unionSet(int x, int y)
{
    int xP = findParent(x);
    int yP = findParent(y);
    parent[yP] = xP;
}

// 初始化parent為自己
void initParent()
{
    for (int i = 0; i <= 10000; i++)
    {
        parent[i] = i;
    }
}

int main()
{
    // N个元素和M个操作
    int n, m;
    cin >> n >> m;
    initParent();
    for (int i = 0; i < m; i++)
    {
        int z, x, y;
        cin >> z >> x >> y;
        if (z == 1)
        {
            unionSet(x, y);
        }
        else
        {
            int xP = findParent(x), yP = findParent(y);
            if (xP == yP)
                cout << "Y" << endl;
            else
                cout << 'N' << endl;
        }
    }
}