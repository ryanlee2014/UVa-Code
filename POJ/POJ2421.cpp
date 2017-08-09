#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=100005;
int cnt;
struct Node
{
	int start,end;
	int weight;
	Node():start(0),end(0),weight(0){}
	bool operator<(const Node& v)const
	{
		return weight<v.weight;
	}
};
int path[1050][1050];
int fa[maxn];
Node node[maxn];
int find(int x)
{
	if(x!=fa[x])fa[x]=find(fa[x]);
	return fa[x];
}
inline void init()
{
	memset(path,0x3f, sizeof(path));
}
int main(void)
{
	int size,temp;
	while(~scanf("%d",&size))
	{
		init();
		cnt=0;
		for(int i=0;i<=size*size;++i)fa[i]=i;
		for(int i=1;i<=size;++i)
			for(int j=1;j<=size;++j)
			{
				scanf("%d",&temp);
				if(i<j){
				node[cnt].start=i;
				node[cnt].end=j;
				node[cnt++].weight=temp;
				}
			}
		int q;
		scanf("%d",&q);
		while(q--)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			fa[find(a)]=find(b);
		}
		int sum=0;
		sort(node,node+cnt);
		for (int i = 0; i < cnt; ++i)
		{
			int x=find(node[i].start);
			int y=find(node[i].end);
			if(x!=y)
			{
				sum+=node[i].weight;
				fa[x]=y;
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}