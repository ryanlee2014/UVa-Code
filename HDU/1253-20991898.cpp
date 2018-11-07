#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define in(x) scanf("%d",&x)
#define ins(x) scanf("%s",&x)
#define inf(x) scanf("%lf",&x)
#define inc(x) scanf("%c",&x)
#define out(x) printf("%d\n",x)
#define od(x,y) printf("%d %d\n",x,y)
#define ms(x) memset(x,0,sizeof(x))
#define cp(x) while(!x.empty())x.pop()
#define rep(i, a, b) for(int i=a;i<b;++i)
using namespace std;
const int dx[]={1,-1,0,0,0,0};
const int dy[]={0,0,1,-1,0,0};
const int dz[]={0,0,0,0,1,-1};

int abs(int x)
{
    return x < 0 ? -x : x;
}
struct Node
{
    int x,y,z,s;
    Node(){}
    Node(int x,int y,int z,int s):x(x),y(y),z(z),s(s){}
};
int a,b,c,s;
int mp[61][61][61];
bool vis[61][61][61];
inline bool isv(int x,int y,int z)
{
    return !(x<0||x>=a||y<0||y>=b||z<0||z>=c||mp[x][y][z]||vis[x][y][z]);
}

Node now,nxt;
int bfs()
{
    queue<Node>q;
    vis[0][0][0]=true;
    q.push(Node(0,0,0,0));
    while(!q.empty())
    {
        now=q.front();
        q.pop();
        if(now.x==a-1&&now.y==b-1&&now.z==c-1&&now.s<=s)return now.s;
        rep(i,0,6)
        {
            nxt.x=now.x+dx[i];
            nxt.y=now.y+dy[i];
            nxt.z=now.z+dz[i];
            nxt.s=now.s+1;
            if(isv(nxt.x,nxt.y,nxt.z))
            {
                vis[nxt.x][nxt.y][nxt.z]=true;
                if (abs(nxt.x - a + 1) + abs(nxt.y - b + 1) + abs(nxt.z - c + 1) + now.s > s)
                    continue;
                q.push(nxt);
            }
        }
    }
    return -1;
}

int main(void)
{
    int t;
    in(t);
    while(t--)
    {
        ms(mp);
        ms(vis);
        in(a),in(b),in(c),in(s);
        rep(i,0,a)rep(j,0,b)rep(k,0,c)in(mp[i][j][k]);
        out(bfs());
    }
    return 0;
}