#include <iostream>
#include <cstring>
#define in(x) scanf("%d",&x)
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
#define stt struct
#define il inline
#define ctn continue
#define db double
#define pf printf
typedef long long ll;
typedef void vt;
cst it INF = 0x3f3f3f3f;
cst it maxn = 1050;
using namespace std;
int n, m;
ll dp[maxn][11];
ll num[maxn][11];
ll ans = 0;
it best[maxn];
stt Node
{
    it hit, spend;
    Node()
    {}
    Node(it x, it y) : hit(x), spend(y)
    {}
};
Node a[maxn];
it main(void)
{
    wl (~in(n) && ~in(m))
    {
        ans = 0;
        ms(num), ms(dp), ms(best);
        it max_hit = 0, max_def = 0, max_hp = 0;
        it lx, ly;
        rep(i, 0, n)
        {
            in(lx), in(ly);
            ++num[lx][ly];
            if (max_def < ly)max_def = ly;
            if (max_hp < lx)max_hp = lx;
        }
        it l_num = 0;
        rep(i, 0, m)
        {
            in(lx), in(ly);
            if (best[ly] != 0 && best[ly] <= lx)ctn;
            best[ly] = lx;
            a[l_num].spend = lx;
            a[l_num].hit = ly;
            if (a[l_num].hit > max_hit)
            {
                max_hit = a[l_num].hit;
            }
            ++l_num;
        }
        m = l_num;
        if (max_hit <= max_def)
        {
            out(-1);
            ctn;
        }
        rep(k_def, 0, 11)
        {
            if (k_def != 0)
                rep(i, 0, m)--a[i].hit;
            rep(i, 1, max_hp + 1)
            {
                ll t = -1;
                rep(j, 0, m)
                {
                    if (a[j].hit <= 0)ctn;
                    if (i - a[j].hit <= 0)
                    {
                        if (t == -1 || t > a[j].spend)t = a[j].spend;
                        ctn;
                    }
                    if (t == -1 || t > dp[i - a[j].hit][k_def] + a[j].spend)t = dp[i - a[j].hit][k_def] + a[j].spend;
                }
                dp[i][k_def] = t;
            }
        }
        rep(i, 0, max_hp + 1) rep(j, 0, 11) ans += (dp[i][j] * num[i][j]);
        outl(ans);
    }
}