#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;
const int inf = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    int cnt = 0;
    while (T--) {
        cout<<"Problem "<<++cnt + 1000<<":"<<"\n";
        int n, m;
        cin >> n >> m;
        int minCheck = inf;
        for (int i = 0; i < n; ++i) {
            int tmp;
            cin >> tmp;
            minCheck = min(minCheck, tmp);
        }
        auto minTeam = inf;
        for (int i = 0; i < m; ++i) {
            int tmp;
            cin >> tmp;
            minTeam = min(minTeam, tmp);
        }
        cout<<"Shortest judge solution: "<<minCheck<<" bytes."<<"\n";
        if(minTeam == inf) {
            cout << "Shortest team solution: N/A bytes."<<"\n";
        }
        else
            cout<<"Shortest team solution: "<<minTeam<<" bytes."<<"\n";
#ifndef ONLINE_JUDGE
        cout.flush();
#endif
    }
}