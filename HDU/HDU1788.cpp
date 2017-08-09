#include <iostream>
#include <algorithm>
#define in(x) scanf("%d",&x)
#define inl(x) scanf("%lld",&x)
#define ins(x) scanf("%s",&x)
#define inf(x) scanf("%lf",&x)
#define inc(x) scanf("%c",&x)
#define c() getchar()
#define out(x) printf("%d\n",x)
#define oul(x) printf("%lld\n",x)
#define od(x, y) printf("%d %d\n",x,y)
#define ms(x) memset(x,0,sizeof(x))
#define cp(x) while(!x.empty())x.pop()
#define rep(i, a, b) for(int i=a;i<b;++i)
#define rvep(i, a, b) for(int i=a;i>=b;--i)
#define LL long long
using namespace std;
void exgcd(LL a, LL b, LL &d, LL &x, LL &y)
{
	if (!b)
	{
		d = a;
		x = 1;
		y = 0;
	}
	else
	{
		exgcd(b, a % b, d, y, x);
		y -= x * (a / b);
	}
}

const int magic = 55;
LL arr[magic], brr[magic];

LL China(int r)
{
	LL a, b, c, c1, c2, d, e, x, y;
	a = arr[0];
	c1 = brr[0];
	rep(i, 1, r)
	{
		b = arr[i];
		c2 = brr[i];
		exgcd(a, b, d, x, y);
		c = c2 - c1;
		if (c % d)
			return -1;
		e = b / d;
		x = ((x * (c / d)) % e + e) % e;
		c1 = a * x + c1;
		a = a * e;
	}
	if (!c1)
	{
		c1 = 1;
		rep(i, 0, r) c1 = c1 * arr[i] / __gcd(c1, arr[i]);
	}
	return c1;
}
int main(void)
{
	int l, r;
	while (~in(l) && ~in(r) && (l + r))
	{
		rep(i, 0, l)
		{
			inl(arr[i]);
			brr[i] = arr[i] - r;
		}
		oul(China(l));
	}
}
