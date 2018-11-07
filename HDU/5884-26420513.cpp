#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <queue>
using ll = long long;
using LL = ll;
using namespace std;
const int maxn = 1e5 + 6;
ll arr[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    int n;
    ll tot;
    cin >> T;
    auto f = [&](int k) -> bool {
        LL sum = 0, pre = 0;
        int inx = 0, cnt = 0;
        priority_queue <LL, vector<LL>, greater<LL>> q;
        if ((n - 1) % (k - 1)) { for (int i = 0; i < ((k - 1) - (n - 1) % (k - 1)); ++i) q.push(0); }
        while (inx < n) {
            if (cnt < k) {
                if (!q.empty() && q.top() < arr[inx]) {
                    pre += q.top();
                    q.pop();
                    ++cnt;
                }
                else {
                    pre += arr[inx++];
                    ++cnt;
                }
            }
            else {
                cnt = 0;
                if (sum + pre > tot) return false;
                sum += pre;
                q.push(pre);
                pre = 0;
            }
        }
        while (!q.empty()) {
            if (cnt < k) {
                pre += q.top();
                q.pop();
                ++cnt;
            }
            else {
                cnt = 0;
                sum += pre;
                if (sum > tot) return false;
                q.push(pre);
                pre = 0;
            }
        }
        if (sum + pre > tot) return false;
        return true;
    };

    while (T--) {

        cin >> n >> tot;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        int l = 0, r = n;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (f(mid))r = mid;
            else l = mid + 1;
        }
        cout << l << '\n';
    }
}
