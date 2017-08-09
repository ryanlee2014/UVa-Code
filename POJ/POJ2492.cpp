#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=2010;
int n,m;
int comset[maxn];
int sex[maxn];
bool flag;
void init()
{
	flag=false;
	for(int i=0; i<=n; i++)
		comset[i]=i,sex[i]=0;
}
int find(int x)
{
	if(x!=comset[x])
	{
		int fx=comset[x];
		comset[x]= find(comset[x]);
		sex[x]=(sex[fx]+sex[x])&1;
	}
	return comset[x];
}
void Union(int x,int y)
{
	int fx= find(x);
	int fy= find(y);
	if(fx==fy&&sex[x]==sex[y])
	{
		flag=true;
		return ;
	}
	comset[fx]=fy;
	sex[fx]=(sex[x]+sex[y]+1)&1;
}
int main(void)
{
	int T;
	int kase=0;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		init();
		int x,y;
		while(m--)
		{
			scanf("%d%d",&x,&y);
			if(flag) continue;
			Union(x,y);
		}
		printf("Scenario #%d:\n",++kase);
		if(flag)
			printf("Suspicious bugs found!");
		else
			printf("No suspicious bugs found!");
		puts("\n");
	}
	return 0;
}