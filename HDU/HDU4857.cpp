#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#define in(x) scanf("%d",&x)
#define ins(x) scanf("%s",x)
#define inf(x) scanf("%lf",&x)
#define inc(x) scanf("%c",&x)
#define gc() getchar()
#define out(x) printf("%d",x)
#define outln(x) printf("%d\n",x)
#define od(x,y) printf("%d %d\n",x,y)
#define ms(x) memset(x,0,sizeof(x))
#define msc(x,n) memset(x,n,sizeof(x))
#define cp(x) while(!x.empty())x.pop()
#define rep(i, a, b) for(int i=a;i<b;++i)
#define rvep(i, a, b) for(int i=a;i>=b;--i)
const int maxn=30010;
using namespace std;

int n,m,ans;
bool vis[maxn];
int ina[maxn];
vector<int>G[maxn];

int main()
{
	int T;
	in(T);
	while(T--)
	{
		in(n),in(m);
		ms(ina);
		ms(vis);
		ans=0;
		rep(i,1,n+1)G[i].clear();
		int u,v;
		rep(i,1,m+1)
		{
			in(u),in(v);
			ina[u]++;
			G[v].push_back(u);
		}
		priority_queue<int> q;
		rep(i,1,n+1)
		{
			if(!ina[i]) q.push(i);
		}
		vector<int>res;
		while(!q.empty())
		{
			++ans;
			u=q.top();
			res.push_back(u);
			q.pop();
			vis[u]=1;
			rep(i,0,G[u].size())
			{
				v=G[u][i];
				ina[v]--;
				if(!ina[v])
					q.push(v);
			}
		}
		rvep(i,res.size()-1,0)
		{
			if(i!=res.size()-1) printf(" ");
			printf("%d",res[i]);
		}
		puts("");
	}
	return 0;
}