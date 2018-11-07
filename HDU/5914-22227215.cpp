#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int f[20];

void prepare()
{
    f[0] = 1;
    f[1] = 1;
    for (int i = 2; i < 20; ++i)
    {
        f[i] = f[i - 1] + f[i - 2];
    }
    return;
}

int main()
{
    int T, n, ans;
    prepare();
    scanf("%d", &T);
    for (int kk = 1; kk <= T; ++kk)
    {
        scanf("%d", &n);
        for (int i = 1; i < 20; ++i)
        {
            if (f[i] > n)
            {
                ans = i - 1;
                break;
            }
        }
        printf("Case #%d: %d\n", kk, n-ans);
    }
    return 0;
}