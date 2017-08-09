#include <iostream>
#include <vector>
#include <queue>
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
#define db double
#define pf printf
typedef long long ll;
#define vt void
using namespace std;
cst it INF = 0x3f3f3f3f;
#define F(i, j, n) for(int i=j;i<=n;i++)
#define D(i, j, n) for(int i=j;i>=n;i--)
#define ll long long
using namespace std;
int k, cnt, p[150];
ll n;
bool vst[150];
struct Node
{
	ll t, x, y, z;
	Node(){}
	Node(ll t,ll x,ll y,ll z):t(t),x(x),y(y),z(z){}
	bl ope<(cst Node& b)cst
	{
		rtn t<b.t;
	}
};
priority_queue<Node> q;
it main(vt)
{
	inl(n),in(k);
	rep(i, 2, 129) 
		if (!vst[i])
		{
			p[++cnt] = i;
			ll x = i;
			for (int j = 1; x <= n; j++, x *= i) q.push(Node(x, i, j - 1, cnt - 1));
			rep(j,2,128/i+1)vst[i*j]=true;
		}
	rep(i,1,k+1)
	{
		Node tmp = q.top();
		q.pop();
		if (i == k)
		{
			outl(tmp.t);
			return 0;
		}
		if (tmp.y)rep(j,1,tmp.z+1)q.push(Node(tmp.t / tmp.x * p[j], tmp.x, tmp.y - 1, j));
	}
	return 0;
}