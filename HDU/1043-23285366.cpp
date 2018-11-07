#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

const int maxn = 370000;
struct Node {
    string path;
    int s[10];
    int loc;
    int ct;
};
int fac[10] = {1, 1, 2, 6, 24, 120, 720, 720 * 7, 720 * 7 * 8, 720 * 7 * 8 * 9};
int dir[4][2] = {0, 1, 0, -1, -1, 0, 1, 0};
int vis[maxn];
char di[5] = "lrdu";
string path[maxn];

void init() {
    memset(vis, 0, sizeof(vis));
}

int cantor(int *a) {
    int sum = 0;
    for (int i = 0; i < 9; i++) {
        int m = 0;
        for (int j = i + 1; j < 9; j++)
            if (a[j] < a[i])
                m++;
        sum += m * (fac[9 - i - 1]);
    }
    return sum + 1;
}

void bfs() {
    Node cur, next;
    queue<Node> q;

    for (int i = 0; i < 8; i++)
        cur.s[i] = i + 1;
    cur.s[8] = 0;
    cur.ct = cantor(cur.s);
    cur.loc = 8;

    q.push(cur);
    vis[cur.ct] = 1;
    path[cur.ct] = "";

    while (!q.empty()) {
        cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int x = cur.loc / 3 + dir[i][0];
            int y = cur.loc % 3 + dir[i][1];
            if (x < 0 || x > 2 || y < 0 || y > 2)
                continue;
            next = cur;
            next.loc = x * 3 + y;
            next.s[cur.loc] = next.s[next.loc];
            next.s[next.loc] = 0;
            next.ct = cantor(next.s);
            if (!vis[next.ct]) {
                vis[next.ct] = 1;
                path[next.ct] = di[i] + path[cur.ct];
                q.push(next);
            }
        }
    }

}

int main() {
    init();
    bfs();
    char s[2];
    int a[10];
    while (~scanf("%s", s)) {
        if (s[0] == 'x')
            a[0] = 0;
        else
            a[0] = s[0] - '0';
        for (int i = 1; i < 9; i++) {
            scanf("%s", s);
            if (s[0] == 'x')
                a[i] = 0;
            else
                a[i] = s[0] - '0';
        }
        int m = cantor(a);
        if (vis[m])
            cout << path[m] << endl;
        else
            puts("unsolvable");
    }
    return 0;
}