#include <cstdio>
#include <regex>
#include <iostream>
#define in(x) scanf("%d",&x)
#define ins(x) scanf("%s",&x)
#define inf(x) scanf("%lf",&x)
#define inc(x) scanf("%c",&x)
#define c() getchar()
#define out(x) printf("%d\n",x)
#define od(x,y) printf("%d %d\n",x,y)
#define ms(x) memset(x,0,sizeof(x))
#define cp(x) while(!x.empty())x.pop()
#define rep(i, a, b) for(int i=a;i<b;++i)
#define rvep(i, a, b) for(int i=a;i>=b;--i)
using namespace std;

int extended_gcd(int a, int b, int &x, int &y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	int r = extended_gcd(b, a % b, x, y);
	int t = x;
	x = y;
	y = t - a / b * y;
	return r;
}

int modularLinearEquation(int a, int b, int n)
{
	int x, y, x0;
	int d = extended_gcd(a, n, x, y);
	if (b%d)
		return false;
	x0 = x*(b / d) % n;
	return  (x0 + (n / d)) % n;
}
int main(void)
{
	int t;
	in(t);
	while(t--)
	{
		int p, e, i, d, x, kase = 0;
		int M = (23 * 28 * 33) / __gcd(23, __gcd(28, 33));
		int a = (M / 23 * modularLinearEquation(M / 23, 1, 23));
		int b = (M / 28 * modularLinearEquation(M / 28, 1, 28));
		int c = (M / 33 * modularLinearEquation(M / 33, 1, 33));
		while (~scanf("%d%d%d%d", &p, &e, &i, &d) && ~p && ~e && ~i && ~d)
		{
			!(x = (a * p + b * e + c * i - d + 21252) % 21252) && (x = 21252);
			cout << "Case " << ++kase << ": the next triple peak occurs in " << x << " days." << endl;
		}
	}
}