#include <iostream>
#include <cmath>
#include <string>
using namespace std;

struct Node
{
    Node *l = NULL;
    Node *r = NULL;
    char c;
};

Node* createTree(string s)
{
    if (s.size() == 1)
    {
        Node *t = new Node;
        t->c = s[0] == '1' ? 'I' : 'B';
        t->l = NULL;
        t->r = NULL;
        return t;
    }
    Node *l = createTree(s.substr(0, s.size() / 2));
    Node *r = createTree(s.substr(s.size() / 2, s.size()));
    Node *ret = new Node;
    ret->l = l;
    ret->r = r;
    if(l->c == 'I' && r->c == 'I')
        ret->c = 'I';
    else if(l->c == 'B' && r->c == 'B')
        ret->c = 'B';
    else ret->c = 'F';
    return ret;
}

void print(Node *n)
{
    if(n == NULL)
        return;
    print(n->l);
    print(n->r);
    cout << n->c;
}

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    Node *head = createTree(s);
    print(head);
    return 0;
}