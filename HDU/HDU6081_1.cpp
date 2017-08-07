#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#define in(x) scanf("%d",&x)
#define ein(x) ~scanf("%d",&x)
#define inl(x) scanf("%lld",&x)
#define ins(x) scanf("%s",x)
#define inf(x) scanf("%lf",&x)
#define inc(x) scanf("%c",&x)
#define gc() getchar()
#define out(x) printf("%d\n",x)
#define outl(x) printf("%lld\n",x)
#define od(x,y) printf("%d %d\n",x,y)
#define ms(x) memset(x,0,sizeof(x))
#define msc(x,n) memset(x,n,sizeof(x))
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
#define ctn continue
#define stt struct
#define il inline
#define db double
#define vt void
#define pf printf
#define main it main(vt)
typedef long long ll;
using namespace std;
cst it INF = 0x3f3f3f3f;
using namespace std;
it sum[10000];
main
{
	it m,n,u,v,w;
	wl(ein(n)&&ein(m))
	{
		ms(sum);
		rep(i,1,m+1)
		{
			in(u),in(v),in(w);
			if(u==v)ctn;
			sum[u]+=w;
			sum[v]+=w;
		}
		sort(sum+1,sum+n+1);
		out(sum[1]);
	}
	rtn 0;
}