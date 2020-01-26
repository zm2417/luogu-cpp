#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

struct Node
{
    int id;
    int arr;
    int process;
    int pro;
    friend bool operator<(struct Node a, struct Node b)
    {
        if (a.pro == b.pro)
            return a.arr > b.arr;
        return a.pro < b.pro;
    }
};

priority_queue<Node> q;
Node cur;
bool first = true;
int t = 0;

int main()
{
    int id, arr, process, pro;
    while (scanf("%d%d%d%d", &id, &arr, &process, &pro) != EOF)
    {
        cur.id = id;
        cur.arr = arr;
        cur.pro = pro;
        cur.process = process;
        while (!q.empty() && q.top().process + t <= arr)
        {
            Node n = q.top();
            q.pop();
            cout << n.id << ' ' << t + n.process << endl;
            t += n.process;
        }
        if (!q.empty())
        {
            Node n = q.top();
            q.pop();
            n.process = n.process - arr + t;
            q.push(n);
        }
        q.push(cur);
        t = cur.arr;
    }
    while (!q.empty())
    {
        Node n = q.top();
        q.pop();
        t += n.process;
        cout << n.id << ' ' << t << endl;
    }
    return 0;
}