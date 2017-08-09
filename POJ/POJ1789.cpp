#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int maxn=2020;
const int inf=0x3f3f3f;
int fa[maxn];
char alpha[maxn][10];
int n,cnt;
struct Node
{
	int start,end;
	int weight;
	Node():start(0),end(0),weight(inf){}
	bool operator<(const Node& v)const
	{
		return weight<v.weight;
	}
};
Node node[maxn*maxn/2];
int find(int x)
{
	if(x!=fa[x])fa[x]=find(fa[x]);
	return fa[x];
}
int dist(int st,int en)
{
	int dis=0;
	for (int i = 0; i < 7; ++i)alpha[st][i]!=alpha[en][i]&&++dis;
	return dis;
}
int Kruskal()
{
	int sum=0;
	for (int i = 0; i <=n ; ++i)
	{
		fa[i]=i;
	}
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
	return sum;
}
int main(void)
{
	while(~scanf("%d",&n)&&n)
	{
		cnt=0;
		for (int i = 1; i <=n ; ++i)
		{
			scanf("%s",alpha[i]);
		}
		for (int i = 1; i <=n ; ++i)
		{
			for (int j = i+1; j <=n ; ++j)
			{
				node[cnt].start=i;
				node[cnt].end=j;
				node[cnt++].weight=dist(i,j);
			}
		}
		printf("The highest possible quality is 1/%d.\n", Kruskal());
	}
	return 0;
}