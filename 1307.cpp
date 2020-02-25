#include <cstdio>
#include <string>
using namespace std;

int main()
{
    int i;
    scanf("%d", &i);
    if (i == 0)
    {
        printf("%d", 0);
        return 0;
    }
    string res;
    if (i < 0)
    {
        res.push_back('-');
        i *= -1;
    }
    string temp = to_string(i);
    // printf("%d %s",i,temp.c_str());
    int l = 0, r = temp.size() - 1;
    while (r >= 0 && temp[r] == '0')
    {
        r--;
    }
    while (r >= 0)
    {
        res.push_back(temp[r--]);
    }
    printf("%s", res.c_str());
}