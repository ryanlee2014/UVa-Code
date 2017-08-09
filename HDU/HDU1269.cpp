#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;
#define in(x) scanf("%d",&x)
#define ins(x) scanf("%s",&x)
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
const int maxn=10010;
const int maxm=100010;
struct Node
{
	int v,next;
};
Node node[maxm];
int n,m;
int ccnt,head[maxm];
int dfn[maxn],low[maxn],belong[maxn];
bool instack[maxn];
int idx,cnt;
void add_edge(int u,int v)
{
	node[ccnt].v=v;
	node[ccnt].next=head[u];
	head[u]=ccnt++;
}
stack<int>s;
void tarjan(int u)
{
	int v;
	low[u]=dfn[u]=++idx;
	s.push(u);
	instack[u]=true;
	for(int i=head[u];i!=-1;i=node[i].next)
	{
		v=node[i].v;
		if(!dfn[v])
		{
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(instack[v])
			low[u]=min(low[u],dfn[v]);
	}
	if(low[u]==dfn[u])
	{
		++cnt;
		while(u!=v)
		{
			v=s.top();
			s.pop();
			instack[v]=0;
			belong[v]=cnt;
		}
	}
}

int main(void)
{
	while(~in(n)&&~in(m)&&(n+m))
	{
		int u,v;
		cnt=0;
		ccnt=1;
		msc(head,-1);
		rep(i,0,m)
		{
			in(u),in(v);
			add_edge(u,v);
		}
		ms(dfn);
		ms(instack);
		cnt=idx=0;
		rep(i,1,n+1)
		{
			if(!dfn[i])
				tarjan(i);
		}
		puts(cnt==1?"Yes":"No");
	}
	return 0;
}