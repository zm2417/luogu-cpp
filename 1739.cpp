#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string word;
    cin >> word;
    stack<char> s;
    for (int i = 0; i < word.size(); i++)
    {
        if (word[i] == '(')
            s.push('(');
        else if (word[i] == ')')
        {
            if (s.empty())
            {
                cout << "NO";
                return 0;
            }
            else
            {
                s.pop();
            }
        }
        else if (word[i] == '@')
        {
            break;
        }
    }
    if (s.empty())
        cout << "YES";
    else
    {
        cout << "NO";
    }

    return 0;
}