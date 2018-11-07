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
cst it maxn=1e4+5;
it fa[maxn];
it nc[maxn];
il vt init(it n)
{
    rep(i,0,n+1)fa[i]=i;
    rep(i,0,n+1)nc[i]=0;
}

il it find(it x)
{
    rtn x==fa[x]?fa[x]:find(fa[x]);
}

il vt merge(it x,it y)
{
    it fx=find(x);
    it fy=find(y);
    if(fx!=fy)
    {
        fa[max(fx,fy)]=min(fx,fy);
    }
}

il bl judge(it n)
{
    it cnt=0;
    it pre=0;
    rep(i,1,n+1)if(nc[n]&1)rtn false;
    rep(i,1,n+1)
    {
        if(fa[i]!=pre)++cnt,pre=fa[i];
        if(cnt>1)rtn false;
    }
    rtn true;
}

int main(void)
{
    it node,edge;
    wl(ein(node)&&node&&ein(edge))
    {
        init(node);
        rep(i,0,edge)
        {
            it x,y;
            in(x),in(y);
            nc[x]++,nc[y]++;
            merge(x,y);
        }
        int ans=judge(node);
        out(ans);
    }
    return 0;
}