#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <cstdlib>
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
#ifdef ONLINE_JUDGE
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
#else
    cin>>ans;
#endif
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
il bl out_char(cst cr c)
{
#ifdef ONLINE_JUDGE
    *(pout++) = c;
    if (pout == pend) write();
    write();
#else
    cout<<c;
#endif;
    rtn true;
}
il bl out_str(cst cr *s)
{
#ifdef ONLINE_JUDGE
    wl(*s)
    {
        *(pout++) = *(s++);
        if (pout == pend) write();
    }
    write();
#else
    cout<<s;
#endif
    rtn true;
}
tpl<cl T>
il bl out_int(T x)
{
#ifdef ONLINE_JUDGE
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
#else
    cout<<x;
#endif
    rtn true;
}

tpl<cl T>
il bl out_intln(T x)
{
#ifdef ONLINE_JUDGE
    out_int(x),out_char('\n');
    write();
#else
    cout<<x<<endl;
#endif
}
const int MAXN = 5555;
const int MAXM = MAXN >> 1;

int n, m;
int cnt, ans;
int tmp[MAXM];
char s[MAXN];

vt check()
{
    int dis = 0, dis2 = 0, x1 = 0, x2 = 0;
    while (x2 < cnt)
    {
        dis2 += tmp[x2++];
        while (dis2 > m)
        {
            dis2 -= tmp[x1++];
        }
        dis = max(dis, x2 - x1);
    }
    ans = max(ans, dis);
}

void solve()
{
    n=strlen(s+1);
    ans = 0;
    rep(i,1,n+1)
    {
        cnt = 0;
        int x1 = i - 1;
        int x2 = i + 1;
        while (x1 > 0 && x2 <= n)
        {
            tmp[cnt++] = abs(s[x1--] - s[x2++]);
        }
        check();
    }
    rep(i,1,n+1)
    {
        cnt = 0;
        int x1 = i;
        int x2 = i + 1;
        while (x1 > 0 && x2 <= n)
        {
            tmp[cnt++] = abs(s[x1--] - s[x2++]);
        }
        check();
    }
}

int main()
{
    int T;
    in(T);
    while (T--)
    {
        in(m),ins(s+1);
        solve();
        out(ans);
    }
    return  0;
}