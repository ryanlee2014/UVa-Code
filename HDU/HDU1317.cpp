#include <iostream>
#include <cstdio>
#include <cstring>
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

const int maxn = 110;
const int INF = 0x3f3f3f3f;

bool G[maxn][maxn];
int iner[maxn];
int d[maxn];
int n, cnt;

struct Edge
{
	int u, v;
};
Edge edge[maxn * maxn];

bool Bellman_ford()
{
	rep(i, 1, n + 1)d[i] = -INF;
	d[1] = 100;
	rep(i, 1, n + 1)
	{
		rep(j, 0, cnt)
		{
			int u = edge[j].u;
			int v = edge[j].v;
			if (d[v] < d[u] + iner[v] && d[u] + iner[v] > 0)
				d[v] = d[u] + iner[v];
		}
	}
	rep(i, 0, cnt)
	{
		int u = edge[i].u;
		int v = edge[i].v;
		if (d[v] < d[u] + iner[v] && d[u] + iner[v] > 0)
			return G[v][n];
	}
	return d[n] > 0;
}

int main()
{
	while (~in(n))
	{
		if (n == -1) break;
		cnt = 0;
		ms(G);
		ms(iner);
		rep(i, 1, n + 1)G[i][i] = true;
		int num;
		rep(i, 1, n + 1)
		{
			int v;
			in(iner[i]), in(num);
			while (num--)
			{
				in(v);
				edge[cnt].u = i;
				edge[cnt++].v = v;
				G[i][v] = true;
			}
		}
		rep(k, 1, n + 1) rep(i, 1, n + 1) rep(j, 1, n + 1) G[i][j] |= G[i][k] && G[k][j];
		puts(Bellman_ford() ? "winnable" : "hopeless");
	}
	return 0;
}