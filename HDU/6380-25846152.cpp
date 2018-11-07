#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
using namespace std;
const int maxn = 2e5+6;
array<int,maxn>degree;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--)
    {
         int n,m,k;
         cin >> n >> m >> k;
         for(int i = 0;i<=n;++i) {
             degree[i] = 0;
         }
         for(int i = 0;i<m;++i)
         {
             int u,v;
             cin >> u >> v;
             ++degree[u];
             ++degree[v];
         }
         int ans = min(*max_element(degree.begin(),degree.begin() + n) + k + n - m - 1,n - 1);
         cout << ans << '\n';
    }
}