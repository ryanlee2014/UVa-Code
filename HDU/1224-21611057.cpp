#include <iostream>
#include <cstring>
#include <queue>
#define in(x) scanf("%d",&x)
#define ins(x) scanf("%s",&x)
#define inf(x) scanf("%lf",&x)
#define inc(x) scanf("%c",&x)
#define c() getchar()
#define out(x) printf("%d\n",x)
#define od(x, y) printf("%d %d\n",x,y)
#define ms(x) memset(x,0,sizeof(x))
#define msc(x, n) memset(x,n,sizeof(x))
#define cp(x) while(!x.empty())x.pop()
#define rep(i, a, b) for(int i=a;i<b;++i)
#define rvep(i, a, b) for(int i=a;i>=b;--i)
using namespace std;

const int INF = 0xfffffff;
const int maxn = 110;

int n, m,w[maxn][maxn],point[maxn],dis[maxn],pre[maxn];
bool vis[maxn];

inline void init()
{
    point[n] = 0;
    rep(i, 0, n + 1)
    {
        w[i][i] = INF;
        rep(j, i + 1, n + 1) w[i][j] = w[j][i] = INF;
    }
}

void SPFA(int s)
{
    ms(vis);
    msc(pre,-1);
    for (int i = 1; i <= n; ++i) dis[i] = -INF;
    dis[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = false;
        rep(v,1,n+1)
            if (w[u][v] != INF)
            {
                int tmp = dis[u] + w[u][v];
                (dis[v]<tmp)&&(dis[v]=tmp,pre[v]=u,(!vis[v])&&(vis[v]=true,q.push(v),1));
            }
    }
}

void print_path(int u)
{
    if (pre[u] == -1)
    {
        printf("1");
        return;
    }
    print_path(pre[u]);
    if (u == n) printf("->%d", 1);
    else printf("->%d", u);
}

int main()
{
    int T, u, v, kase = 0;
    in(T);
    while (T--)
    {
        in(n);
        ++n;
        init();
        rep(i,1,n)in(point[i]);
        in(m);
        rep(i,0,m)in(u),in(v),w[u][v]=point[v];
        SPFA(1);
        kase!=0&&puts("");
        printf("CASE %d#\n", ++kase);
        printf("points : %d\ncircuit : ", dis[n]);
        print_path(n);
        puts("");
    }
    return 0;
}