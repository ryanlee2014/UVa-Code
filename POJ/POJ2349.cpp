#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#define in(x) scanf("%d",&x)
#define inf(x) scanf("%lf",&x)
using namespace std;
const int maxn=500050;
int fa[600];
int cnt;
struct Post
{
	double x,y;
};
Post post[600];
struct Node
{
	int start,end;
	double weight;
	Node(){}
	bool operator<(const Node& v)const
	{
		return weight<v.weight;
	}
};
Node node[maxn];
double d[550];
int find(int x)
{
	if(x!=fa[x])fa[x]=find(fa[x]);
	return fa[x];
}

double cal_dis(double x1,double y1,double x2,double y2)
{
	return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}

void init(int n)
{
	for (int i = 0; i <= n; ++i)
	{
		fa[i]=i;
	}
}

inline void merge(int x,int y)
{
	int fx=find(x);
	int fy=find(y);
	if(fx>fy)
		fa[fx]=fy;
	else
		fa[fy]=fx;
}

void Kruskal(int n)
{
	int k=0;
	for (int i = 0; i < cnt; ++i)
	{
		if(find(node[i].start)!=find(node[i].end))
		{
			merge(node[i].start,node[i].end);
			d[k++]=node[i].weight;
			--n;
			if(n==1)return;
		}
	}
}

int main(void)
{
	int T;
	int sat,pot;
	scanf("%d",&T);
	while(T--)
	{
		cnt=0;
		scanf("%d%d",&sat,&pot);
		init(pot);
		for (int i = 1; i <=pot ; ++i)
		{
			scanf("%lf%lf",&post[i].x,&post[i].y);
		}
		for (int i = 1; i <=pot ; ++i)
		{
			for (int j = i+1; j <=pot ; ++j)
			{
				node[cnt].start=i;
				node[cnt].end=j;
				node[cnt++].weight=cal_dis(post[i].x,post[i].y,post[j].x,post[j].y);
				node[cnt].start=j;
				node[cnt].end=i;
				node[cnt++].weight=cal_dis(post[i].x,post[i].y,post[j].x,post[j].y);
			}
		}
		sort(node,node+cnt);
		Kruskal(pot);
		printf("%.2lf\n",d[pot-sat-1]);
	}
	return 0;
}

