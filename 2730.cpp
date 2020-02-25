#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

struct Node
{
    string a = "";
    string b = "";

    string p = "";
};

queue<Node> q;
int ans;
bool mask[88888888];

Node A(Node i)
{
    Node r;
    r.a = i.b;
    r.b = i.a;
    return r;
}

Node B(Node i)
{
    Node r;
    // r.a[0] = i.a[3];
    // r.a[1] = i.a[0];
    // r.a[2] = i.a[1];
    // r.a[3] = i.a[2];
    r.a = i.a[3] + i.a.substr(0, 3);

    // r.b[0] = i.b[3];
    // r.b[1] = i.b[0];
    // r.b[2] = i.b[1];
    // r.b[3] = i.b[2];
    r.b = i.b[3] + i.b.substr(0, 3);
    // cout << i.a.c_str() << ' ' << i.b.c_str() << endl;
    // cout << r.a.c_str() << ' ' << r.b.c_str() << endl;
    return r;
}

Node C(Node i)
{
    Node r;
    r.a = i.a;
    r.b = i.b;

    r.a[1] = i.b[1];
    r.a[2] = i.a[1];
    r.b[1] = i.b[2];
    r.b[2] = i.a[2];

    return r;
}

int getNum(Node n)
{
    int res = 0;
    for (int i = 0; i < 4; i++)
    {
        res = 10 * res + (n.a[i] - '0');
    }
    for (int i = 0; i < 4; i++)
    {
        res = 10 * res + (n.b[i] - '0');
    }
    return res;
}

bool equal(Node n, Node m)
{
    // cout << n.a.c_str() << ' ' << n.b.c_str() << endl;
    // cout << m.a.c_str() << ' ' << m.b.c_str() << endl;
    return n.a == m.a && n.b == m.b;
}

void print(Node n)
{
    cout << n.p.length() << endl;
    for (int i = 0; i < n.p.length();)
    {
        cout << n.p[i++];
        if (i % 60 == 0)
            cout << endl;
    }
}

int main()
{
    Node t;
    string a;
    for (int i = 0; i < 4; i++)
    {
        string j;
        cin >> j;
        a += j;
    }
    t.a = a;
    string b;
    for (int i = 0; i < 4; i++)
    {
        string j;
        cin >> j;
        b += j;
    }
    reverse(b.begin(), b.end());
    t.b = b;
    // cout << t.a.c_str() << ' ' << t.b.c_str() << endl;
    memset(mask, false, sizeof(mask));

    Node start;
    start.a = "1234";
    start.b = "8765";

    // cout << 'a' + 'b' << endl;

    q.push(start);
    while (true)
    {
        Node n = q.front();
        // cout << n.a.c_str() << ' ' << n.b.c_str() << endl;
        if (equal(n, t))
        {
            print(n);
            return 0;
        }
        q.pop();
        mask[getNum(n)] = true;
        Node nodeA = A(n);
        // cout << nodeA.a.c_str() << ' ' << nodeA.b.c_str() << endl;
        if (!mask[getNum(nodeA)])
        {
            nodeA.p = n.p + 'A';
            q.push(nodeA);
        }
        Node nodeB = B(n);
        // cout << nodeB.a.c_str() << ' ' << nodeB.b.c_str() << endl;
        if (!mask[getNum(nodeB)])
        {
            nodeB.p = n.p + 'B';
            q.push(nodeB);
        }
        Node nodeC = C(n);
        // cout << nodeC.a.c_str() << ' ' << nodeC.b.c_str() << endl;
        if (!mask[getNum(nodeC)])
        {
            nodeC.p = n.p + 'C';
            q.push(nodeC);
        }
    }
    return 0;
}