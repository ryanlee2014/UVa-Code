#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <cstring>
#define in(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define ms(x) memset(x,0,sizeof(x))
int mp[20][20],use[20][20];
using namespace std;
struct Node
{
	int x,y,use,remain;
};

const int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};;

Node now,nxt;
int row,col,ans,remain;
bool f;

void input_map()
{
	ms(mp);
	ms(use);
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			in(mp[i][j]);
			if(mp[i][j]==2)
			{
				now.x=i;
				now.y=j;
				now.use=0;
				now.remain=6;
				use[i][j]=6;
			}
		}
	}
}

inline bool check()
{
	return !(nxt.x<0||nxt.y<0||nxt.x>=row||nxt.y>=col||mp[nxt.x][nxt.y]==0);
}

void BFS()
{
	queue<Node>q;
	q.push(now);
	while(!q.empty()&&!(f))
	{
		now=q.front();
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			nxt.x=now.x+dir[i][0];
			nxt.y=now.y+dir[i][1];
			nxt.use=now.use+1;
			nxt.remain=now.remain-1;
			if(check())
			{
				if(mp[nxt.x][nxt.y]==3)
				{
					ans=nxt.use;
					remain=nxt.remain;
					f=true;
					break;
				}
				if(mp[nxt.x][nxt.y]==4)
				{
					nxt.remain=6;
				}
				if(nxt.remain > use[nxt.x][nxt.y] && nxt.remain>1)
				{
					use[nxt.x][nxt.y]=nxt.remain;
					q.push(nxt);
				}
			}
		}
		if(f)break;
	}
}

int main(void)
{
	int t;
	in(t);
	while(t--)
	{
		f=false;
		in(row),in(col);
		input_map();
		BFS();
		if(f&&remain>0)
			out(ans);
		else
			out(-1);
	}
	return 0;
}