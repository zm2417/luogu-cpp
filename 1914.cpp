#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    char letter[26];
    for (int i = 0; i < 26; i++)
    {
        char c = (char)((i+n) % 26 + 'a');
        letter[i] = c;
    }
    for (int i = 0; i < s.size(); i++)
    {
        s[i] = letter[s[i] - 'a'];
    }
    cout << s.c_str();
    return 0;
    
}