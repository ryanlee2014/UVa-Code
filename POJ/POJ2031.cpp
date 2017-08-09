#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
struct Node
{
	double x,y,z,r;
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
Node node[201];
Edge edge[10010];
int fa[201];
double graph[110][110];
int cnt=0;
int find(int x)
{
	if(x!=fa[x])fa[x]=find(fa[x]);
	return fa[x];
}
inline void calcu_dis(int i,int j)
{
	double dis=sqrt(pow(node[i].x-node[j].x,2)+pow(node[i].y-node[j].y,2)+pow(node[i].z-node[j].z,2));
	double center_dis=dis-node[i].r-node[j].r;
	if(center_dis>0)
	{
		edge[cnt].start=i;
		edge[cnt].end=j;
		edge[cnt++].weight=center_dis;
	}
	else
		fa[find(j)]=find(i);
}
double Kruskal()
{
	double sum=0;
	for(int i=0;i<cnt;++i)
	{
		int fx=find(edge[i].start);
		int fy=find(edge[i].end);
		if(fx!=fy)
		{
			sum+=edge[i].weight;fa[fy]=fx;
		}
	}
	return sum;
}
int main(void)
{
	int t;
	while(~scanf("%d",&t)&&t)
	{
		for(int i=1;i<=t;++i)scanf("%lf%lf%lf%lf",&node[i].x,&node[i].y,&node[i].z,&node[i].r);
		for(int i=0;i<=t;++i)fa[i]=i;
		cnt=0;
		for(int i=1;i<=t;++i)
			for(int j=i+1;j<=t;++j)
			{
				calcu_dis(i,j);
			}
		sort(edge,edge+cnt);
		printf("%.3f\n",Kruskal());
	}
	return 0;
}