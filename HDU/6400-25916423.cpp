#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <cstring>
#include <queue>
#include <regex>
#ifdef ONLINE_JUDGE
#define endl '\n'
#endif

using namespace std;
using ll = long long;
using lll = __int128;
using pii = pair<int,int>;

const int maxn = 1e5+6;

int main()
{
    int m,n;
    bool rever = false;
    int T;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while(T--)
    {
        cin >> m >> n;
        array<array<char,210>,210>g;
        for(int i = 0;i<=max(m,n);++i)g[i].fill(0);
        rever = false;
        if(m & 1) {
            // m is odd
            for(int i = 0;i < m;++i)
            {
                for(int j = 0;j < n;++j)
                {
                    if(j >= (n >> 1))
                    {
                        g[i][j] = ')';
                    }
                    else 
                    {
                        g[i][j] = '(';
                    }
                }
            }
        }
        else if(n & 1)
        {
            for(int i = 0;i<m;++i)
            {
                for(int j = 0;j<n;++j)
                {
                    if(i >= (m >> 1))
                    {
                        g[i][j]=')';
                    }
                    else
                    {
                        g[i][j]='(';
                    }
                }
            }
        }
        else
        {
            if(m > n)
            {
                swap(m,n);
                rever = true;
            }
            switch (m)
            {
                case 2:
                    for(int i = 0;i < n;++i)
                    {
                        g[0][i] = '(';
                        g[1][i] = ')';
                    }
                    break;
                case 4:
                    for(int i = 0;i < n;++i)
                    {
                        g[0][i] = '(';
                        if(i < (n >> 1))
                        {
                            g[1][i] = ')';
                            g[2][i] = '(';
                        }
                        else
                        {
                            g[1][i] = '(';
                            g[2][i] = ')';
                        }
                        g[3][i] = ')';
                    }
                    break;
                default:
                    for(int i = 0;i < m;++i)
                    {
                        for(int j = 0;j < n;++j)
                        {
                            if(i == 0 || j == 0) g[i][j] = '(';
                            else if(i == m-1 || j == n-1)g[i][j] = ')';
                            else if((i ^ j) & 1)
                            {
                                // (i & 1) ^ (j & 1)
                                g[i][j] = ')';
                            }
                            else g[i][j] = '(';
                        }
                    }
            }
            }
            if(rever)
            {
                for(int j = 0;j<n;++j)
                {
                    for(int i = 0;i < m;++i)
                    {
                        cout << g[i][j];
                    }
                    cout << endl;
                }
            }
            else 
            {
                for(int i = 0;i < m;++i)
                {
                    for(int j = 0;j < n;++j)
                    {
                        cout << g[i][j];
                    }
                    cout << endl;
                }
            }
        
    }
}

