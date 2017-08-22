#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <climits>
#include <cmath>

using namespace std;

int n, h[110][110];

void floyd()
{
    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                h[i][j] = min(h[i][j], h[i][k] + h[k][j]);
            }
        }
    }
    return ;
}

int main()
{
    int m, a, b;
    bool p;
    while (~scanf("%d %d", &n, &m))
    {
        memset(h, 0x3f3f3f3f, sizeof(h));
        for (int i = 0; i < n; ++i)
        {
            h[i][i] = 0;
        }
        for (int i = 0; i < m; ++i)
        {
            scanf("%d %d", &a, &b);
            h[a][b] = 1;
            h[b][a] = 1;
        }
        floyd();
        p = true;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (h[i][j] > 7)
                {
                    printf("No\n");
                    p = false;
                    break;
                }
            }
            if (!p) break;
        }
        if (p) printf("Yes\n");
    }
    return 0;
}
