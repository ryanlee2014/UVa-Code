#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

char h[110][110];
int vis[110][110][4];
int n, m;

int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
//下 上 右 左 
struct node
{
    int x, y, t, f;
};

bool operator < (const node& a, const node& b)
{
    return a.t > b.t;
}

bool judge(int x, int y, int f, int t)
{
    return (x > 0 && x <= n && y > 0 && y <= m && h[x][y] == '.' && t < vis[x][y][f]);
}

node s, t, temp1, temp2;
int k;

bool bfs()
{
    priority_queue<node> q;
    memset(vis, 0x3f3f3f3f, sizeof(vis));
    s.t = -1;
    s.f = -1;
    q.push(s);
    while (!q.empty())
    {
        temp1 = q.top();
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            temp2 = temp1;
            temp2.x += dir[i][0];
            temp2.y += dir[i][1];
            if (temp2.f != i)
            {
                temp2.t++;
                temp2.f = i;
            }
            //printf("%d %d %d %d\n", temp2.x, temp2.y, temp2.f, temp2.t);
            if (temp2.t > k) continue;
            if (temp2.x == t.x && temp2.y == t.y)
            {
                return true;
            }
            if (judge(temp2.x, temp2.y, temp2.f, temp2.t))
            {
                vis[temp2.x][temp2.y][temp2.f] = temp2.t;
                q.push(temp2);
            }
        }
    }
    return false;
}

int main()
{
    int T;
    scanf("%d", &T);
    getchar();
    while (T--)
    {
        scanf("%d %d", &n, &m);
        getchar();
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                h[i][j] = getchar();
            }
            getchar();
        }
        scanf("%d %d %d %d %d", &k, &s.y, &s.x, &t.y, &t.x);
        printf("%s\n", bfs()?"yes":"no");
    }
    return 0;
}

