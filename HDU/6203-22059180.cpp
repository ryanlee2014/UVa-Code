#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAXN 100100
#define MAXM 200100
#define MAXNODE 100100
#define INF 0x3f3f3f3f
using namespace std;

struct Edge
{
    int from,to,next;
    Edge(){}
    Edge(int u,int v,int n):from(u),to(v),next(n){}
};

int n,m;
Edge edges[MAXM];
int head[MAXN],tot,idc;
int num[MAXN],size[MAXN],dep[MAXN],son[MAXN],fa[MAXN];
int top[MAXN],id[MAXN];

struct Node
{
    int from,to,lca;
    Node(){}
    Node(int u,int v,int lca):from(u),to(v),lca(lca){}
    bool operator < (const Node &rhs) const
    {
        return dep[lca]>dep[rhs.lca];
    }
};

Node a[MAXNODE];

void AddEdge(int u,int v)
{
    edges[tot]=Edge(u,v,head[u]);
    head[u]=tot++;
    edges[tot]=Edge(v,u,head[v]);
    head[v]=tot++;
}

void init()
{
    tot=idc=0;
    memset(head,-1,sizeof(head));
    memset(son,-1,sizeof(son));
}

void dfs1(int u,int p,int d)
{
    dep[u]=d;
    fa[u]=p;
    size[u]=1;
    for(int i=head[u];~i;i=edges[i].next)
    {
        Edge &e=edges[i];
        if(e.to==p) continue;
        dfs1(e.to,u,d+1);
        size[u]+=size[e.to];
        if(!~son[u] || size[e.to]>size[son[u]]) son[u]=e.to;
    }
}

void dfs2(int u,int fa,int tp)
{
    top[u]=tp;
    id[u]=++idc;
    if(!~son[u]) return;
    dfs2(son[u],u,tp);
    for(int i=head[u];~i;i=edges[i].next)
    {
        Edge &e=edges[i];
        if(e.to==son[u] || e.to==fa) continue;
        dfs2(e.to,u,e.to);
    }
}

int tree[MAXN*4];

void maintain(int u)
{
    tree[u]=max(tree[u<<1],tree[u<<1|1]);
}

void build()
{
    memset(tree,0,sizeof(tree));
}

void update(int u,int L,int R,int p,int v)
{
    if(L==R)
    {
        tree[u]=v;
        return;
    }
    int mid=L+(R-L)/2;
    int lc=u<<1,rc=u<<1|1;
    if(p<=mid) update(lc,L,mid,p,v);
    else update(rc,mid+1,R,p,v);
    maintain(u);
}

int query(int u,int L,int R,int ql,int qr)
{
    if(ql<=L && R<=qr) return tree[u];
    int mid=L+(R-L)/2;
    int lc=u<<1,rc=u<<1|1;
    int res=-INF;
    if(ql<=mid) res=max(res,query(lc,L,mid,ql,qr));
    if(qr>mid) res=max(res,query(rc,mid+1,R,ql,qr));
    return res;
}

void change(int x,int v)
{
    update(1,1,idc,id[x],v);
}

int find(int u,int v)
{
    int res=-INF;
    while(top[u]!=top[v])
    {
        if(dep[top[u]]<dep[top[v]]) swap(u,v);
        res=max(res,query(1,1,idc,id[top[u]],id[u]));
        u=fa[top[u]];
    }
    if(dep[u]>dep[v]) swap(u,v);
    res=max(res,query(1,1,idc,id[u],id[v]));
    return res;
}

int lca(int u,int v)
{
    while(top[u]!=top[v])
    {
        if(dep[top[u]]<dep[top[v]]) swap(u,v);
        u=fa[top[u]];
    }
    return dep[u]<dep[v]?u:v;
}

int main()
{
    while(~scanf("%d",&n))
    {
        init();
        for(int i=0;i!=n;++i)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            AddEdge(u,v);
        }
        dfs1(0,-1,1);
        dfs2(0,-1,0);
        build();
        scanf("%d",&m);
        for(int i=0;i!=m;++i)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            a[i]=Node(u,v,lca(u,v));
        }
        sort(a,a+m);
        int ans=0;
        for(int i=0;i!=m;++i)
        {
            Node &e=a[i];
            if(find(e.from,e.to)) continue;
            else change(e.lca,1),++ans;
        }
        printf("%d\n",ans);
    }
}