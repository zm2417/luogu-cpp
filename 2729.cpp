#include <iostream>
using namespace std;

int v1, v2, v3, w1[3], w2[3], w3[3];
int main()
{
    cin >> v1 >> v2 >> v3;
    for (int i = 0; i < 3; i++)
        cin >> w1[i] >> w2[i] >> w3[i];
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            for (int k = 0; k < 100; k++)
            {
                if (!i && !j && !k)
                    continue;
                int u1 = w1[0] * i + w1[1] * j + w1[2] * k, u2 = w2[0] * i + w2[1] * j + w2[2] * k, u3 = w3[0] * i + w3[1] * j + w3[2] * k;
                int t = 0;
                if (v1 != 0 && u1 != 0)
                    t = u1 / v1;
                else if (v2 != 0 && u2 != 0)
                    t = u2 / v2;
                else if (v3 != 0 && u3 != 0)
                    t = u3 / v3;
                if (v1 * t == u1 && v2 * t == u2 && v3 * t == u3)
                {
                    printf("%d %d %d %d\n", i, j, k, t);
                    return 0;
                }
            }
    printf("NONE\n");
    return 0;
}