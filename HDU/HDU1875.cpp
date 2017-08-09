#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <queue>
using namespace std;
struct Node
{
	double x,y;
	Node(){}
};
struct Edge
{
	int start,end;
	double weight;
	bool operator<(const Edge& v)const
	{
		return weight<v.weight;
	}
};
Edge edge[10010];

int island;
int fa[200];
int find(int x)
{
	if(x!=fa[x])fa[x]=find(fa[x]);
	return fa[x];
}
void init()
{
	for(int i=0;i<200;i++)fa[i]=i;
}
double kruskal(int k)
{
	double sum=0;
	for(int i=0;i<k;i++)
	{
		int x=find(edge[i].start);
		int y=find(edge[i].end);
		if(x!=y)fa[x]=y,sum+=edge[i].weight;
	}
	return sum;
}
Node node[200];
int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&island);
		init();
		memset(node,0, sizeof(node));
		memset(edge,0, sizeof(edge));
		for (int i = 1; i <=island ; ++i)
		{
			scanf("%lf%lf",&node[i].x,&node[i].y);
		}
		int cnt=0;
		for (int i = 1; i <=island ; ++i)
		{
			for (int j = i+1; j <=island ; ++j)
			{
				double dis=sqrt(pow(node[i].x-node[j].x,2)+pow(node[i].y-node[j].y,2));
				if(dis>=10&&dis<=1000)
				{
					edge[cnt].start=i;
					edge[cnt].end=j;
					edge[cnt].weight=dis;
					cnt++;
				}
			}
		}
		sort(edge,edge+cnt);
		double sum=kruskal(cnt);
		int count=0;
		for(int i=1;i<=island;i++)if(fa[i]==i)count++;
		if(count!=1)puts("oh!");
		else printf("%.1lf\n",sum*100);
	}
	return 0;
}