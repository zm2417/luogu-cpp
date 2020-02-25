#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int x;
    int y;
    int f;
};
int N, M, fx[] = {-1, 0, 1, 0}, fy[] = {0, 1, 0, -1}, d[51][51], used[51][51][4];
int board[4][2] = {{-1, 0}, {0, -1}, {-1, -1}, {0, 0}};

bool check(int i, int j)
{
    if (i >= 0 && i < N && j >= 0 && j < M)
    {
        return true;
    }
    return false;
}

bool canMove(int i, int j)
{
    for (int k = 0; k < 4; k++)
    {
        if (!check(i + board[k][0], j + board[k][1]) || d[i + board[k][0]][j + board[k][1]] == 1)
            return false;
    }
    return true;
}

int main()
{
    // int N, M;
    cin >> N >> M;
    // int d[N][M], used[N][M][4];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> d[i][j];
            for (int k = 0; k < 4; k++)
            {
                used[i][j][k] = 0;
            }
        }
    }

    int x, y, endx, endy;
    char f;
    cin >> x >> y >> endx >> endy >> f;
    if (d[x][y] == 1)
    {
        cout << -1;
        return 0;
    }
    queue<Node> q;
    int startF = 0;

    if (f == 'S')
        startF = 2;
    if (f == 'N')
        startF = 0;
    if (f == 'W')
        startF = 3;
    if (f == 'E')
        startF = 1;
    Node node = {x, y, startF};
    q.push(node);

    int testX = 7, testy = 5;
    int p = 0, size = 0, count = 1;
    while (!q.empty())
    {
        Node n = q.front();
        if (n.x == endx && n.y == endy)
        {
            cout << p;
            return 0;
        }
        for (int i = 0; i < 3; i++)
        {
            Node temp;
            if (i == 0 && used[n.x][n.y][(n.f + 3) % 4] == 0)
            {
                //turn left
                temp = {n.x, n.y, (n.f + 3) % 4};
                q.push(temp);
                size++;
                used[n.x][n.y][(n.f + 3) % 4] = 1;
            }
            else if (i == 1 && used[n.x][n.y][(n.f + 1) % 4] == 0)
            {
                //turn right
                temp = {n.x, n.y, (n.f + 1) % 4};
                q.push(temp);
                size++;
                used[n.x][n.y][(n.f + 1) % 4] = 1;
            }
            else if (check(n.x + fx[n.f], n.y + fy[n.f]) && canMove(n.x + fx[n.f], n.y + fy[n.f]) && used[n.x + fx[n.f]][n.y + fy[n.f]][n.f] == 0)
            {
                temp = {n.x + fx[n.f], n.y + fy[n.f], n.f};
                q.push(temp);
                size++;
                used[n.x + fx[n.f]][n.y + fy[n.f]][n.f] = 1;
                // if (n.x + fx[n.f] == testX && n.y + fy[n.f] == testy)
                // {
                //     cout << 1 << ' ' << n.x << ' ' << n.y << endl;
                // }
                if (check(n.x + 2 * fx[n.f], n.y + 2 * fy[n.f]) && canMove(n.x + 2 * fx[n.f], n.y + 2 * fy[n.f]) && used[n.x + 2 * fx[n.f]][n.y + 2 * fy[n.f]][n.f] == 0)
                {
                    Node t1 = {n.x + 2 * fx[n.f], n.y + 2 * fy[n.f], n.f};
                    q.push(t1);
                    size++;
                    used[n.x + 2 * fx[n.f]][n.y + 2 * fy[n.f]][n.f] = 1;
                    // if (n.x + 2 * fx[n.f] == testX && n.y + 2 * fy[n.f] == testy)
                    // {
                    //     cout << 2 << ' ' << n.x << ' ' << n.y << endl;
                    // }
                    if (check(n.x + 3 * fx[n.f], n.y + 3 * fy[n.f]) && canMove(n.x + 3 * fx[n.f], n.y + 3 * fy[n.f]) && used[n.x + 3 * fx[n.f]][n.y + 3 * fy[n.f]][n.f] == 0)
                    {
                        Node t2 = {n.x + 3 * fx[n.f], n.y + 3 * fy[n.f], n.f};
                        q.push(t2);
                        size++;
                        used[n.x + 3 * fx[n.f]][n.y + 3 * fy[n.f]][n.f] = 1;
                        // if (n.x + 3 * fx[n.f] == testX && n.y + 3 * fy[n.f] == testy)
                        // {
                        //     cout << 3 << ' ' << n.x << ' ' << n.y << endl;
                        // }
                    }
                }
            }
        }
        count--;
        if (count == 0)
        {
            count = size;
            size = 0;
            p++;
        }
        q.pop();
    }
    cout << -1;
    return 0;
}