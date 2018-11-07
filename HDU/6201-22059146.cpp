#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#define MAXN 100010
#define MAXM 200010
#define INF 0x3f3f3f3f
using namespace std;

struct Edge
{
    int from,to,next,dist;
    Edge(){}
    Edge(int u,int v,int n,int d):from(u),to(v),next(n),dist(d){}
};

struct Node
{
    int u,d;
    Node(){}
    Node(int u,int d):u(u),d(d){}
};

int n,a[MAXN],vis[MAXN];
Edge edges[MAXM];
int head[MAXN],tot;

void AddEdge(int u,int v,int w)
{
    edges[tot]=Edge(u,v,head[u],w);
    head[u]=tot++;
    edges[tot]=Edge(v,u,head[v],w);
    head[v]=tot++;
}

void init()
{
    tot=0;
    memset(head,-1,sizeof(head));
}

int dp[MAXN][2];

int dfs(int u,int fa,int op)
{
    for(int i=head[u];~i;i=edges[i].next)
    {
        Edge &e=edges[i];
        if(e.to==fa) continue;
        dp[e.to][0]=max(dp[e.to][0],dp[u][0]-e.dist);
        dp[e.to][1]=min(dp[e.to][1],dp[u][1]+e.dist);
        dfs(e.to,u,op);
        if(!~op) continue;
        dp[u][0]=max(dp[u][0],dp[e.to][0]-e.dist);
        dp[u][1]=min(dp[u][1],dp[e.to][1]+e.dist);
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        init();
        scanf("%d",&n);
        for(int i=1;i<=n;++i) scanf("%d",&a[i]);
        for(int i=1;i<=n;++i) dp[i][0]=dp[i][1]=a[i];
        for(int i=0;i!=n-1;++i)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            AddEdge(u,v,w);
        }
        dfs(1,-1,1);
        dfs(1,-1,-1);
        int ans=0;
        for(int i=1;i<=n;++i) ans=max(ans,dp[i][0]-dp[i][1]);
        printf("%d\n",max(ans,0));
    }
}