#include <iostream>
#include <cstring>
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
int digit[25];
ll dp[25][2];
ll dfs(it l, bl num, bl jud)
{
    if(!l)rtn 1;
    if(!jud&&~dp[l][num])rtn dp[l][num];
    ll ans = 0;
    it nex = jud ? digit[l] : 9;
    rep(i,0,nex+1)
    {
        if(num&&i==9)ctn;
        ans+=dfs(l-1,i==4,jud&&i==nex);
    }
    if(!jud)dp[l][num]=ans;
    rtn ans;
}
ll f(ll num)
{
    it pos=0;
    wl(num)
    {
        digit[++pos]=num%10;
        num/=10;
    }
    rtn dfs(pos,false,true);
}
int main()
{
    it T;
    ll n;
    msc(dp, -1);
    in(T);
    wl(T--)
    {
        inl(n);
        outl(n - f(n) + 1);
    }
    return 0;
}