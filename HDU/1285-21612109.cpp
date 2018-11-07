#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define in(x) scanf("%d",&x)
#define ins(x) scanf("%s",x)
#define inf(x) scanf("%lf",&x)
#define inc(x) scanf("%c",&x)
#define gc() getchar()
#define out(x) printf("%d",x)
#define outln(x) printf("%d\n",x)
#define od(x, y) printf("%d %d\n",x,y)
#define ms(x) memset(x,0,sizeof(x))
#define msc(x, n) memset(x,n,sizeof(x))
#define cp(x) while(!x.empty())x.pop()
#define rep(i, a, b) for(int i=a;i<b;++i)
#define rvep(i, a, b) for(int i=a;i>=b;--i)
const int maxn = 1010;

int degree[maxn], res[maxn];
bool G[maxn][maxn];
vector<int> a[maxn];
int n, m;

void Topo_Sort()
{
    int p;
    rep(i, 1, n + 1)
    {
        p = -1;
        rep(j, 1, n + 1)
        {
            if (!degree[j])
            {
                degree[j]--;
                res[i] = p = j;
                break;
            }
        }
        rep(j, 1, n + 1)
        {
            if (G[p][j])
            {
                G[p][j] = false;
                degree[j]--;
            }
        }
    }
}

int main()
{
    int x, y;
    while (~in(n) && ~in(m))
    {
        ms(G), ms(degree), ms(res);
        rep(i, 1, n + 1)a[i].clear();
        rep(i, 1, m + 1)
        {
            in(x), in(y);
            if (!G[x][y])
            {
                G[x][y] = true;
                degree[y]++;
            }
        }
        Topo_Sort();
        rep(i, 1, n + 1)
        {
            if (i-1)printf(" ");
            out(res[i]);
        }
        puts("");
    }

    return 0;
}