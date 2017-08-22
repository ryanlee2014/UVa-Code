#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#define in(x) scanf("%d",&x)
#define ins(x) scanf("%s",x)
#define inf(x) scanf("%lf",&x)
#define inc(x) scanf("%c",&x)
#define gc() getchar()
#define out(x) printf("%d\n",x)
#define od(x, y) printf("%d %d\n",x,y)
#define ms(x) memset(x,0,sizeof(x))
#define msc(x, n) memset(x,n,sizeof(x))
#define cp(x) while(!x.empty())x.pop()
#define rep(i, a, b) for(int i=a;i<b;++i)
#define rvep(i, a, b) for(int i=a;i>=b;--i)
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 2010;
int T, m, p[maxn], s[maxn], e[maxn], kase = 0, n;
struct Edge
{
    int from, to, cap, flow;
    Edge()
    {}
    Edge(int from, int to, int cap, int flow) : from(from), to(to), cap(cap), flow(flow)
    {}
    bool operator<(const Edge &v) const
    {
        return from < v.from || (from == v.from && to < v.to);
    }
};

struct Dinic
{
    int n, m, s, t;
    vector<Edge> edges;
    vector<int> G[maxn];
    bool vis[maxn];
    int d[maxn];
    int cur[maxn];
    void init(int n)
    {
        rep(i, 0, n)G[i].clear();
        edges.clear();
    }
    void AddEdge(int from, int to, int cap)
    {
        edges.push_back(Edge(from, to, cap, 0));
        edges.push_back(Edge(to, from, 0, 0));
        m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }
    bool BFS()
    {
        ms(vis);
        queue<int> q;
        q.push(s);
        vis[s] = 1;
        d[s] = 0;
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            rep(i, 0, G[x].size())
            {
                Edge &e = edges[G[x][i]];
                if (!vis[e.to] && e.cap > e.flow)
                {
                    vis[e.to] = 1;
                    d[e.to] = d[x] + 1;
                    q.push(e.to);
                }
            }
        }
        return vis[t];
    }
    int DFS(int x, int a)
    {
        if (x == t || a == 0) return a;
        int flow = 0, f;
        for(int& i = cur[x]; i < G[x].size(); i++) 
        {
            Edge &e = edges[G[x][i]];
            if (d[x] + 1 == d[e.to] && (f = DFS(e.to, min(a, e.cap - e.flow))) > 0)
            {
                e.flow += f;
                edges[G[x][i] ^ 1].flow -= f;
                flow += f;
                a -= f;
                if (a == 0) break;
            }
        }
        return flow;
    }
    int Maxflow(int s, int t)
    {
        this->s = s;
        this->t = t;
        int flow = 0;
        while (BFS())
        {
            ms(cur);
            flow += DFS(s, INF);
        }
        return flow;
    }
};
Dinic dinic;
int main(void)
{
    in(T);
    while (T--)
    {
        in(n), in(m);
        int max_t = 0, flow = 0;
        rep(i, 1, n + 1)
        {
            in(p[i]), in(s[i]), in(e[i]);
            flow += p[i];
            max_t = max(max_t, e[i]);
        }
        dinic.init(max_t + n + 5);
        rep(i, 1, max_t + 1)
        {
            dinic.AddEdge(0, i, m);
        }
        rep(i, 1, n + 1)
        {
            rep(j, s[i], e[i] + 1)
            {
                dinic.AddEdge(j, max_t + i, 1);
            }
            dinic.AddEdge(max_t + i, max_t + n + 1, p[i]);
        }
        printf("Case %d: ", ++kase);
        if (flow == dinic.Maxflow(0, max_t + n + 1)) printf("Yes");
        else printf("No");
        puts("\n");
    }
    return 0;
}

