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
const int maxn=2300;
vector<int> G[maxn];
int n,m;
int cost[maxn];
int dfn[maxn],low[maxn],belong[maxn],money[maxn],vis[maxn],u[maxn],v[maxn];
bool instack[maxn];
int idx,cnt;
stack<int>s;
void tarjan(int u)
{
	low[u] = dfn[u] = ++idx;
	s.push(u);
	rep(i,0,G[u].size())
	 {
		int v = G[u][i];
		if(!dfn[v]) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
		} else if(!belong[v]) {
			low[u] = min(low[u], dfn[v]);
		}
	}
	int v;
	if(dfn[u] == low[u]) {
		cnt++;
		do {
			v = s.top(); s.pop();
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
		cp(s);
		rep(i,1,n+1)G[i].clear();
		msc(money,0x3f);
		rep(i,1,n+1)
		{
			in(cost[i]);
		}
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
		rep(i,1,n+1)
		{
			money[belong[i]]=min(cost[i],money[belong[i]]);
		}
		rep(i,1,cnt+1)
		{
			vis[i]=1;
		}

		rep(i,0,m)
		{
			if(belong[u[i]]!=belong[v[i]])
				vis[belong[v[i]]] = 0;
		}

		int ans=0;
		int sum=0;
		rep(i,1,cnt+1)
		{
			if(vis[i]){
				ans++;
				sum+=money[i];
			}
		}
		printf("%d %d\n",ans,sum);
	}
	return 0;
}