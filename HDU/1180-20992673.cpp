#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
int m, n;
char map[25][25];
bool vis[25][25];
const int dx[] = {0, 0, 1, -1},
            dy[] = {1, -1, 0, 0};
struct node
{
    int x, y, step;
    bool operator < (const node b) const
    {
        return step > b.step;
    }
};
node start, goal;
priority_queue <node> q;
void input()
{
    for (int i = 0; i < m; i++)
        scanf("%s", map[i]);
}
void pre()
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] == 'S')
                start = (node){i, j, 0};
            else if (map[i][j] == 'T')
                goal = (node){i, j, 0};
        }
    while (!q.empty())
        q.pop();
    memset(vis, 0, sizeof(vis));
}
bool check(int x, int y)
{
    if (x < 0 || x >= m || y < 0 || y >= n || vis[x][y] || map[x][y] == '*')
        return 0;
    return 1;
}
void bfs()
{
    pre();
    vis[start.x][start.y] = 1;
    q.push(start);
    while (!q.empty())
    {
        node u = q.top();
        q.pop();
        if (u.x == goal.x && u.y == goal.y)
        {
            printf("%d\n", u.step);
            return;
        }
        node next;
        for (int i = 0; i < 4; i++)
        {
            next.x = u.x + dx[i];
            next.y = u.y + dy[i];
            if (!check(next.x, next.y))
                continue;
            if (map[next.x][next.y] == '-' || map[next.x][next.y] == '|')
            {
                int curmap = 0;
                if (map[next.x][next.y] == '|')
                    curmap = 1;
                if (u.step % 2)
                    curmap = !curmap;
                if ((!curmap && (i == 2 || i == 3)) || (curmap && (i == 0 || i == 1)))
                {
                    next = u;
                    next.step++;
                    q.push(next);
                    continue;
                }
                next.x += dx[i];
                next.y += dy[i];
                if (!check(next.x, next.y))
                    continue;
            }
            vis[next.x][next.y] = 1;
            next.step = u.step + 1;
            q.push(next);
        }
    }
}
int main()
{
    while (scanf("%d%d", &m, &n) == 2)
    {
        input();
        bfs();
    }
    return 0;
}