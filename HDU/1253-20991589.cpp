#define _CRT_SECURE_NO_DEPRECATE 
#define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES 1 

#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
const int N = 55;

int map[N][N][N];
int vis[N][N][N];
int tx[] = { 1,-1,0,0,0,0 };
int ty[] = { 0,0,1,-1,0,0 };
int tz[] = { 0,0,0,0,1,-1 };
int a, b, c, t, ans;

struct Node
{
    int x, y, z, step;
};

int abs(int x)//绝对值
{
    return x < 0 ? -x : x;
}

int check(int i, int j, int k)//判断是否可行
{
    if (i < 0 || j < 0 || k < 0 || i >= a || j >= b || k >= c || map[i][j][k])
        return 0;
    return 1;
}

int bfs(int x, int y, int z)
{
    int i;
    queue<Node> Q;
    Node p, q;
    p.x = x;
    p.y = y;
    p.z = z;
    p.step = 0;
    vis[x][y][z] = 1;
    Q.push(p);
    while (!Q.empty())
    {
        p = Q.front();
        Q.pop();
        if (p.x == a - 1 && p.y == b - 1 && p.z == c - 1 && p.step <= t)
            return p.step;
        for (i = 0; i < 6; i++)
        {
            q = p;
            q.x += tx[i];
            q.y += ty[i];
            q.z += tz[i];
            if (!vis[q.x][q.y][q.z] && check(q.x, q.y, q.z))
            {
                q.step++;
                vis[q.x][q.y][q.z] = 1;
                //由于行走只能朝6个固定方向，这里是对剩下时间里能否走到出口进行预判，如果走最短路径依然不能再规定时间内到达出口，明显是不行的,当然不加这个判断也能AC，只是比较消耗时间
                if (abs(q.x - a + 1) + abs(q.y - b + 1) + abs(q.z - c + 1) + q.step > t)
                    continue;
                Q.push(q);
            }
        }
    }
    return -1;
}

int main()
{
    int cas;
    scanf("%d", &cas);
    while (cas--)
    {
        int i, j, k;
        scanf("%d%d%d%d", &a, &b, &c, &t);
        memset(map, 0, sizeof(map));
        memset(vis, 0, sizeof(vis));
        for (i = 0; i < a; i++)
            for (j = 0; j < b; j++)
                for (k = 0; k < c; k++)
                    scanf("%d", &map[i][j][k]);
        ans = bfs(0, 0, 0);
        printf("%d\n", ans);
    }

    return 0;
}
