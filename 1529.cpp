#include <iostream>
using namespace std;

const int max_p = 10005;
const int INF = INT16_MAX;
int p;
int dis[60][60];

int getNum(char c)
{
    if (c >= 'a' && c <= 'z')
        return c - 'a';
    else
        return c - 'A' + 26;
}

char getChar(int i)
{
    if (i < 26)
        return (char)(i + 'a');
    else
        return (char)(i - 26 + 'A');
}

int main()
{
    cin >> p;
    char s, e;
    int d;

    for (int i = 0; i < 52; i++)
        for (int j = 0; j < 52; j++)
            dis[i][j] = INF;

    for (int i = 0; i < p; i++)
    {
        cin >> s >> e >> d;
        int x = getNum(s), y = getNum(e);
        // if (e == 'Z')
        // cout << e << endl;
        dis[x][y] = min(dis[x][y], d);
        dis[y][x] = min(dis[x][y], d);
    }

    for (int i = 0; i < 52; i++)
        for (int j = 0; j < 52; j++)
            for (int l = 0; l < 52; l++)
                if (dis[j][i] + dis[i][l] < dis[j][l])
                    dis[j][l] = dis[j][i] + dis[i][l];

    int min_p = 26;
    for (int i = 27; i < 51; i++)
    {
        if (dis[min_p][51] > dis[i][51])
            min_p = i;
    }
    cout << getChar(min_p) << ' ' << dis[min_p][51];
    return 0;
}