#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void)
{
    string key;
    string data;
    int flag = 0;
    int demo = -1;
    getline(cin, key);
    getline(cin, data);
    transform(key.begin(), key.end(), key.begin(), ::tolower);
    transform(data.begin(), data.end(), data.begin(), ::tolower);
    int i = 0;
    int j = 0;
    while (data[i] != '\0')
    {
        if (flag == 0)
        {
            demo = i;
        }
        while (data[i] == key[j])
        {
            if (key[j + 1] == '\0' && (data[i + 1] == ' ' || data[i + 1] == '\0'))
            {
                flag++;
                break;
            }
            else
            {
                j++;
                i++;
            }
        }
        j = 0;
        while (data[i++] != ' ' && data[i] != '\0')
        {
        }
    }
    if (flag != 0)
        cout << flag << " " << demo;
    else
        cout << -1;
    return 0;
}