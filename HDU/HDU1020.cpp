#include <iostream>
#include <cstring>
#define in(x) scanf("%d",&x)
#define inl(x) scanf("%lld",&x)
#define ins(x) scanf("%s",x)
#define inf(x) scanf("%lf",&x)
#define inc(x) scanf("%c",&x)
#define gc() getchar()
#define nl puts("");
#define out(x) printf("%d",x)
#define outc(x) printf("%c",x)
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
#define stt struct
#define il inline
#define db double
#define pf printf
typedef long long ll;
typedef void vt;
using namespace std;
cst it INF = 0x3f3f3f3f;
char str[10010];
int main(void)
{
    it T;
    in(T);
    wl(T--)
    {
        ins(str);
        it len = strlen(str);
        char c = str[0];
        int cnt = 1;
        rep(i, 1, len)
        {
            if (str[i] != c)
            {
                cnt > 1 && out(cnt);
                outc(c);
                cnt = 1;
                c = str[i];
            }
            else
            {
                cnt++;
            }
        }
        cnt > 1 && out(cnt);
        outc(c);
        nl
    }
    return 0;
}