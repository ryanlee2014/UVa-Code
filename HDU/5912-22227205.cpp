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
int main()
{
    it T;
    in(T);
    it kase=0;
    wl(T--)
    {
        it n;
        in(n);
        ll a[20],b[20];
        rep(i,1,n+1)inl(a[i]);
        rep(i,1,n+1)inl(b[i]);
        ll up1=b[n],down1=a[n],up2=up1,down2=down1;
        rvep(i,n-1,1)
        {
            up2=b[i]*down1;
            down2=down1*a[i]+up1;
            ll tmp=__gcd(up2,down2);
            up1=up2/tmp;
            down1=down2/tmp;
        }
        ll tmp=__gcd(down2,up2);
        up1=up2/tmp;
        down1=down2/tmp;
        printf("Case #%d: %lld %lld\n",++kase,up1,down1);
    }
    return 0;
}