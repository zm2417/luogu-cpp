#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

void changeM(int &m)
{
    if (m == 1)
        m = 2;
}

int main()
{
    string equation;
    cin >> equation;
    int cofficient = 0, number = 0, i = 0;
    string t = "";
    int flag = 1;
    int mask = 0;  //0：数字；1：字母
    string x = ""; //未知数
    int m = 0;
    while (i < equation.size())
    {
        if (equation[i] >= '0' && equation[i] <= '9')
        {
            mask = 0;
            t.push_back(equation[i]);
            changeM(m);
        }
        else if (equation[i] == '+')
        {
            if (mask == 0)
            {
                number += flag * atoi(t.c_str());
            }
            else
            {
                cofficient += flag * atoi(t.c_str());
            }
            t = "";
            changeM(m);
        }
        else if (equation[i] == '-')
        {
            if (!t.empty())
            {
                if (mask == 0)
                {
                    number += flag * atoi(t.c_str());
                }
                else
                {
                    cofficient += flag * atoi(t.c_str());
                }
                t = "";
            }
            t.push_back('-');
            changeM(m);
        }
        else if (equation[i] == '=')
        {
            if (!t.empty())
            {
                if (mask == 0)
                {
                    number += flag * atoi(t.c_str());
                }
                else
                {
                    cofficient += flag * atoi(t.c_str());
                }
                t = "";
            }
            flag = -1;
            changeM(m);
        }
        else
        {
            mask = 1;
            if (m == 0)
            {
                m = 1;
                x.push_back(equation[i]);
            }
            if(t.empty() || t.compare("-") == 0)
            {
                t.push_back('1');
            }
        }
        i++;
    }
    if (!t.empty())
    {
        if (mask == 0)
        {
            number += flag * atoi(t.c_str());
        }
        else
        {
            cofficient += flag * atoi(t.c_str());
        }
    }
    printf("%s=%0.3lf", x.c_str(), -1 * (number * 1.0 / cofficient));
    return 0;
};