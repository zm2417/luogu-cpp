#include <iostream>
#include <string>
using namespace std;

string num;
string word;
int letter[26] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, -1, 7, 7, 8, 8, 8, 9, 9, 9, -1};

bool check()
{
    if(num.size() != word.size())
        return false;
    for (int i = 0; i < word.size(); i++)
    {
        if(letter[word[i] - 'A'] != (int)(num[i] - '0') )
        {
            return false;
        }
    }
    return true;
}

int main()
{
    cin >> num;
    bool mask = true;
    while (cin >> word)
    {
        if(check()){
            cout << word.c_str() << endl;
            mask = false;
        }
    }
    if(mask)
        cout << "NONE";
    return 0;
}