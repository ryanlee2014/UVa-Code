#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
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
using namespace std;
struct Edge
{
	int u,v,w;
	bool operator<(const Edge& v)const
	{
		return w<v.w;
	}
};
int cnt;
Edge edge[10100];
int map[110][110];
int fa[110];
int find(int x)
{
	if(x!=fa[x])return fa[x]=find(fa[x]);
	return x;
}
int Kruskal(int village)
{
	rep(i,0,village+1)fa[i]=i;
	int ans=0,count=0;
	rep(i,0,cnt)
	{
		int fx=find(edge[i].u);
		int fy=find(edge[i].v);
		if(fx!=fy)
		{
			ans+=edge[i].w;
			fa[fx]=fy;
			++count;
			if(count==village-1)break;
		}
	}
	return ans;
}
int main(void)
{
	int village;
	while(~in(village))
	{
		rep(i,0,village)
		{
			rep(j,0,village)
			{
				in(map[i][j]);
			}
		}
		cnt=0;
		rep(i,0,village)
		{
			rep(j,i+1,village)
			{
				edge[cnt].u=i,edge[cnt].v=j,edge[cnt++].w=map[i][j];
			}
		}
		sort(edge,edge+cnt);
		out(Kruskal(village));
	}
	return 0;
}