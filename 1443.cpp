#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;

struct Node
{
    int x;
    int y;
};

int d[401][401], MOVE[8][2] = {{-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, -1}, {2, 1}, {-1, -2}, {1, -2}},
                 N, M;
queue<Node> q;

bool check(int i, int j)
{
    if (i > 0 && i <= N && j > 0 && j <= M)
    {
        return true;
    }
    return false;
}

int main()
{
    cin >> N >> M;
    int startX, startY;
    cin >> startX >> startY;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            d[i][j] = -1;
        }
    }
    Node first = {startX, startY};
    q.push(first);
    d[startX][startY] = 0;
    int p = 0, size = 1, cuntSize = 0;
    while (!q.empty())
    {
        Node n = q.front();
        
        for (int i = 0; i < 8; i++)
        {
            if (check(n.x + MOVE[i][0], n.y + MOVE[i][1]) && d[n.x + MOVE[i][0]][n.y + MOVE[i][1]] == -1)
            {
                Node temp = {n.x + MOVE[i][0], n.y + MOVE[i][1]};
                d[n.x + MOVE[i][0]][n.y + MOVE[i][1]] = p+1;
                q.push(temp);
                cuntSize++;
            }
        }
        q.pop();
        size--;
        if (size == 0)
        {
            size = cuntSize;
            cuntSize = 0;
            p++;
        }
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            printf("%-5d", d[i][j]);
        }
        cout << endl;
    }

    return 0;
}