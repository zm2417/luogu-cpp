#include <iostream>
#include <string>
#include <stack>
using namespace std;

struct Node
{
    char letter;
    // string x;
    // string y;
    int len;
    bool canIn;
};

int main()
{
    int t;
    cin >> t;
    for (int a = 0; a < t; a++)
    {
        int l;
        string o;
        cin >> l >> o;
        // if (l % 2 == 1)
        // {
        //     cout << "ERR" << endl;
        //     continue;
        // }
        // 题目中时间的复杂度
        int num = 0;
        if (o.compare("O(1)") == 0)
        {
            num = 0;
        }
        else
        {
            string t = o.substr(4, o.size() - 1);
            num = stoi(t);
        }
        //计算的最大栈的深度
        int m = 0;
        stack<Node> s;
        int letter[26] = {0};
        bool error = false;
        for (int j = 0; j < l; j++)
        {
            char startChar;
            cin >> startChar;
            if (startChar == 'F')
            {
                char i;
                string x, y;
                cin >> i >> x >> y;
                //新建的变量与已经存在但未被销毁的变量重复
                if (letter[i - 'a'] != 0)
                {
                    // cout << "ERR";
                    error = true;
                    // break;
                }
                letter[i - 'a'] = 1;
                struct Node node = {i, 0, true};
                if (!s.empty())
                {
                    node.len = s.top().len;
                    node.canIn = s.top().canIn;
                }
                if (x != "n" && y == "n" && node.canIn)
                {
                    node.len++;
                }
                else if (x == "n" && y != "n")
                {
                    node.canIn = false;
                }
                else if (x != "n" && y != "n" && stoi(x) > stoi(y))
                {
                    node.canIn = false;
                }
                s.push(node);
            }
            else
            {
                //F 和 E 不匹配
                if (s.empty())
                {
                    // cout << "ERR";
                    error = true;
                    // break;
                }
                else
                {
                    Node node = s.top();
                    if (node.canIn)
                        m = max(m, node.len);
                    s.pop();
                    letter[node.letter - 'a'] = 0;
                }
            }
        }
        if (!error)
        {
            if (!s.empty())
                cout << "ERR";
            else if (num == m)
                cout << "Yes";
            else
                cout << "No";
        }
        else
        {
            cout << "ERR";
        }
        cout << endl;
    }
}