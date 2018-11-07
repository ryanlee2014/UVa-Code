#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;
using ll = long long;
using LL = ll;
const int maxn = (int) 1e5 + 1, maxd = 17;
int T, n, m, mx, Log[maxn], a[maxd][maxn];
unsigned int X, Y, Z;

unsigned int rng61() {
    X ^= X << 11;
    X ^= X >> 4;
    X ^= X << 5;
    X ^= X >> 14;
    unsigned int tmp = X ^Y ^Z;
    X = Y;
    Y = Z;
    Z = tmp;
    return Z;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for (int i = 2; i < maxn; ++i)
        Log[i] = Log[i >> 1] + 1;
    cin >> T;
    while (T--) {
        cin >> n >> m >> X >> Y >> Z;
        for (mx = 0; 1 << mx <= n; ++mx);
        while (m--) {
            int L = rng61() % n + 1, R = rng61() % n + 1, v = rng61() & ((1 << 30) - 1);
            if (L > R)
                swap(L, R);
            int d = Log[R - L + 1];
            a[d][L] = max(a[d][L], v);
            a[d][R - (1 << d) + 1] = max(a[d][R - (1 << d) + 1], v);
        }
        for (int i = mx - 1; i > 0; --i)
            for (int j = 1; j + (1 << i) - 1 <= n; ++j) {
                a[i - 1][j] = max(a[i - 1][j], a[i][j]);
                a[i - 1][j + (1 << (i - 1))] = max(a[i - 1][j + (1 << (i - 1))], a[i][j]);
                a[i][j] = 0;
            }
        LL ans = 0;
        for (int i = 1; i <= n; ++i) {
            ans ^= (LL) i * a[0][i];
            a[0][i] = 0;
        }
        cout << ans << "\n";
    }
}