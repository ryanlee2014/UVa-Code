#include <iostream>
#include <cstdio>
#include <cstring>
#include <list>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <complex>
#define in(x) scanf("%d",&x)
#define ein(x) ~scanf("%d",&x)
#define inl(x) scanf("%lld",&x)
#define ins(x) scanf("%s",x)
#define inf(x) scanf("%lf",&x)
#define inc(x) scanf("%c",&x)
#define gc() getchar()
#define out(x) printf("%d\n",x)
#define outl(x) printf("%lld\n",x)
#define od(x, y) printf("%d %d\n",x,y)
#define ms(x) memset(x,0,sizeof(x))
#define msc(x, n) memset(x,n,sizeof(x))
#define cp(x) while(!x.empty())x.pop()
#define rep(i, a, b) for(int i=a;i<b;++i)
#define rvep(i, a, b) for(int i=a;i>=b;--i)
#define elif else if
#define el else
#define wl(x) while(x)
#define sn scanf
#define bl bool
#define mp make_pair
#define pii pair<int,int>
#define rtn return
#define ope operator
#define cst const
#define it int
#define cr char
#define ctn continue
#define stt struct
#define il inline
#define tpl template
#define cl class
#define db double
#define sf(x) sizeof(x)
#define vt void
#define pf printf
typedef long long ll;
using namespace std;
cst it maxn=1e3+10;
stt Edge
{
    it from,to,next,dist;
    Edge(){}
    Edge(it u,it v,it n,it d):from(u),to(v),next(n),dist(d){}
};

stt Node
{
    it d,u;
    bl ope<(cst Node& rhs)cst
    {
        rtn d>rhs.d;
    }
};

it n,m;
Edge edges[maxn<<1];
it head[maxn<<1],tot,link[maxn<<1],vis[maxn<<1];

il vt init()
{
    tot=0;
    msc(head,-1);
}

il vt AddEdge(it u,it v,bl dir,it d=1)
{
    edges[tot]=Edge(u,v,head[u],d);
    head[u]=tot++;
    if(dir)
    {
        edges[tot] = Edge(v, u, head[v], d);
        head[v] = tot++;
    }
}

il it dfs(it u)
{
    for (int i = head[u]; ~i ; i=edges[i].next)
    {
        Edge& e=edges[i];
        if(!vis[e.to])
        {
            vis[e.to]=true;
            if(!link[e.to]||dfs(link[e.to]))
            {
                link[e.to]=u;
                rtn true;
            }
        }
    }
    rtn false;
}

il it solve()
{
    ms(link);
    it ans=0;
    rep(i,1,n+1)
    {
        ms(vis);
        if(dfs(i))++ans;
    }
    rtn ans;
}

int main(void)
{
    it k;
    wl(ein(k)&&k)
    {
        init();
        in(n),in(m);
        wl(k--)
        {
            it x,y;
            in(x),in(y);
            AddEdge(x,y+n,true);
        }
        out(solve());
    }
    return 0;
}