#include <iostream>
#include <string>
using namespace std;

const int maxInf = 10;
int n;
char origin[maxInf][maxInf], ans[maxInf][maxInf], temp[maxInf][maxInf];

void rotate()
{
    char t[maxInf][maxInf];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            t[i][j] = temp[n - j - 1][i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp[i][j] = t[i][j];
        }
    }
}

void reflex()
{
    char t[maxInf][maxInf];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            t[i][j] = temp[i][n - j - 1];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp[i][j] = t[i][j];
        }
    }
}

bool sample(char t1[maxInf][maxInf], char t2[maxInf][maxInf])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (t1[i][j] != t2[i][j])
                return false;
        }
    }
    return true;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string t;
        cin >> t;
        for (int j = 0; j < n; j++)
        {
            origin[i][j] = t[j];
            temp[i][j] = t[j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        string t;
        cin >> t;
        for (int j = 0; j < n; j++)
        {
            ans[i][j] = t[j];
        }
    }
    rotate(); //90
    if (sample(temp, ans))
    {
        cout << 1;
        return 0;
    }
    rotate(); //180
    if (sample(temp, ans))
    {
        cout << 2;
        return 0;
    }
    rotate(); // 270
    if (sample(temp, ans))
    {
        cout << 3;
        return 0;
    }
    rotate(); //360
    reflex();
    if (sample(temp, ans))
    {
        cout << 4;
        return 0;
    }
    rotate();
    if (sample(temp, ans))
    {
        cout << 5;
        return 0;
    }
    rotate();
    if (sample(temp, ans))
    {
        cout << 5;
        return 0;
    }
    rotate();
    if (sample(temp, ans))
    {
        cout << 5;
        return 0;
    }
    if (sample(origin, ans))
    {
        cout << 6;
        return 0;
    }
    cout << 7;
    return 0;
}