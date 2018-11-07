#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define in(x) scanf("%d",&x)
#define ins(x) scanf("%s",x)
#define inf(x) scanf("%lf",&x)
#define inc(x) scanf("%c",&x)
#define gc() getchar()
#define out(x) printf("%lld\n",x)
#define od(x,y) printf("%d %d\n",x,y)
#define ms(x) memset(x,0,sizeof(x))
#define msc(x,n) memset(x,n,sizeof(x))
#define cp(x) while(!x.empty())x.pop()
#define rep(i, a, b) for(int i=a;i<b;++i)
#define rvep(i, a, b) for(int i=a;i>=b;--i)
const int INF=0x3f3f3f3f;
const int MAXN=1000010;
typedef long long ll;
struct Node
{
    int v;
    int w;
    Node(int v=0,int c=0):v(v),w(c){}
    bool operator <(const Node &b)const
    {
        return w>b.w;
    }
};
struct Edge
{
    int v,cost;
    Edge(int v=0,int cost=0):v(v),cost(cost){}
};
vector<Edge>G[MAXN];
bool vis[MAXN];
int dis[MAXN],u[MAXN],v[MAXN],w[MAXN];
void Dijkstra(int start)
{
    ms(vis);
    msc(dis,INF);
    priority_queue<Node>q;
    cp(q);
    dis[start]=0;
    q.push(Node(start,0));
    Node tmp;
    while(!q.empty())
    {
        tmp=q.top();
        q.pop();
        int u=tmp.v;
        if(vis[u])
            continue;
        vis[u]=true;
        rep(i,0,G[u].size())
        {
            int v=G[tmp.v][i].v;
            int cost=G[u][i].cost;
            if(!vis[v]&&dis[v]>dis[u]+cost)
            {
                dis[v]=dis[u]+cost;
                q.push(Node(v,dis[v]));
            }
        }
    }
}
void add_edge(int u, int v, int w)
{
    G[u].push_back(Edge(v,w));
}

int main(void)
{
    int n,m,T;
    in(T);
    while(T--)
    {
        in(n),in(m);
        rep(i,1,n+1)G[i].clear();
        rep(i,0,m)
        {
            in(u[i]), in(v[i]), in(w[i]);
            add_edge(u[i], v[i], w[i]);
        }
        Dijkstra(1);
        ll ans=0;
        rep(i,1,n+1)ans+=dis[i];
        rep(i,1,n+1)G[i].clear();
        rep(i,0,m)add_edge(v[i], u[i], w[i]);
        Dijkstra(1);
        rep(i,1,n+1)ans+=dis[i];
        out(ans);
    }
    return 0;
}