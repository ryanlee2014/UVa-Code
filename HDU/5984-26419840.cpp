#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
using ll = long long;
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    cout << setiosflags(ios::fixed) << setprecision(6);
    while(T--)
    {
        double a,b;
        cin >> a >> b;
        if(a <= b) {
            cout << 0.0 << '\n';
            continue;
        }
        cout << round((log(a) + 1 - log(b)) * 1e6) / 1e6 << '\n';
    }
}
