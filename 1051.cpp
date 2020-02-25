#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, allSum = 0, maxSum = 0;
    string name;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string name1, gb, west;
        int qimou, banji, paper;
        cin >> name1 >> qimou >> banji >> gb >> west >> paper;
        int temp = 0;
        if (qimou > 80 && paper > 0)
        {
            temp += 8000;
        }
        if (qimou > 85 && banji > 80)
        {
            temp += 4000;
        }
        if (qimou > 90)
        {
            temp += 2000;
        }
        if (qimou > 85 && west.compare("Y") == 0)
        {
            temp += 1000;
        }
        if (banji > 80 && gb.compare("Y") == 0)
        {
            temp += 850;
        }

        allSum += temp;
        if (temp > maxSum)
        {
            maxSum = temp;
            name = name1;
        }
    }
    cout << name.c_str() << endl
         << maxSum << endl
         << allSum << endl;
    return 0;
}