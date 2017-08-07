#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#define in(x) scanf("%d",&x)
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
#define stt struct
#define il inline
#define db double
#define pf printf
#define vt void
typedef long long ll;
using namespace std;
cst it INF = 0x3f3f3f3f;
cst it maxn=1010;
it fa[maxn];
it rec[maxn];
it pt,ed;
stt Edge
{
	it u,v,w;
	Edge(){}
	Edge(it u,it v,it w):u(u),v(v),w(w){}
	il bl ope<(cst Edge& v)cst
	{
		rtn w<v.w;
	}
};
Edge edge[5010];
il it find(it x)
{
	if(x!=fa[x])fa[x]=find(fa[x]);
	rtn fa[x];
}


il vt set_init()
{
	rep(i,0,pt)fa[i]=i;
}

il vt Kruskal()
{
	set_init();
	sort(edge,edge+ed);
	it tot_w=0,cnt=0;
	rep(i,0,ed)
	{
		it fx=find(edge[i].u);
		it fy=find(edge[i].v);
		if(fx!=fy)
		{
			fa[fx]=fy;
			tot_w+=edge[i].w;
			rec[cnt++]=i;
		}
	}
	it atot_w=0;
	bl unique=true;
	it num=0;
	rep(e,0,cnt)
	{
		set_init();
		atot_w=0;
		num=0;
		rep(i,0,ed)
		{
			if(i==rec[e])continue;
			it fx=find(edge[i].u);
			it fy=find(edge[i].v);
			if(fx!=fy)
			{
				fa[fx]=fy;
				atot_w+=edge[i].w;
				++num;
			}
		}
		if(num!=cnt)continue;
		if(atot_w==tot_w)
		{
			unique=false;
			break;
		}
	}
	unique?out(tot_w):puts("Not Unique!");
}

int main(void)
{
	it T,u,v,w;
	in(T);
	wl(T--)
	{
		in(pt),in(ed);
		rep(i,0,ed)
		{
			in(u),in(v),in(w);
			edge[i]=Edge(u,v,w);
		}
		Kruskal();
	}
	return 0;
}