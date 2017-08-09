#include <iostream>
#include <cstring>
#include <stack>
#include <vector>
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
const int maxn=20010;
vector<int> G[maxn];
int n,m;
int ini[maxn],oni[maxn];
int dfn[maxn],low[maxn],belong[maxn],u[maxn],v[maxn];
bool instack[maxn];
int idx,cnt;
stack<int>s;
void tarjan(int u)
{
	low[u] = dfn[u] = ++idx;
	instack[u]=true;
	s.push(u);
	rvep(i,G[u].size()-1,0)
	{
		if(!dfn[G[u][i]])
		{
			tarjan(G[u][i]);
			low[u]=min(low[u],low[G[u][i]]);
		}
		else if(instack[G[u][i]])
			low[u]=min(low[u],dfn[G[u][i]]);
	}
	int v;
	if(dfn[u] == low[u]) {
		cnt++;
		do {
			instack[v=s.top()]=false;
			s.pop();
			belong[v] = cnt;
		} while(u != v);
	}
}

int main(void)
{
	while(~in(n)&&~in(m))
	{
		cnt=0;
		ms(dfn);
		ms(low);
		ms(belong);
		ms(instack);
		ms(ini);
		ms(oni);
		cp(s);
		rep(i,1,n+1)G[i].clear();
		rep(i,0,m)
		{
			in(u[i]),in(v[i]);
			G[u[i]].push_back(v[i]);
		}

		cnt=idx=0;
		rep(i,1,n+1)
		{
			if(!dfn[i])
				tarjan(i);
		}
		if(cnt<=1)
		{
			out(0);
			continue;
		}
		rep(i,1,n+1)
		{
			rvep(j,G[i].size()-1,0)
			{
				if(belong[i]!=belong[G[i][j]])
				{
					++ini[belong[G[i][j]]];
					++oni[belong[i]];
				}
			}
		}
		int a,b;
		a=b=0;
		rep(i,1,cnt+1)
		{
			if(!ini[i])++a;
			if(!oni[i])++b;
		}
		if(cnt!=1)
			out(max(a,b));
		else
			out(0);
	}
	return 0;
}