#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 1211;
const int inf = 0x3f3f3f3f;
#define msc(x, n) memset(x,n,sizeof(x))
#define in(x) scanf("%d",&x)
#define ins(x) scanf("%s",&x)
#define inf(x) scanf("%lf",&x)
#define inc(x) scanf("%c",&x)
#define c() getchar()
#define out(x) printf("%d\n",x)
#define od(x, y) printf("%d %d\n",x,y)
#define ms(x) memset(x,0,sizeof(x))
#define cp(x) while(!x.empty())x.pop()
#define rep(i, a, b) for(int i=a;i<b;++i)
#define rvep(i, a, b) for(int i=a;i>=b;--i)
const int len = 2520;
struct Edge
{
    int v, next, val;
    Edge():v(0),next(-1),val(0){}
};
struct Node
{
    int u, val;
    Node():u(0),val(0){}
    bool operator<(const Node &v) const
    {
        return val > v.val;
    }
};
inline void snode(Node &v, int a, int b)
{
    v.u = a;
    v.val = b;
}

Edge edge[maxn * maxn];
int n, m, idx;
int dist[maxn], nxt[maxn];
bool vis[maxn];

void add_edge(int u, int v, int sp)
{
    edge[idx].v = v;
    edge[idx].next = nxt[u];
    edge[idx].val = sp;
    nxt[u] = idx++;
}
inline void add_list(int u, int v, int dir, char c)
{
    if (c == '*')
    {
        add_edge(u, v, dir);
        add_edge(v, u, dir);
        return;
    }
    if (c == '>' || c == 'v')
        add_edge(u, v, dir);
    else
        add_edge(v, u, dir);
}
inline void init()
{
    idx = 0;
    msc(nxt, 0xff);
    msc(vis, 0);
    msc(dist, 0x3f);
}
void input()
{
    int  u, v, sp;
    char ch;
    rep(i,0,n-1)
    {
        rep(j,0,m-1)
        {
            scanf("%d %c", &sp, &ch);
            if (sp == 0)
                continue;
            u = i * m + j;
            v = u + 1;
            add_list(u, v, sp, ch);
        }
        rep(j,0,m)
        {
            scanf("%d %c", &sp, &ch);
            if (sp == 0)
                continue;
            u = i * m + j;
            v = (i + 1) * m + j;
            add_list(u, v, sp, ch);
        }
    }
    rep(j,0,m-1)
    {
        scanf("%d %c", &sp, &ch);
        u = (n - 1) * m + j;
        v = u + 1;
        if (sp == 0)
            continue;
        add_list(u, v, sp, ch);
    }
}
int dijkstra()
{
    int cur, tmp, v;
    int e = n * m;
    priority_queue<Node> q;
    Node node, t_node;
    cp(q);
    snode(t_node, 0, 0);
    q.push(t_node);
    dist[0] = 0;
    msc(vis,0);
    while (!q.empty())
    {
        node = q.top();
        q.pop();
        cur = node.u;
        if (vis[node.u])
            continue;
        if (cur == e - 1)
            return node.val;
        vis[cur] = true;
        for (int i = nxt[cur]; i != -1; i = edge[i].next)
        {
            v = edge[i].v;
            if (vis[v])
                continue;
            tmp = dist[cur] + len / edge[i].val;
            if (dist[v] > tmp)
            {
                dist[v] = tmp;
                snode(t_node, v, tmp);
                q.push(t_node);
            }
        }
    }
    return -1;
}

int main(void)
{
    while (~in(n)&&~in(m)&&n++&&m++)
    {
        init();
        input();
        int ans;
        ans = dijkstra();
        if (ans == -1)
            puts("Holiday");
        else
            printf("%d blips\n", ans);
    }
    return 0;
}