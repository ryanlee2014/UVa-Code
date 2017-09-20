#include<cstdio>
#include<queue>
#include<cstring>
#include<iostream>
#include<algorithm>
#define MAXN 1010
#define MAXM 10010
#define INF 0x3f3f3f3f
#define LL long long
using namespace std;

int read()
{
    int res=0;
    char ch=getchar();
    while(ch<'0' || '9'<ch) ch=getchar();
    while(ch>='0' && ch<='9')
    {
        res=res*10+ch-'0'; ch=getchar();
    }
    return res;
}

struct Edge
{
    int from,to,next,cap;
    Edge(){}
    Edge(int u,int v,int n,int c):from(u),to(v),next(n),cap(c){}
};

int n,m,s,t;
Edge edges[MAXM];
int head[MAXN],tot;
int d[MAXN],cur[MAXN],vis[MAXN];

void init()
{
    tot=0;
    for(int i=1;i<=n;++i) head[i]=-1;
    for(int i=1;i<=n;++i) vis[i]=0;
}

void AddEdge(int u,int v,int c)
{
    edges[tot]=Edge(u,v,head[u],c);
    head[u]=tot++;
    edges[tot]=Edge(v,u,head[v],0);
    head[v]=tot++;
}

int bfs(int s,int t)
{
    for(int i=1;i<=n;++i) d[i]=-1; d[s]=0;
    queue<int> q; q.push(s);
    while(!q.empty())
    {
        int u=q.front(); q.pop();
        for(int i=head[u];~i;i=edges[i].next)
        {
            Edge &e=edges[i];
            if(!~d[e.to] && e.cap)
            {
                d[e.to]=d[u]+1;
                if(e.to==t) return 1;
                q.push(e.to);
            }
        }
    }
    return 0;
}

int dfs(int u,int t,int a)
{
    if(u==t || !a) return a;
    int flow=0,f;
    for(int &i=cur[u];~i;i=edges[i].next)
    {
        Edge &e=edges[i];
        if(d[e.to]==d[u]+1 && (f=dfs(e.to,t,min(a,e.cap))))
        {
            e.cap-=f;
            edges[i^1].cap+=f;
            flow+=f;
            a-=f;
            if(!a) break;
        }
    }
    return flow;
}

int dinic(int s,int t)
{
    int flow=0;
    while(bfs(s,t))
    {
        for(int i=1;i<=n;++i) cur[i]=head[i];
        flow+=dfs(s,t,INF);
    }
    return flow;
}

int main()
{
    int T;
    T=read();
    while(T--)
    {
        n=read(),m=read(),s=read(),t=read();
        init();
        for(int i=0;i!=m;++i)
        {
            int u,v,w;
            u=read(),v=read(),w=read();
            AddEdge(u,v,w*(m+1)+1);
        }
        int ans=dinic(s,t)%(m+1);
        printf("%d\n",ans);
    }
}
