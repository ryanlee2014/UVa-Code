#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    cout << setprecision(0) << setiosflags(ios::fixed);
    while(T--)
    {
        int n;
        cin >> n;
        cout << pow(2,n) << '\n';
    }
}