#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    Node(int i, int j)
    {
        this->i = i;
        this->j = j;
    };
    int i = 0, j = 0;
};

int n, d[31][31];
queue<Node> q;

bool check(int i, int j)
{
    if (i >= 0 && i < n && j >= 0 && j < n)
    {
        return true;
    }
    return false;
}

void bfs(int x, int y)
{
    // d[i][j] = 2;
    Node node(x, y);
    q.push(node);
    while (!q.empty())
    {
        Node t = q.front();
        int i = t.i, j = t.j;
        d[i][j] = 2;
        if (check(i - 1, j) && d[i - 1][j] == 0)
        {
            Node t1(i - 1, j);
            q.push(t1);
        }
        if (check(i, j - 1) && d[i][j - 1] == 0)
        {
            Node t2(i, j - 1);
            q.push(t2);
        }
        if (check(i + 1, j) && d[i + 1][j] == 0)
        {
            Node t3(i + 1, j);
            q.push(t3);
        }
        if (check(i, j + 1) && d[i][j + 1] == 0)
        {
            Node t4(i, j + 1);
            q.push(t4);
        }
        q.pop();
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> d[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (d[0][i] == 0)
        {
            bfs(0, i);
        }
        if (d[i][0] == 0)
        {
            bfs(i, 0);
        }
        if (d[n - 1][i] == 0)
            bfs(n - 1, i);
        if (d[i][n - 1] == 0)
            bfs(i, n - 1);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (d[i][j] == 0)
                cout << 2 << ' ';
            else if (d[i][j] == 2)
                cout << 0 << ' ';
            else
                cout << 1 << ' ';
        }
        cout << endl;
    }

    return 0;
}