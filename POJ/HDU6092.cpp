#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
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
cst it INF = 0x3f3f3f3f;
using namespace std;
/*
 * 输入挂
 * 场场AK buff
 */
cst it MAXBUF = 10000;
cr buf[MAXBUF], *ps = buf, *pe = buf + 1;
il vt rnext()
{
    if (++ps == pe)
        pe = (ps = buf) + fread(buf, sf(cr), sf(buf) / sf(cr), stdin);
}

tpl<cl T>
il bl fin(T &ans)
{
    ans = 0;
    T f = 1;
    if (ps == pe) rtn false;//EOF
    do
    {
        rnext();
        if ('-' == *ps) f = -1;
    } wl(!isdigit(*ps) && ps != pe);
    if (ps == pe) rtn false;//EOF
    do
    {
        ans = (ans << 1) + (ans << 3) + *ps - 48;
        rnext();
    } wl(isdigit(*ps) && ps != pe);
    ans *= f;
    rtn true;
}

/*
 * 输出挂
 * 超强 超快
 */


cst it MAXOUT = 10000;
cr bufout[MAXOUT], outtmp[50], *pout = bufout, *pend = bufout + MAXOUT;
il vt write()
{
    fwrite(bufout, sf(cr), pout - bufout, stdout);
    pout = bufout;
}
il bl out_char(cr c)
{
    *(pout++) = c;
    if (pout == pend) write();
    write();
    rtn true;
}
il bl out_str(cr *s)
{
    wl(*s)
    {
        *(pout++) = *(s++);
        if (pout == pend) write();
    }
    write();
    rtn true;
}
tpl<cl T>
il bl out_int(T x)
{
    if (!x)
    {
        out_char('0');
        rtn true;
    }
    if (x < 0) x = -x, out_char('-');
    it len = 0;
    wl(x)
    {
        outtmp[len++] = x % 10 + 48;
        x /= 10;
    }
    outtmp[len] = 0;
    for (it i = 0, j = len - 1; i < j; i++, j--) swap(outtmp[i], outtmp[j]);
    out_str(outtmp);
    rtn true;
}

tpl<cl T>
il bl out_intln(T x)
{
    out_int(x), out_char('\n');
    write();
}


ll b[10010], cnt, sum[10010];
int n, m, nxt, mi, a[10010], ans[10010];

it main()
{
    it T;
    fin(T);
    wl(T--)
    {
        fin(n), fin(m);
        rep(i, 0, m + 1)fin(b[i]), sum[i] = 0;
        mi = 0, cnt = 1;
        wl(cnt < b[0])
        {
            cnt *= 2;
            mi++;
        }
        a[0] = mi;
        sum[0] = 1 << mi;
        rep(i, 1, m + 1)
        {
            a[i] = (b[i] - sum[i]) / sum[0];
            rep(j, 1, a[i] + 1) rvep(k, m, i) sum[k] += sum[k - i];
        }
        nxt = 0;
        rep(i, 0, m + 1) rep(j, 1, a[i] + 1)ans[++nxt] = i;
        rep(i, 1, nxt + 1)out_int(ans[i]), out_char(i == nxt ? '\n' : ' ');
    }
    write();
    rtn 0;
}