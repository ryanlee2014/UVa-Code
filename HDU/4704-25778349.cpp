#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <array>

using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
string s;

ll quickpow(ll x, ll a) {
    ll ans = 1;
    while (a) {
        if (a & 1)
            ans = ans * x % mod;
        x = x * x % mod;
        a >>= 1;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while (cin >> s) {
        ll n = 0;
        for (auto i:s) {
            n = (n * 10 + i - '0') % (mod - 1);
        }
        n = (n - 1 + mod - 1) % (mod - 1) + (mod - 1);
        cout << quickpow(2, n) << '\n';
    }
    return 0;
}
