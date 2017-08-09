#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define in(x) scanf("%lld",&x)
#define ins(x) scanf("%s",x)
#define inf(x) scanf("%lf",&x)
#define inc(x) scanf("%c",&x)
#define gc() getchar()
#define out(x) printf("%lld\n",x)
#define od(x,y) printf("%d %d\n",x,y)
#define ms(x) memset(x,0,sizeof(x))
#define msc(x,n) memset(x,n,sizeof(x))
#define cp(x) while(!x.empty())x.pop()
#define rep(i, a, b) for(int i=a;i<b;++i)
#define rvep(i, a, b) for(int i=a;i>=b;--i)
#define elif else if
#define el else
#define wl(x) while(x)
#define pf printf
typedef long long ll;
using namespace std;
const ll INF = 10000000000000000LL;
struct Node
{
	int u,v,w;
	Node(){}
	Node(int u,int v,int w):u(u),v(v),w(w){}
	bool operator<(const Node & v)const
	{
		return u<v.u;
	}
};
const int maxn = 100009;
const int N = 100001;
ll n, m, x;
ll A, B, C, a[maxn], b[maxn], f[maxn], g[maxn], ans;
int main() {
	wl(~in(A)&&~in(B)&&~in(C))
	{
		in(n),in(m);
		rep(i,1,n+1)
		{
			in(x);
			++a[x];
		}
		rep(i,1,m+1)
		{
			in(x);
			++b[x];
		}
		rep(i,1,N+1)
		{
			f[i] = f[i - 1] + a[i - 1] * C;
			a[i] += a[i - 1];
			g[i] = g[i - 1] + i * b[i];
			b[i] += b[i - 1];
			f[i] = min(f[i], INF);
		}
		ans = g[N] * B;
		rep(i,1,N+1)
		{
			if (C == INF && a[i - 1]) break;
			ll mi = b[i] * i - g[i];
			ll mx = g[N] - g[i] - (b[N] - b[i]) * i;
			if (B <= A) ans = min(ans, f[i] + mx * B);
			el ans = min(ans, f[i] + min(mi, mx) * A + (mx - min(mi, mx)) * B);
		}
		out(ans);
	}
}