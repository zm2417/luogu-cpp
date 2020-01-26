#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n, ans, used[105];
string word[105], sent, sentTemp;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> word[i];
        transform(word[i].begin(), word[i].end(), word[i].begin(), ::tolower);
    }
    getchar();
    getline(cin, sent);
    transform(sent.begin(), sent.end(), sent.begin(), ::tolower);
    for (int i = 0; i < sent.length(); i++)
    {
        if (sent[i] == '.')
        {
            for (int j = 0; j < n; j++)
            {
                if (sentTemp == word[j] && used[j] == 0)
                {
                    ans++;
                }
                used[j] = 0;
            }
            sentTemp = "";
        }
        else if (sent[i] == ',' || sent[i] == ' ')
        {
            for (int j = 0; j < n; j++)
            {
                if (sentTemp == word[j] && used[j] == 0)
                {
                    ans++;
                    used[j] = 1;
                    break;
                }
            }
            sentTemp = "";
        }
        else
        {
            sentTemp += sent[i];
        }
    }
    cout << ans << endl;
    return 0;
}