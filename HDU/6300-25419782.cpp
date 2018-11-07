#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 1005;

struct Node {
    int x, y, id;

    bool operator<(const Node &v) const {
        if (x != v.x) return x < v.x;
        return y < v.y;
    }
} a[maxn * 3];

int n;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= 3 * n; i++) {
            cin >> a[i].x >> a[i].y;
            a[i].id = i;
        }

        sort(a + 1, a + 3 * n + 1);
        for (int i = 1; i <= 3 * n; i += 3) {
            cout << a[i].id << " " << a[i + 1].id << " " << a[i + 2].id << "\n";
        }
    }
}
