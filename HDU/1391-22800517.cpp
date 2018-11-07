#include <bits/stdc++.h>
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

int main(void)
{
    it T;
    in(T);
    while(T--)
    {
        int x,y;
        in(x),in(y);
        if(x!=y&&x!=y+2)
        {
            puts("No Number");
            continue;
        }
        else
        {
            if(x==y)
            {
                if(x&1)
                {
                    out(x+y-1);
                }
                else
                {
                    out(x+y);
                }
            }
            else
            {
                if(x&1)
                {
                    out(x+y-1);
                }
                else
                {
                    out(x+y);
                }
            }
        }
    }
    return 0;
}