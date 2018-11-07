#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<vector>
#include<cmath>
#include<string>
#include<algorithm>
#define INF 0x3f3f3f3f3f3f3f3f
#define LL long long
#define MAXN 100010
#define MAXM 300010
#define MOD 1000000007
#define lowbit(x) (x)&(-x)
#define mk(a,b) make_pair(a,b)
#define Pii pair<int,int>
using namespace std;

struct Edge
{
    int from,to,next;
    LL dist;
    Edge(){}
    Edge(int u,int v,int n,LL d):from(u),to(v),next(n),dist(d){}
};

struct Node
{
    LL d; int u;
    bool operator < (const Node &rhs) const
    {
        return d>rhs.d;
    }
};

int n,m;
int head[MAXN],tot;
Edge edges[MAXM];
LL d1[MAXN],d2[MAXN];
LL mi[MAXN];
int vis[MAXN];

void init()
{
    tot=0;
    memset(head,-1,sizeof(head));
}

void AddEdge(int u,int v,LL d)
{
    edges[tot]=Edge(u,v,head[u],d);
    head[u]=tot++;
    edges[tot]=Edge(v,u,head[v],d);
    head[v]=tot++;
}

LL dijkstra(int s)
{
    memset(d1,0x3f,sizeof(d1));
    memset(vis,0,sizeof(vis));
    memset(d2,0x3f,sizeof(d2));
    memset(mi,0x3f,sizeof(mi));
    priority_queue<Node> q;
    d1[s]=0;
    q.push((Node){0,s});
    while(!q.empty())
    {
        Node x=q.top(); q.pop();
        int u=x.u;
        LL d=x.d;
        if(d2[u]<d) continue;
        if(mi[u]==INF)
        {
            for(int i=head[u];~i;i=edges[i].next)
            {
                Edge &e=edges[i];
                mi[u]=min(mi[u],e.dist);
            }
        }
        for(int i=head[u];~i;i=edges[i].next)
        {
            Edge &e=edges[i];
            LL w=d+e.dist;
            if(d1[e.to]>w || (d1[e.to]==w && mi[u]<mi[e.to]))
            {
                swap(d1[e.to],w);
                mi[e.to]=min(mi[e.to],mi[u]);
                q.push((Node){d1[e.to],e.to});
            }
            if(d2[e.to]>w && d1[e.to]<=w)
            {
                d2[e.to]=w;
                q.push((Node){d2[e.to],e.to});
            }
        }
    }
    LL res=d2[n];
    return res;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        init();
        scanf("%d%d",&n,&m);
        for(int i=0;i!=m;++i)
        {
            int u,v;
            LL w;
            scanf("%d%d%lld",&u,&v,&w);
            AddEdge(u,v,w);
        }
        LL ans=dijkstra(1);
        printf("%lld\n",ans);
    }
}