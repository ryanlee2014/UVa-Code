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
#define einl(x) ~scanf("%lld",&x)
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
	if (ps == pe) rtn false;
	do
	{
		rnext();
		if ('-' == *ps) f = -1;
	} wl(!isdigit(*ps) && ps != pe);
	if (ps == pe) rtn false;
	do
	{
		ans = (ans << 1) + (ans << 3) + *ps - 48;
		rnext();
	} wl(isdigit(*ps) && ps != pe);
	ans *= f;
	rtn true;
}


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
	out_int(x),out_char('\n');
	write();
}



stt Number
{
	ll num;
	Number(){}
	Number(ll s):num(s){}
	ope ll()
	{
		rtn num;
	}
	ope it()
	{
		rtn (it)num;
	}
	bl ope<(cst Number& v)cst
	{
		rtn num>v.num;
	}
};

priority_queue<Number>q;

int main(void)
{
	ll T;
	ll ans;
	fin(T);
	wl(T--)
	{
		ans=0;
		cp(q);
		ll num;
		fin(num);
		ll tmp;
		rep(i,0,num)q.push(Number((fin(tmp),tmp)));
		wl(q.size()>=2)
		{
			tmp=q.top().num;
			q.pop();
			tmp+=q.top().num;
			q.pop();
			ans+=tmp;
			q.push(Number(tmp));
		}
		out_intln(ans);
	}
	rtn 0;
}