#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int MAXN = 50010;
const int MAXM = 100010;
struct Edge
{
    int to,next;
}edge[MAXM];
int head[MAXN],tot;
int Low[MAXN],DFN[MAXN],Stack[MAXN],Belong[MAXN];
int Index,top;
int scc;
bool Instack[MAXN];
void addedge(int u,int v)
{
    edge[tot].to = v;edge[tot].next = head[u];head[u] = tot++;
}
void Tarjan(int u)
{
    int v;
    DFN[u] = Low[u] = ++Index;
    Stack[top++] = u;
    Instack[u] = true;
    for(int i = head[u];i != -1;i = edge[i].next)
    {
        v = edge[i].to;
        if(!DFN[v])
        {
            Tarjan(v);
            if( Low[u] > Low[v] )Low[u] = Low[v];
        }
        else if(Instack[v] && Low[u] > DFN[v])Low[u] = DFN[v];
    }
    if(Low[u] == DFN[u])
    {
        scc++;
        do
        {
            v = Stack[--top];
            Instack[v] = false;
            Belong[v] = scc;
        }
        while( v != u );
    }
}

void init()
{
    tot = 0;
    memset(head,-1,sizeof(head));
}
struct Node
{
    int u,v,c;
}node[MAXM];
int a[MAXN];
const int INF = 0x3f3f3f3f;
int main()
{
    int n,m;
    int u,v,c;
    while(scanf("%d%d",&n,&m) == 2)
    {
        init();
        for(int i = 0;i < m;i++)
        {
            scanf("%d%d%d",&u,&v,&c);
            u++;
            v++;
            node[i].u = u;
            node[i].v = v;
            node[i].c = c;
            addedge(u,v);
        }
        memset(DFN,0,sizeof(DFN));
        memset(Instack,false,sizeof(Instack));
        Index = scc = top = 0;
        for(int i = 1;i <= n;i++)
            if(!DFN[i])
                Tarjan(i);
        for(int i = 1;i <= scc;i++)
            a[i] = INF;
        for(int i = 0;i < m;i++)
        {
            int t1 = Belong[node[i].u];
            int t2 = Belong[node[i].v];
            if(t1 != t2)
            {
                a[t2] = min(a[t2],node[i].c);
            }
        }
        int ans = 0;
        for(int i = 1;i <= scc;i++)
            if(a[i] != INF)
                ans+=a[i];
        printf("%d\n",ans);
    }
    return 0;
}