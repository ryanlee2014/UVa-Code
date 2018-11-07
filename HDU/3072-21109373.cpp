#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;
#define in(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define ms(x) memset(x,0,sizeof(x))
#define msc(x, n) memset(x,n,sizeof(x))
#define cp(x) while(!x.empty())x.pop()
#define rep(i, a, b) for(int i=a;i<b;++i)
#define rnep(i, a, b, c) for(int i=a;i!=b;i=c)
const int maxn = 50010;
const int INF = 0x3f3f3f3f;
struct Edge
{
    int to, next;
};
struct Node
{
    int u, v, w;
};
Edge edge[2 * maxn];
Node node[2 * maxn];
int n, m;
int arr[maxn];
int head[maxn], tot;
int dfn[maxn], low[maxn], belong[maxn];
bool instack[maxn];
int idx, cnt;
stack<int> s;
inline void addedge(int u, int v)
{
    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot++;
}
void tarjan(int u)
{
    int v;
    low[u] = dfn[u] = ++idx;
    instack[u] = true;
    s.push(u);
    rnep(i,head[u],-1,edge[i].next)
    {
        v = edge[i].to;
        if (!dfn[v])
        {
            tarjan(v);
            if (low[u] > low[v])
                low[u] = low[v];
        }
        else if (instack[v] && low[u] > dfn[v])
            low[u] = dfn[v];
    }
    if (dfn[u] == low[u])
    {
        cnt++;
        do
        {
            instack[v = s.top()] = false;
            s.pop();
            belong[v] = cnt;
        } while (u != v);
    }
}

int main(void)
{
    int u, v, w;
    while (~in(n) && ~in(m))
    {
        cnt = tot = idx = 0;
        msc(head, -1);
        ms(dfn);
        ms(instack);
        cp(s);
        rep(i, 0, m)
        {
            in(u), in(v), in(w);
            ++u, ++v;
            node[i].u = u;
            node[i].v = v;
            node[i].w = w;
            addedge(u, v);
        }
        rep(i, 1, n + 1)
        {
            if (!dfn[i])
                tarjan(i);
        }
        msc(arr,0x3f);
        rep(i,0,m)
        {
            int t1 = belong[node[i].u];
            int t2 = belong[node[i].v];
            if(t1 != t2)
            {
                arr[t2] = min(arr[t2],node[i].w);
            }
        }
        int ans = 0;
        rep(i, 1, cnt + 1)
            if (arr[i] != INF)
                ans += arr[i];
        out(ans);
    }
    return 0;
}