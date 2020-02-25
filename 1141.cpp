#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Node
{
    int x;
    int y;

    Node(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};

int n, m;
int d[1001][1001], dp[1001][1001];
queue<Node> q,used;
int fx[] = {1, -1, 0, 0}, fy[] = {0, 0, 1, -1};

bool check(int i, int j)
{
    if (i >= 1 && i <= n && j >= 1 && j <= n)
    {
        return true;
    }
    return false;
}

int bfs(int i, int j)
{
    if (dp[i][j] != -1)
    {
        cout << dp[i][j] << endl;
        return dp[i][j];
    }
    Node node = {i, j};
    dp[i][j] = -2;
    q.push(node);
    int c = 0;
    while (!q.empty())
    {
        Node n = q.front();
        used.push(n);
        for (int k = 0; k < 4; k++)
        {
            int tx = n.x + fx[k], ty = n.y + fy[k];
            if (check(tx, ty) && d[tx][ty] != d[n.x][n.y] && dp[tx][ty] == -1)
            {
                Node t = {tx, ty};
                q.push(t);
                dp[tx][ty] = -2;
            }
        }
        c++;
        q.pop();
    }
    cout << c << endl;
    return c;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        string t;
        cin >> t;
        for (int j = 1; j <= n; j++)
        {
            d[i][j] = t[j - 1] - '0';
            dp[i][j] = -1;
        }
    }
    for (int k = 0; k < m; k++)
    {
        int x, y;
        cin >> x >> y;
        int c = bfs(x, y);
        while (!used.empty())
        {
            Node n = used.front();
            dp[n.x][n.y] = c;
            used.pop();
        }
    }
    return 0;
}