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
inline int read()
{
	int t=1,sum=0;char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') t=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
		sum=sum*10+ch-'0',ch=getchar();
	return t*sum;
}
const int maxn=5e4+10;
int c1[maxn],c2[maxn],a[maxn],n,m,cnt;
ll ans[maxn],Ans;
struct Node
{
	int l,r,id;
	Node(){}
	Node(int l,int r,int id):l(l),r(r),id(id){}
	bool operator < (const Node &v) const
	{
		if(l/233!=v.l/233) return l<v.l;
		if(l/233&1) return r>v.r;
		else return r<v.r;
	}
};
Node Q[maxn<<2];
int main(void)
{
	int i,x1,x2,y1,y2;
	in(n);
	rep(i,1,n+1)
		in(a[i]);
	in(m);
	rep(i,1,m+1)
	{
		in(x1),in(y1),in(x2),in(y2);
		Q[++cnt]=(Node){y1,y2,i};
		if(x1>1) Q[++cnt]=Node(x1-1,y2,-i);
		if(x2>1) Q[++cnt]=Node(x2-1,y1,-i);
		if(x1>1&&x2>1) Q[++cnt]=Node(x1-1,x2-1,i);
	}
	rep(i,1,cnt+1)
		if(Q[i].l>Q[i].r)swap(Q[i].l,Q[i].r);
	sort(Q+1,Q+cnt+1);
	int l=1,r=0; c1[a[1]]++;
	rep(i,1,cnt+1)
	{
		while(r<Q[i].r)
			r++,Ans+=c1[a[r]],c2[a[r]]++;
		while(l<Q[i].l)
			l++,Ans+=c2[a[l]],c1[a[l]]++;
		while(r>Q[i].r)
			Ans-=c1[a[r]],c2[a[r]]--,r--;
		while(l>Q[i].l)
			Ans-=c2[a[l]],c1[a[l]]--,l--;
		if(Q[i].id<0) ans[-Q[i].id]-=Ans;
		el ans[Q[i].id]+=Ans;
	}
	rep(i,1,m+1)
		printf("%lld\n",ans[i]);
	return 0;
}