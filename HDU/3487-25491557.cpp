#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

#define key_val son[son[root][1]][0]
const int N = 300010, INF = 0x3f3f3f3f;
int son[N][2], pre[N], siz[N];
int key[N], val[N], lazy[N];
int root, num, cnt;
int n, m;

void new_node(int &x, int fa, int v) {
    x = ++num;
    pre[x] = fa, key[x] = v;
    siz[x] = 1, lazy[x] = 0;
    son[x][0] = son[x][1] = 0;
}

void push_up(int x) {
    siz[x] = siz[son[x][0]] + siz[son[x][1]] + 1;
}

void push_down(int x) {
    if (lazy[x]) {
        lazy[son[x][0]] ^= 1, lazy[son[x][1]] ^= 1;
        swap(son[x][0], son[x][1]);
        lazy[x] = 0;
    }
}

void _rotate(int x, int dir) {
    int y = pre[x];
    push_down(y), push_down(x);
    son[y][!dir] = son[x][dir], pre[son[x][dir]] = y;
    if (pre[y]) son[pre[y]][son[pre[y]][1] == y] = x;
    pre[x] = pre[y];
    son[x][dir] = y, pre[y] = x;
    push_up(y);
}

void splay(int x, int goal) {
    push_down(x);
    while (pre[x] != goal) {
        int y = pre[x];
        if (pre[y] == goal) _rotate(x, son[y][0] == x);
        else {
            int dir = son[pre[y]][0] == y;
            if (son[y][dir] == x) _rotate(x, !dir), _rotate(x, dir);
            else _rotate(y, dir), _rotate(x, dir);
        }
    }
    push_up(x);
    if (goal == 0) root = x;
}

int get_subs(int x) {
    push_down(x);
    int t = son[x][1];
    push_down(t);
    while (son[t][0]) t = son[t][0], push_down(t);
    return t;
}

int get_kth(int k) {
    int x = root;
    push_down(x);
    while (siz[son[x][0]] + 1 != k) {
        if (siz[son[x][0]] + 1 > k) x = son[x][0];
        else k -= (siz[son[x][0]] + 1), x = son[x][1];
        push_down(x);
    }
    return x;
}

void build(int &x, int l, int r, int fa) {
    if (l > r) return;
    int mid = (l + r) >> 1;
    new_node(x, fa, mid);
    build(son[x][0], l, mid - 1, x);
    build(son[x][1], mid + 1, r, x);
    push_up(x);
}

void init() {
    root = num = 0;
    son[root][0] = son[root][1] = siz[root] = pre[root] = 0;
    key[root] = val[root] = lazy[root] = 0;
    new_node(root, 0, -INF);
    new_node(son[root][1], root, -INF);
    build(key_val, 1, n, son[root][1]);
    push_up(son[root][1]), push_up(root);
}

void cut(int a, int b, int c) {
    splay(get_kth(a), 0);
    splay(get_kth(b + 2), root);
    int tmp = key_val;
    key_val = 0;
    push_up(son[root][1]), push_up(root);
    splay(get_kth(c + 1), 0);
    splay(get_subs(root), root);
    key_val = tmp, pre[key_val] = son[root][1];
    push_up(son[root][1]), push_up(root);
}

void _reverse(int a, int b) {
    splay(get_kth(a), 0);
    splay(get_kth(b + 2), root);
    lazy[key_val] ^= 1;
}

void inorder(int x) {
    if (!x) return;
    push_down(x);
    inorder(son[x][0]);
    if (key[x] > 0) cout << key[x] << " \n"[++cnt == n];
    inorder(son[x][1]);
}

int main() {
    string str;
    int a, b, c;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while (cin >> n >> m && ~n && ~m) {
        init();
        for (int i = 1; i <= m; i++) {
            cin >> str >> a >> b;
            if (str[0] == 'C') {
                cin >> c;
                cut(a, b, c);
            } else _reverse(a, b);
        }
        cnt = 0;
        inorder(root);
    }

}