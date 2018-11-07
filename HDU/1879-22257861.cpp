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
cst it maxn=1e3;
stt Edge{
    it from,to,dist;
    Edge(){}
    Edge(it u,it v,it d):from(u),to(v),dist(d){}
    bl ope<(cst Edge& rhs)cst
    {
        rtn dist<rhs.dist;
    }
};
Edge edges[maxn*maxn>>1];
it fa[maxn];
it n,cnt;

il it find(it x)
{
    rtn x==fa[x]?fa[x]:find(fa[x]);
}

il vt init()
{
    rep(i,0,n+1)fa[i]=i;
}

il it Kruskal()
{
    sort(edges,edges+cnt);
    it total=0;
    rep(i,0,cnt)
    {
        Edge& e=edges[i];
        it fx=find(e.from);
        it fy=find(e.to);
        if(fx!=fy)
        {
            fa[fx]=fy;
            total+=e.dist;
        }
    }
    rtn total;
}

int main(void)
{
    wl(ein(n)&&n)
    {
        it col=n*(n-1)/2;
        init();
        cnt=0;
        rep(i,0,col)
        {
            it from,to,dist,build;
            in(from),in(to),in(dist),in(build);
            if(build)dist=0;
            edges[cnt++]=Edge(from,to,dist);
        }
        it ans=Kruskal();
        out(ans);
    }
    return 0;
}
