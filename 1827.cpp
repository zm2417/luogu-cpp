#include <iostream>
#include <string>
using namespace std;

string mid, pre;

void deal(int ml, int mr, int pl, int pr)
{
    if (ml > mr && pl > pr)
    {
        return;
    }
    char root = pre[pl];
    if (ml == mr && pl == pr)
    {
        cout << root;
        return;
    }
    int i;
    for (i = ml; i <= mr; i++)
        if (mid[i] == root)
            break;
    int len = i - ml;
    deal(ml, i - 1, pl + 1, pl + len);
    deal(i + 1, mr, pl + len + 1, pr);
    cout << root;
}

int main()
{
    cin >> mid >> pre;
    deal(0, mid.size() - 1, 0, pre.size() - 1);
}