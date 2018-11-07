#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;


struct Node {
    int son;
    int distance;
};
const int maxn = 40001;

int n;
vector<Node> v[maxn];
int deep[maxn];
int visitnum[maxn << 1];
int visitn[maxn];
int vnum = 1;
int mins[maxn << 1][18];
int dist[maxn];
int fa[maxn];

void visit(int m, int d, int dis) {
    deep[m] = d;
    dist[m] = dis;
    for (auto p = v[m].begin(); p != v[m].end(); p++) {
        visitn[m] = vnum;
        visitnum[vnum++] = m;
        visit((*p).son, d + 1, dis + (*p).distance);
    }
    visitn[m] = vnum;
    visitnum[vnum++] = m;
}

void RMQ() {
    for (int i = 1; i <= 2 * n - 1; i++)mins[i][0] = visitnum[i];
    for (int j = 1; (1 << j) <= 2 * n - 1; j++) {
        for (int i = 1; i <= 2 * n - 1; i++) {
            mins[i][j] = mins[i][j - 1];
            int k = i + (1 << (j - 1));
            if (k <= 2 * n - 1 && deep[mins[i][j]] > deep[mins[k][j - 1]])
                mins[i][j] = mins[k][j - 1];
        }
    }
}

int LCA(int x, int y) {
    int j = 0;
    while ((1 << j) <= y - x)j++;
    --j;
    int min = mins[y + 1 - (1 << j)][j];
    if (deep[min] > deep[mins[x][j]])min = mins[x][j];
    return min;
}

int main() {
    int T, m, x, y, l;
    Node nod;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) {
            v[i].clear();
            fa[i] = i;
        }
        for (int i = 1; i < n; i++) {
            scanf("%d%d%d", &x, &y, &l);
            nod.distance = l;
            nod.son = y;
            v[x].insert(v[x].end(), nod);
            fa[y] = x;
        }
        while (fa[x] != x)x = fa[x];
        visit(x, 1, 0);
        RMQ();
        while (m--) {
            scanf("%d%d", &x, &y);
            int lca_;
            if (visitn[x] <= visitn[y])lca_ = LCA(visitn[x], visitn[y]);
            else lca_ = LCA(visitn[y], visitn[x]);
            printf("%d\n", dist[x] + dist[y] - (dist[lca_] << 1));
        }
    }
    return 0;
}