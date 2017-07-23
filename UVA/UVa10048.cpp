#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int graph[120][120];
int road,point;
const int INF=0x3f3f3f3f;
int kase=1;
int command;
int temp_s,temp_e;
int main(void)
{
	ios::sync_with_stdio(false);
	while(cin>>point>>road>>command,point&&road&&command)
	{
		memset(graph,INF, sizeof(graph));
		for (int i = 1; i <=point ; i++)
		{
			graph[i][i]=0;
		}
		for (int i = 0; i < road; i++)
		{
			cin>>temp_s>>temp_e;
			cin>>graph[temp_s][temp_e];
			graph[temp_e][temp_s]=graph[temp_s][temp_e];
		}
		for (int k = 1; k <=point; k++)
		{
			for (int i = 1; i <=point ; i++)
			{
				for (int j = 1; j <=point ; j++)
				{
					graph[i][j]=min(graph[i][j],max(graph[i][k],graph[k][j]));
				}
			}
		}
		if(kase!=1)
			cout<<endl;
		cout<<"Case #"<<kase++<<endl;
		for (int i = 0; i < command; i++)
		{
			int s,e;
			cin>>s>>e;
			if(graph[s][e]!=INF)
			{
				cout<<graph[s][e]<<endl;
			}
			else
			{
				cout<<"no path"<<endl;
			}
		}
	}
	return 0;
}