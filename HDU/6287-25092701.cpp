#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;
const int maxn = static_cast<const int>(1e5 + 6);
vector<int> factor[maxn];

int query(int l, int r, int x) {
    return static_cast<int>(upper_bound(factor[x].begin(), factor[x].end(), r) -
                            lower_bound(factor[x].begin(), factor[x].end(), l));
}

bool solve(int l, int r, int d) {
    for (int i = 2; i * i <= d; i++) {
        if (d % i == 0) {
            int cnt = 0;
            while (d % i == 0) {
                cnt++;
                d /= i;
            }
            if (cnt > query(l, r, i))
                return false;
        }
    }
    if (d > 1) {
        if (query(l, r, d) < 1)
            return false;
    }

    return true;
}

bool need_clear = false;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        if (need_clear) {
            for (auto &i : factor) i.clear();
        }
        for (int i = 1, temp; i <= n; i++) {
            cin >> temp;
            for (int j = 2; j * j <= temp; j++) {
                while (!(temp % j)) {
                    temp /= j;
                    factor[j].push_back(i);
                }
            }
            if (temp > 1) factor[temp].push_back(i);
        }
        need_clear = true;
        while (m--) {
            int l, r, d;
            cin >> l >> r >> d;
            cout << (solve(l, r, d) ? "Yes" : "No") << "\n";
        }
#ifndef ONLINE_JUDGE
        cout.flush();
#endif
    }
    return 0;
}
