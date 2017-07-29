#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define in(x) scanf("%d",&x)
#define ins(x) scanf("%s",x)
#define inf(x) scanf("%lf",&x)
#define inc(x) scanf("%c",&x)
#define gc() getchar()
#define out(x) printf("%d\n",x)
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
const int INF = 0x3f3f3f3f;
const int maxn = 50100;
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
int n,p,k,r,a[101],b[101],c[101];
int main()
{
	while(~in(n)&&~in(p)&&~in(k)&&~in(r))
	{
		++a[0];
		++a[k - 1];
		b[0] = 1;
		for (ll i = (ll) n * k; i; i >>= 1)
		{
			if (i & 1)
			{
				ms(c);
				rep(i, 0, k) rep(j, 0, k) c[(i + j) % k] = (c[(i + j) % k] + (ll) a[i] * b[j]) % p;
				rep(i, 0, k)b[i] = c[i];
			}
			ms(c);
			rep(i, 0, k) rep(j, 0, k) c[(i + j) % k] = (c[(i + j) % k] + (ll) a[i] * a[j]) % p;
			rep(i, 0, k)a[i] = c[i];
		}
		out(b[r]);
	}
	return 0;
}