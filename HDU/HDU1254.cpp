#include <iostream>
#include <queue>
#include <cstring>
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
using namespace std;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
int m, n, bx, by, sx, sy;
const int maxn = 10;
int mp[maxn][maxn], vis[maxn][maxn];
bool used[maxn][maxn];
struct Node
{
	int x, y, nx, ny, step;
	Node()
	{}
	Node(int x, int y, int nx, int ny, int step) : x(x), y(y), nx(nx), ny(ny), step(step)
	{}
	bool operator<(const Node &v) const
	{
		return step > v.step;
	}
};
inline bool isv(int x, int y)
{
	return !(x < 0 || x >= n || y < 0 || y >= m);
}

bool DFS(int x, int y, int ex, int ey)
{
	used[x][y] = true;
	if (x == ex && y == ey)
		return true;
	rep(i, 0, 4)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (!isv(nx, ny) || mp[nx][ny] == 1 || used[nx][ny])
			continue;
		if (DFS(nx, ny, ex, ey))
			return true;
	}
	return false;
}

int BFS(int x, int y)
{
	queue<Node> q;
	ms(vis);
	Node now(x, y, sx, sy, 0), next;
	vis[x][y] = 1;
	q.push(now);
	while (!q.empty())
	{
		now = q.front();
		q.pop();
		if (mp[now.x][now.y] == 3)return now.step;
		rep(i, 0, 4)
		{
			next.x = now.x + dx[i];
			next.y = now.y + dy[i];
			if (!isv(next.x, next.y) || vis[next.x][next.y] > 2 || mp[next.x][next.y] == 1)
				continue;
			int tx, ty;
			switch (i)
			{
				case 0:
					tx = now.x + dx[1];
					ty = now.y + dy[1];
					break;
				case 1:
					tx = now.x + dx[0];
					ty = now.y + dy[0];
					break;
				case 2:
					tx = now.x + dx[3];
					ty = now.y + dy[3];
					break;
				case 3:
					tx = now.x + dx[2];
					ty = now.y + dy[2];
					break;
				default:
					break;
			}
			if (!isv(tx, ty) || mp[tx][ty] == 1)
				continue;
			int tmp = mp[now.x][now.y];
			mp[now.x][now.y] = 1;
			ms(used);
			if (DFS(now.nx, now.ny, tx, ty))
			{
				next.step = now.step + 1;
				vis[next.x][next.y]++;
				next.nx = now.x;
				next.ny = now.y;
				q.push(next);
			}
			mp[now.x][now.y] = tmp;
		}
	}
	return -1;
}

int main(void)
{
	int t;
	in(t);
	while (t--)
	{
		in(n), in(m);
		rep(i, 0, n) rep(j, 0, m)
			{
				in(mp[i][j]);
				if (mp[i][j] == 2)
				{
					bx = i;
					by = j;
				}
				if (mp[i][j] == 4)
				{
					sx = i;
					sy = j;
				}
			}
		out(BFS(bx, by));
	}
	return 0;
}