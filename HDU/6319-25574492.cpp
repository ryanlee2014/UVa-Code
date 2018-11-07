#include <iostream>
#include <queue>
#include <algorithm>
#include <array>

using namespace std;
using ll = long long;
const int maxn = 1e7 + 1e2;
array<int, maxn> a;
int n, m, k, P, Q, R, mod;
ll A, B;
deque<int> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        q.clear();
        cin >> n >> m >> k >> P >> Q >> R >> mod;
        for (int i = 1; i <= k; ++i)cin >> a[i];
        for (int i = k + 1; i <= n; ++i) {
            a[i] = (1ll * P * a[i - 1] + 1ll * Q * i + R) % mod;
        }
        A = B = 0;
        for (int i = n; i; --i) {
            while (!q.empty() && a[q.back()] <= a[i])q.pop_back();
            q.push_back(i);
            if (i + m - 1 <= n) {
                while (q.front() >= i + m) q.pop_front();
                A += i ^ a[q.front()];
                B += i ^ q.size();
            }
        }
        cout << A << " " << B << "\n";
    }
}