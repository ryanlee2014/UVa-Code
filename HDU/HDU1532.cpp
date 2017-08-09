#include <cstdio>
#include <cstring>
#include <queue>
#define in(x) scanf("%d",&x)
#define ins(x) scanf("%s",&x)
#define inf(x) scanf("%lf",&x)
#define inc(x) scanf("%c",&x)
#define c() getchar()
#define out(x) printf("%d\n",x)
#define od(x, y) printf("%d %d\n",x,y)
#define ms(x) memset(x,0,sizeof(x))
#define msc(x, c) memset(x,c,sizeof(x))
#define cp(x) while(!x.empty())x.pop()
#define rep(i, a, b) for(int i=a;i<b;++i)
#define min(x, y) ((x<y)?(x):(y))
using namespace std;
const int MAX = 0x3f3f3f3f;
int tab[250][250], dis[250], n, m, ans;//n:点数;m,边数
bool BFS()
{
	queue<int> q;
	msc(dis, 0xff);//以-1填充
	dis[1] = 0;
	q.push(1);
	while (!q.empty())
	{
		int j = q.front();
		q.pop();
		rep(i, 1, n + 1) if (dis[i] < 0 && tab[j][i] > 0)
			{
				dis[i] = dis[j] + 1;
				q.push(i);
			}
	}
	return dis[n] > 0;
}
int find(int x, int low)
{
	int a = 0;
	if (x == n)
		return low;//是汇点
	rep(i, 1, n + 1) if (tab[x][i] > 0 //联通
	                     && dis[i] == dis[x] + 1 //是分层图的下一层
	                     && (a = find(i, min(low, tab[x][i]))))//能到汇点(a <> 0)
		{
			tab[x][i] -= a;
			tab[i][x] += a;
			return a;
		}
	return 0;

}
int main(void)
{
	int from, to, flow, temp;
	while (~in(m) && ~in(n))
	{
		ms(tab);
		rep(i, 1, m + 1)
		{
			in(from), in(to), in(flow);
			tab[from][to] += flow;
		}
		ans = 0;
		while (BFS())while (temp = find(1, 0x7fffffff))ans += temp;
		out(ans);
	}
}