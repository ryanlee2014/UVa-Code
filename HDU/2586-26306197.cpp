#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;
//#pragma comment(linker, "/STACK:102400000,102400000") //不需要申请系统栈
const int N = 40010;
const int M = 25;
int dp[2 * N][M];  //这个数组记得开到2*N，因为遍历后序列长度为2*n-1
bool vis[N];
struct edge {
    int u, v, w, next;
} e[2 * N];
int tot, head[N];

inline void add(int u, int v, int w, int &k) {
    e[k].u = u;
    e[k].v = v;
    e[k].w = w;
    e[k].next = head[u];
    head[u] = k++;
    u = u ^ v;
    v = u ^ v;
    u = u ^ v;
    e[k].u = u;
    e[k].v = v;
    e[k].w = w;
    e[k].next = head[u];
    head[u] = k++;
}

int ver[2 * N], R[2 * N], first[N], dir[N];

void dfs(int u, int dep) {
    vis[u] = true;
    ver[++tot] = u;
    first[u] = tot;
    R[tot] = dep;
    for (int k = head[u]; k != -1; k = e[k].next)
        if (!vis[e[k].v]) {
            int v = e[k].v, w = e[k].w;
            dir[v] = dir[u] + w;
            dfs(v, dep + 1);
            ver[++tot] = u;
            R[tot] = dep;
        }
}

void ST(int n) {
    for (int i = 1; i <= n; i++)
        dp[i][0] = i;
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            int a = dp[i][j - 1], b = dp[i + (1 << (j - 1))][j - 1];
            dp[i][j] = R[a] < R[b] ? a : b;
        }
    }
}

int RMQ(int l, int r) {
    int k = 0;
    while ((1 << (k + 1)) <= r - l + 1)
        k++;
    int a = dp[l][k], b = dp[r - (1 << k) + 1][k]; //保存的是编号
    return R[a] < R[b] ? a : b;
}

int LCA(int u, int v) {
    int x = first[u], y = first[v];
    if (x > y) swap(x, y);
    int res = RMQ(x, y);
    return ver[res];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int cas;
    cin >> cas;
    while (cas--) {
        int n, q, num = 0;
        cin >> n >> q;
        memset(head, -1, sizeof(head));
        memset(vis, false, sizeof(vis));
        for (int i = 1; i < n; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            add(u, v, w, num);
        }
        tot = 0;
        dir[1] = 0;
        dfs(1, 1);
        ST(2 * n - 1);
        while (q--) {
            int u, v;
            cin >> u >> v;
            int lca = LCA(u, v);
            cout << dir[u] + dir[v] - 2 * dir[lca] << '\n';
        }
    }
}
