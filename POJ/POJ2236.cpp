#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
using namespace std;
const int maxn=1050;
struct Node{
	int x,y;
	Node(){}
};

Node node[1050];
int n,d;

int combine_set[1050];

bool repair[maxn];

bool graph[1050][1050];

int find(int x)
{
	if(combine_set[x]==x)
		return x;
	else
		return combine_set[x]=find(combine_set[x]);
}

inline void connect(int x,int y)
{
	int fx=find(x);
	int fy=find(y);
	if(fx!=fy)
		combine_set[fx]=fy;
}

void build_tree()
{
	double distant;
	for (int i = 1; i <=n ; ++i)
	{
		for (int j = 1; j <=n ; ++j)
		{
			distant=sqrt((node[i].x-node[j].x)*(node[i].x-node[j].x)*1.0+(node[i].y-node[j].y)*(node[i].y-node[j].y)*1.0);
			if(distant<d+1e-8)
				graph[i][j]=graph[j][i]=true;
		}
	}
}

inline void init()
{
	memset(repair,false, sizeof(repair));
	memset(graph,false, sizeof(graph));
}

int main(void)
{
	while (~scanf("%d%d",&n,&d))
	{
		for (int i = 1; i <=n ; ++i)
		{
			scanf("%d%d",&node[i].x,&node[i].y);
		}
		for (int i = 1; i <=n ; ++i)
		{
			combine_set[i]=i;
		}
		init();
		build_tree();
		char arr[20];
		while(~scanf("%s",arr))
		{
			if(arr[0]=='O')
			{
				int a;
				scanf("%d",&a);
				repair[a]=true;
				for (int i = 1; i <=n ; ++i)
				{
					if(graph[i][a]&&repair[i])
						connect(a,i);
				}
			}
			else
			{
				int a,b;
				scanf("%d%d",&a,&b);
				int fa,fb;
				fa=find(a);
				fb=find(b);
				puts(fa==fb?"SUCCESS":"FAIL");
			}
		}
	}
	return 0;
}