#pragma GCC optimize("O3")

#include <iostream>
#include <cstdio>
#include <cstring>
#include <list>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>

using ll = long long;
using lll = __int128;
#define LL long long
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;

int a[1100][1100];
int b[1100][1100];

/*int vis[1100];
int prime[1100], pt = 0;

void init()
{
    for (int i = 2; i < 1100; i++)
    {
        if (!vis[i])
        {
            prime[pt++] = i;
            for (int j = i * 2; j < 1100; j += i)
            {
                vis[j] = 1;
            }
        }
    }
}*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T, p;
    cin >> T;
    while (T--)
    {
        cin >> p;
        for (int i = 0; i < p; ++i)
        {
            for (int j = 0; j < p; ++j)
            {
                a[i][j] = i * j % p;
            }
        }

        for (int i = 0; i < p; ++i)
        {
            cout << a[i][0];
            for (int j = 1; j < p; ++j)
            {
                cout << " " << a[i][j];
            }
            cout << '\n';
        }
        for (int i = 0; i < p; ++i)
        {
            cout << a[i][0];
            for (int j = 1; j < p; ++j)
            {
                cout << " " << a[i][j];
            }
            cout << '\n';
        }
    }
    return 0;
}
