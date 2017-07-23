#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
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
int fa[4001000];
const int MOD=998244353;
int find(int x)
{
	if(x!=fa[x])return fa[x]=find(fa[x]);
	return x;
}

inline void union_set(int x,int y)
{
	int fx=find(x);
	int fy=find(y);
	if(fx!=fy)
	{
		fa[fx]=fy;
	}
}
string ans;
int main(void)
{
	int point,t;
	while(~in(point)&&~in(t))
	{
		rep(i,0,point+1)fa[i]=i;
		ans.clear();
		int op,u,v;
		rep(i,0,t)
		{
			in(op),in(u),in(v);
			if(op)
			{
				int fx=find(u);
				int fy=find(v);
				if(fx!=fy)
				{
					ans+="0";
				}
				else
				{
					ans+="1";
				}
			}
			else
			{
				union_set(u,v);
			}
		}
		int len=ans.length();
		int res=0;
		int start=0;
		while(ans[start]=='0')++start;
		rep(i,start,len)
		{
			res*=2;
			res+=ans[i]-'0';
			res%=MOD;
		}
		out(res%MOD);
	}
	return 0;
}