#include <cstdio>
#define in(x) scanf("%d",&x)
#define rep(i, a, b) for(int i=a;i<b;++i)
#define rvep(i, a, b) for(int i=a;i>=b;--i)
const int maxn = 1000005;
int map[maxn][3], i, num, T, sum, v;
int main(void)
{
    in(T);
    rep(i, 1, T + 1)
    {
        sum = 0;
        int query;
        in(num), in(query);
        rep(j, 1, query + 1)in(map[j][0]), in(map[j][1]), in(map[j][2]);
        rep(j, 1, num + 1)
        {
            v = 1;
            rvep(k, query, 0)
                if (map[k][0] <= j && j <= map[k][1])
                {
                    v = map[k][2];
                    break;
                }
            sum += v;
        }
        printf("Case %d: The total value of the hook is %d.\n", i, sum);
    }
}
