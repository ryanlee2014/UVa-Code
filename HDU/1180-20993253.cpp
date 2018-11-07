#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define in(x) scanf("%d",&x)
#define ins(x) scanf("%s",&x)
#define inf(x) scanf("%lf",&x)
#define inc(x) scanf("%c",&x)
#define c() getchar()
#define out(x) printf("%d\n",x)
#define od(x,y) printf("%d %d\n",x,y)
#define ms(x) memset(x,0,sizeof(x))
#define cp(x) while(!x.empty())x.pop()
#define rep(i, a, b) for(int i=a;i<b;++i)
using namespace std;
struct Node
{
    int x, y,s;
    Node():x(0),y(0),s(0){}
    Node(int x,int y,int s):x(x),y(y),s(s){}
    bool operator<(const Node& v)const
    {
        return s>v.s;
    }
};

const int dy[]={1,-1,0,0};
const int dx[]={0,0,1,-1};

char mp[30][30];
bool vis[30][30];
int m,n;

priority_queue<Node>q;

inline bool isv(int x,int y)
{
    return !(x<0||x>=m||y<0||y>=n||vis[x][y]||mp[x][y]=='*');
}
Node start,target;
void bfs()
{
    rep(i,0,m)
    {
        rep(j, 0, n)
        {
            if (mp[i][j] == 'S')
            {
                start=Node(i,j,0);
            }
            else if (mp[i][j] == 'T')
            {
                target=Node(i,j,0);
            }
        }
    }
    ms(vis);
    vis[start.x][start.y]=true;
    cp(q);
    q.push(start);
    while(!q.empty())
    {
        Node now=q.top();
        q.pop();
        if(now.x==target.x&&now.y==target.y)
        {
            out(now.s);
            return;
        }
        Node next;
        rep(i,0,4)
        {
            next.x=now.x+dx[i];
            next.y=now.y+dy[i];
            if(!isv(next.x,next.y))
                continue;
            if(mp[next.x][next.y]=='-'||mp[next.x][next.y]=='|')
            {
                int status=0;
                if(mp[next.x][next.y]=='|')
                    status=1;
                if(now.s&1)
                    status = ! status;
                if((!status&&(i==2||i==3))||(status&&(i==0||i==1)))
                {
                    next=now;
                    next.s++;
                    q.push(next);
                    continue;
                }
                next.x+=dx[i];
                next.y+=dy[i];
                if(!isv(next.x,next.y))
                    continue;
            }
            vis[next.x][next.y]=true;
            next.s=now.s+1;
            q.push(next);
        }
    }
}

int main(void)
{
    while(~in(m)&&~in(n))
    {
        rep(i,0,m)
        {
            ins(mp[i]);
        }
        bfs();
    }
    return 0;
}