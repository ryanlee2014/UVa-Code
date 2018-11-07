#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

int main()
{
    int T, n, sum1, sum2, temp;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        sum1 = 0;
        sum2 = 0;
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &temp);
            if ((temp & 1) == 1)
            {
                sum1++;
            }
            else
            {
                sum2++;
            }
        }
        if (sum1 >= sum2)
        {
            printf("2 1\n");
        }
        else
        {
            printf("2 0\n");
        }
    }
    return 0;
} 