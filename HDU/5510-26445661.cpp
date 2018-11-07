#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

using ll = long long;
using lll = __int128;
using pii = pair<int,int>;

const int maxn = 1e3+6;
string s[maxn];
int fa[maxn];

int find(int x) { return fa[x] == x ? x : (fa[x] = find(fa[x])); }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T, n;
    cin >> T;
    for (int kase = 1; kase <= T; kase++) {
        cout << "Case #" << kase << ": ";
        cin >> n;
        iota(fa, fa + n + 1, 0);
        for (int i = 1; i <= n; i++) {
            cin >> s[i];
        }
        int ans = -1;
        for (int i = 1; i < n; i++) if (s[i + 1].find(s[i]) != s[i + 1].npos) fa[i] = i + 1;
        for (int i = 1; i <= n; find(i++));
        for (int i = 2; i <= n; i++) {
            for (int j = i - 1; j > 0; j = lower_bound(fa + 1, fa + j + 1, fa[j]) - fa - 1) {
                if (s[i].find(s[j]) == s[i].npos) ans = i;
                if (j == 1) break;
            }
        }
        cout << ans << '\n';
    }
}
