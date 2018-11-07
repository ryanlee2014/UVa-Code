#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define in(x) scanf("%d",&x)
#define c() getchar()
#define inc(x) scanf("%c",&x)
#define out(x) printf("%d\n",x)
#define ms(x) memset(x,0,sizeof(x))
#define cp(x) while(!x.empty())x.pop()
#define rep(i, a, b) for(int i=a;i<b;++i)
const int inf=0x3f3f3f3f;
using namespace std;
int row,col;
int ans;
int sx,sy;
int ex,ey;
char mp[220][220];
bool visit[220][220];
const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};
struct Node{
    int x,y,s;
    bool operator<(const Node& v)const
    {
        return s>v.s;
    }
};
inline bool isv(int x,int y)
{
    return !(x<1||x>row||y<1||y>col||mp[x][y]=='#'||visit[x][y]);
}
int bfs()
{
    priority_queue<Node>q;
    Node now,next;
    now.x=sx;
    now.y=sy;
    now.s=0;
    q.push(now);
    while(!q.empty())
    {
        now=q.top();
        q.pop();
        if(now.x==ex&&now.y==ey)
            return now.s;
        for (int i = 0; i < 4; ++i)
        {
            next.x=now.x+dx[i];
            next.y=now.y+dy[i];
            if(isv(next.x,next.y))
            {
                visit[next.x][next.y]=true;
                next.s=now.s+(mp[next.x][next.y]=='x'?2:1);
                q.push(next);
            }
        }
    }
    return -1;
}

int main(void)
{
    while(~in(row)&&~in(col)&&row&&col)
    {
        c();
        ans=inf;
        sx=sy=0;
        ex=ey=0;
        ms(mp);
        ms(visit);
        rep(i,1,row+1)
        {
            rep(j, 1, col + 1)
            {
                inc(mp[i][j]);
                if (mp[i][j] == 'r')
                    sx = i, sy = j;
                else if (mp[i][j] == 'a')
                    ex = i, ey = j;
            }
            c();
        }
        visit[sx][sy]=true;
        ans=bfs();
        if(~ans)
            out(ans);
        else
            puts("Poor ANGEL has to stay in the prison all his life.");
    }
    return 0;
}