#include <iostream>
#include <queue>
using namespace std;

const int s = 1000001;

struct Tree
{
    int val;
    int h = 0;
    Tree *l = NULL;
    Tree *r = NULL;
} * tree[s], *t[s];

int ans = 1, temp = 1;
bool mask = true;

void dfs(Tree *left, Tree *right)
{
    if (left == NULL && right == NULL){
        return;
    }
    if ((left == NULL && right != NULL) || (left != NULL && right == NULL) || (left->val != right->val)){
        mask = false;
        return;
    }
    dfs(left->l, right->r);
    dfs(left->r, right->l);
    temp += 2;
}

int main()
{
    int n;
    cin >> n;
    int value[n + 1];
    for (int i = 1; i <= n; i++)
    {
        int v;
        cin >> v;
        Tree *t = new Tree;
        t->val = v;
        tree[i] = t;
    }
    for (int i = 1; i <= n; i++)
    {
        int l, r;
        cin >> l >> r;
        if (l != -1)
            tree[i]->l = tree[l];
        if (r != -1)
            tree[i]->r = tree[r];
    }
    for (int i = 1; i <= n; i++)
    {
        Tree *l = tree[i]->l,*r = tree[i]->r;
        if(l != NULL && r != NULL && l->val == r->val)
        {
            mask = true;
            dfs(l,r);
            if(mask)
            {
                ans = max(ans,temp);
            }
            temp = 1;
        }
    }
    cout << ans;
    return 0;
}