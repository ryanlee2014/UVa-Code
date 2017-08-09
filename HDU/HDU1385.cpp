#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N=1001;
int path[N][N];
int dis[N][N];
int weight[N];
const int inf=0x3f3f3f3f;
void floyd(int t)
{
	for (int i = 1; i <=t ; ++i)
	{
		for (int j = 1; j <=t ; ++j)
		{
			path[i][j]=j;
		}
	}
	for (int k = 1; k <=t ; ++k)
	{
		for (int i = 1; i <=t ; ++i)
		{
			for (int j = 1; j <=t ; ++j)
			{
				if(dis[i][k]<inf&&dis[k][j]<inf)
				{
					int temp=dis[i][k]+dis[k][j]+weight[k];
					if(temp<dis[i][j])
					{
						dis[i][j]=temp;
						path[i][j]=path[i][k];
					}
					else if(temp==dis[i][j]&&path[i][j]>path[i][k])
					{
						path[i][j]=path[i][k];
					}
				}
			}
		}
	}
}

int main(void)
{
	int t;
	while(~scanf("%d",&t)&&t)
	{
		for (int i = 1; i <=t ; ++i)
		{
			for (int j = 1; j <=t ; ++j)
			{
				scanf("%d",&dis[i][j]);
				if(dis[i][j]==-1)
				{
					dis[i][j]=inf;
				}
			}
		}
		for (int i = 1; i <=t ; ++i)
		{
			scanf("%d",&weight[i]);
		}
		floyd(t);
		int start,end;
		while(~scanf("%d%d",&start,&end))
		{
			if(start==-1&&end==-1)break;
			printf("From %d to %d :\n",start,end);
			printf("Path: %d",start);
			int cur=start;
			while(cur!=end)
			{
				printf("-->%d",path[cur][end]);
				cur=path[cur][end];
			}
			puts("");
			printf("Total cost : %d\n",dis[start][end]);
			puts("");
		}
	}
	return 0;
}