#include <iostream>

using namespace std;
using ll = long long;

int main() {
    ll T, n;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n;
        cout << (n % 3 == 0 ? (n / 3) * (n / 3) * (n / 3) : n % 4 == 0 ? (n / 2) * (n / 4) * (n / 4) : -1) << '\n';
    }
}