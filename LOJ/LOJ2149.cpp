#include <cstdio>
#include <algorithm>
using namespace std;
int fa[500];
struct Node { int start,end,weight;bool operator<(const Node& v)const { return weight<v.weight; }};
Node node[10001];
int find(int x) { return fa[x]==x?x:fa[x]=find(fa[x]); }
int main(void)
{
	int point,road;
	while(~scanf("%d%d",&point,&road))
	{
		for (int i = 0; i < road; ++i)scanf("%d%d%d",&node[i].start,&node[i].end,&node[i].weight);
		int cnt=0,big=-1;
		for (int i = 0; i < 500; ++i)fa[i]=i;
		sort(node,node+road);
		for(int i=0;i<road;++i)
		{
			int fx=find(node[i].start),fy=find(node[i].end);
			if(fx!=fy)
			{
				++cnt;
				fa[fx]=fy;
				big=max(big,node[i].weight);
				if(cnt==point-1)break;
			}
		}
		printf("%d %d\n",cnt,big);
	}
	return 0;
}