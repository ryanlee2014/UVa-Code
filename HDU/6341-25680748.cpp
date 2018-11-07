#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <array>

using namespace std;
using ll = long long;
const int maxn = 20;
int T, ans, tot;
array<array<char, maxn>, maxn>tmp;
array<string,maxn>matrix;
array<int, maxn> vis;

void rotate(int x, int y) {
    for (int i = x; i < x + 4; ++i)
        for (int j = y; j < y + 4; ++j)
            tmp[x + j % 4][y + 3 - i % 4] = matrix[i][j];

    for (int i = x; i < x + 4; ++i)
        for (int j = y; j < y + 4; ++j)
            matrix[i][j] = tmp[i][j];
}

bool check(int a, int b) {
    for (int i = a; i < a + 4; ++i) {
        tot++;
        for (int j = 0; j < b + 4; ++j) {
            if (vis[matrix[i][j]] == tot)
                return false;
            vis[matrix[i][j]] = tot;
        }
    }
    for (int i = b; i < b + 4; ++i) {
        tot++;
        for (int j = 0; j < a + 4; ++j) {
            if (vis[matrix[j][i]] == tot)
                return false;
            vis[matrix[j][i]] = tot;
        }
    }
    return true;
}

void dfs(int x, int y, int sum) {
    if (sum >= ans) return;
    if (x == 4) {
        ans = min(ans, sum);
        return;
    }
    if (y == 4) {
        dfs(x + 1, 0, sum);
        return;
    }
    for (int i = 0; i < 4; ++i) {
        if (check(x * 4, y * 4)) dfs(x, y + 1, sum + i);
        rotate(x * 4, y * 4);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--) {
        for (int i = 0; i < 16; ++i) {
            cin >> matrix[i];
        }
        for (int i = 0; i < 16; ++i)
            for (int j = 0; j < 16; ++j)
                if (isdigit(matrix[i][j])) matrix[i][j] -= '0';
                else matrix[i][j] -= 'A' - 10;
        ans = 50;
        dfs(0, 0, 0);
        cout << ans << "\n";
    }
}