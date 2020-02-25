#include <iostream>
#include <cmath>
using namespace std;

const int max_n = 160;
const double INF = 1e20;
int n;
double dis[max_n][max_n];
double diameter[max_n];
int field[max_n];

struct Node
{
    int x, y;
    double distance(const Node &b)
    {
        return sqrt((x - b.x) * (x - b.x) + (y - b.y) * (y - b.y));
    }
} node[max_n];

void dfs(int p, int id)
{
    field[p] = id;
    for (int i = 0; i < n; i++)
    {
        if (dis[p][i] < INF && field[i] == 0)
            dfs(i, id);
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> node[i].x >> node[i].y;
    }
    char c[max_n];
    for (int i = 0; i < n; i++)
    {
        cin >> c;
        for (int j = 0; j < n; j++)
        {
            if (c[j] == '1' || i == j)
                dis[i][j] = node[i].distance(node[j]);
            else
                dis[i][j] = INF;
        }
    }
    int id = 0;
    for (int i = 0; i < n; i++)
    {
        if (field[i] == 0)
            dfs(i, ++id);
    }

    // floyd
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (dis[j][i] + dis[i][k] < dis[j][k])
                    dis[j][k] = dis[j][i] + dis[i][k];
            }
        }
    }

    double max_sp[max_n];
    for (int i = 0; i < n; ++i)
    {
        max_sp[i] = 0.0;
        for (int j = 0; j < n; ++j)
            if (dis[i][j] < INF)
                max_sp[i] = max(max_sp[i], dis[i][j]);
        diameter[field[i]] = max(diameter[field[i]], max_sp[i]);
    }

    double min_d = INF, max_d;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (field[i] != field[j])
            {
                max_d = max(max(diameter[field[i]], diameter[field[j]]),
                            max_sp[i] + node[i].distance(node[j]) + max_sp[j]);
                min_d = min(min_d, max_d);
            }

    printf("%.6f\n", min_d);

    return 0;
}