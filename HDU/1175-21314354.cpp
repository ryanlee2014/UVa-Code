#include <cstdio>
#include <queue>
#include <cstring>
#define in(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define ms(x) memset(x,0,sizeof(x))
#define cp(x) while(!x.empty())x.pop()
#define rep(i, a, b) for(int i=a;i<b;++i)
using namespace std;
int mp[1010][1010];
bool visit[1010][1010][5];
const int dir[4][2] = {{0,  1},
                       {0,  -1},
                       {1,  0},
                       {-1, 0}};
int m, n, T;
struct node
{
    int x, y, turn, dir;
    bool operator==(const node b)
    {
        return x == b.x && y == b.y;
    }
};
node s, e;
queue<node> q;
inline bool check(int x, int y)
{
    return !(x < 1 || x > n || y < 1 || y > m);
}

void bfs()
{
    s.turn = 0;
    s.dir = -1;
    q.push(s);
    while (!q.empty())
    {
        node cur = q.front();
        q.pop();
        if (cur.turn > 2)
            continue;
        if (cur == e)
        {
            puts("YES");
            return;
        }
        node next;
        rep(i,0,4)
        {
            next.x = cur.x + dir[i][0];
            next.y = cur.y + dir[i][1];
            if (!check(next.x, next.y) || visit[next.x][next.y][i])
                continue;
            if (mp[next.x][next.y] && !(next == e))
                continue;
            visit[cur.x][cur.y][i] = 1;
            next.turn = cur.turn;
            next.dir = i;
            if (cur.dir != -1 && cur.dir != i)
                next.turn++;
            q.push(next);
        }
    }
    puts("NO");
}
int main()
{
    while (~in(n) && ~in(m) && m && n)
    {
        rep(i, 1, n + 1)rep(j, 1, m + 1)in(mp[i][j]);
        in(T);
        while (T--)
        {
            in(s.x), in(s.y), in(e.x), in(e.y);
            if (!mp[s.x][s.y] || mp[s.x][s.y] != mp[e.x][e.y] || s == e)
            {
                puts("NO");
                continue;
            }
            cp(q);
            ms(visit);
            bfs();
        }
    }
    return 0;
}