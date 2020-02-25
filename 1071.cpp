#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main()
{
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    int dp[26];
    for(int i = 0;i<26;i++)
    {
        dp[i] = -1;
    }
    for (int i = 0; i < s1.size(); i++)
    {
        if (dp[s1[i] - 'A'] != -1 && dp[s1[i] - 'A'] != s2[i] - 'A')
        {
            cout << "Failed";
            return 0;
        }
        dp[s1[i] - 'A'] = s2[i] - 'A';
    }
    unordered_set<int> set;
    for(int i = 0;i<26;i++)
    {
        if(dp[i] == -1||set.find(dp[i]) != set.end())
        {
            cout << "Failed";
            return 0;
        }
        set.insert(dp[i]);
    }
    string ans;
    for (char c : s3)
    {
        if (dp[c - 'A'] == -1)
        {
            cout << "Failed";
            return 0;
        }
        ans.push_back((char)'A' + dp[c - 'A']);
    }
    cout << ans.c_str();

    return 0;
}