#include <iostream>
#include <cstdio>

long double ans = 0;

int main()
{
    long double s;
    while (scanf("%Lf", &s) != EOF)
    {
        ans += s * 1000000;
    }
    printf("%.5Lf", ans / 1000000);
}