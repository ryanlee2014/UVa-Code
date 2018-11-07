#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
#define in(x) scanf("%d",&x)
#define ins(x) scanf("%s",&x)
#define inf(x) scanf("%lf",&x)
#define inc(x) scanf("%c",&x)
#define gc() getchar()
#define out(x) printf("%d\n",x)
#define kout(c,x) printf("Case %d: %d\n",c,x)
#define od(x, y) printf("%d %d\n",x,y)
#define ms(x) memset(x,0,sizeof(x))
#define msc(x, n) memset(x,n,sizeof(x))
#define cp(x) while(!x.empty())x.pop()
#define rep(i, a, b) for(int i=a;i<b;++i)
#define rvep(i, a, b) for(int i=a;i>=b;--i)
const int N = 20;
const int INF = 0x3f3f3f3f;
int n, m, G[N][N], path[N], flow[N], start, target;
queue<int> q;

int bfs()
{
    int  t;
    cp(q);
    msc(path,-1);
    path[start] = 0, flow[start] = INF;
    q.push(start);
    while (!q.empty())
    {
        t = q.front();
        q.pop();
        if (t == target) break;
        rep(i,1,m+1)
        {
            if (i != start && path[i] == -1 && G[t][i])
            {
                flow[i] = flow[t] < G[t][i] ? flow[t] : G[t][i];
                q.push(i);
                path[i] = t;
            }
        }
    }
    if (path[target] == -1) return -1;
    return flow[m];
}
int Edmonds_Karp()
{
    int max_flow = 0, step, now, pre;
    while (~(step = bfs()))
    {
        max_flow += step;
        now = target;
        while (now != start)
        {
            pre = path[now];
            G[pre][now] -= step;
            G[now][pre] += step;
            now = pre;
        }
    }
    return max_flow;
}
int main(void)
{
    int u, v, w;
    int kase;
    start = 1;
    in(kase);
    rep(i, 1, kase + 1)
    {
        in(m), in(n);
        ms(G);
        rep(j,0,n)
        {
            in(u),in(v),in(w);
            G[u][v] += w;
        }
        target = m;
        kout(i,Edmonds_Karp());
    }
    return 0;
}