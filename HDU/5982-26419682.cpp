#include <iostream>
#include <algorithm>
using ll = long long;
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--)
    {
        ll ans = 0;
        int n;
        cin >> n;
        for(int i = 0;i<n;++i)
        {
            ll a,b;
            cin >> a >> b;
            ans += a * b;
        }
        cout << ans << '\n';
    }
}
