#include <cstdio>
#include <cstring>
#include <cctype>
#include <queue>
#define in(x) scanf("%d",&x)
#define ins(x) scanf("%s",x)
#define out(x) printf("%d\n",x)
#define ms(x) memset(x,0,sizeof(x))
#define cp(x) while(!x.empty())x.pop()
#define rep(i, a, b) for(int i=a;i<b;++i)
const int maxn = 21;
const int KEY = 10;
using namespace std;
struct Node
{
    int x, y, s, key;
    Node()
    {}
    Node(int x, int y, int s, int key) : x(x), y(y), s(s), key(key)
    {}
};
char mp[maxn][maxn];
bool visit[1 << KEY][maxn][maxn];
int n, m, T;
queue<Node> q;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
inline int ctoi(char c)
{
    return c - (isupper(c) ? 'A' : 'a');
}
inline int isWall(int x, int y)
{
    return (x < 0 || x >= n || y < 0 || y >= m || mp[x][y] == '*');
}
int BFS(int sx, int sy)
{
    Node cur;
    int x, y, step, key, i;
    cp(q);
    ms(visit);
    visit[0][sx][sy] = true;
    q.push(Node(sx, sy, 0, 0));
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        if (cur.s >= T)
            break;
        for (i = 0; i < 4; i++)
        {
            x = cur.x + dx[i];
            y = cur.y + dy[i];
            step = cur.s + 1;
            key = cur.key;
            if (mp[x][y] == '^')
                return step;
            if (isWall(x, y) || visit[key][x][y] || (isupper(mp[x][y]) && !(key & (1 << ctoi(mp[x][y])))))
                continue;
            if (islower(mp[x][y]))
                key |= (1 << ctoi(mp[x][y]));
            if (!visit[key][x][y])
            {
                visit[key][x][y] = true;
                q.push(Node(x, y, step, key));
            }
        }
    }
    return -1;
}

int main(void)
{
    int x, y;
    while (~in(n) && ~in(m) && ~in(T))
    {
        rep(i, 0, n)
        {
            ins(mp[i]);
            rep(j, 0, m)
            {
                if (mp[i][j] == '@')
                {
                    mp[i][j] = '.';
                    x = i, y = j;
                }
            }
        }
        --T;
        out(BFS(x, y));
    }
    return 0;
}
