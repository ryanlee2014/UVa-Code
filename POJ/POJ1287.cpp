#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
using namespace std;
int fa[5100];
struct Node{
	int start,end,weight;
	bool operator<(const Node& v)const
	{
		return weight<v.weight;
	}
};
Node node[5100];
int point,way;
int find(int x)
{
	if(x!=fa[x])fa[x]=find(fa[x]);
	return fa[x];
}

int kruskal()
{
	int sum=0;
	int cnt=0;
	for (int i = 0; i <way ; ++i)
	{
		int x=find(node[i].start);
		int y=find(node[i].end);
		if(x!=y)
		{
			cnt++;
			sum+=node[i].weight;
			if(cnt==point-1)break;
			fa[x]=y;
		}
	}
	return sum;
}

int main(void)
{
	while(scanf("%d",&point)==1&&point)
	{
		scanf("%d",&way);
		if(point&&!way)
		{
			puts("0");
			continue;
		}
		for (int i = 0; i < way; ++i)
		{
			fa[i]=i;
		}
		for (int i = 0; i <way ; ++i)
		{
			scanf("%d%d%d",&node[i].start,&node[i].end,&node[i].weight);
		}
		sort(node,node+way);
		int sum=kruskal();
		printf("%d\n",sum);
	}
	return 0;
}