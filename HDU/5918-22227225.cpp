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
cst it maxn=1e5+6;
it a[maxn],b[maxn];
int main()
{
    it T;
    in(T);
    it kase=0;
    wl(T--)
    {
        it n,m,p;
        in(n),in(m),in(p);
        rep(i,0,n)in(a[i]);
        rep(i,0,m)in(b[i]);
        it mx=n-(m-1)*p;
        it cnt=0;
        rep(i,1,mx+1)
        {
            bl is=true;
            rep(j,0,m)
            {
                if(a[i+j*p-1]!=b[j])
                {
                    is=false;
                    break;
                }
            }
            is&&++cnt;
        }
        printf("Case #%d: %d\n",++kase,cnt);
    }
    return 0;
}