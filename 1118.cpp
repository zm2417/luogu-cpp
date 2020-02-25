#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int N, sum;
    cin >> N >> sum;
    int d[N];
    for (int i = 0; i < N; i++)
    {
        d[i] = i + 1;
    }
    int c[N] = {0};
    c[0] = 1;
    for (int i = 1; i < N; i++)
        for (int j = i; j >= 1; j--)
            c[j] += c[j - 1];
    do
    {
        int cutSum = 0, temp[N] = {0};
        for (int i = 0; i < N; i++)
        {
            cutSum += d[i] * c[i];
            if (cutSum > sum)
            {
                //优化，将后面的从大到小排序，next_permutation跳过这一段
                sort(d + i, d + N, greater<int>());
                break;
            }
        }
        if (cutSum == sum)
        {
            for (int i = 0; i < N; i++)
            {
                cout << d[i] << ' ';
            }
            return 0;
        }
    } while (next_permutation(d, d + N));
}