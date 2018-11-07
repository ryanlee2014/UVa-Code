#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <cstring>
#include <queue>
#include <regex>

using namespace std;
using ll = long long;
using lll = __int128;
using pii = pair<int,int>;

const int maxn = 2e5+6;
int n,m,tot;
int h[maxn];
int st[maxn][32-__builtin_clz(maxn)];
int dp[maxn];
bool select[maxn];
int pre[maxn],cnt[maxn];

inline void init_st()
{
    int l = 31 - __builtin_clz(n);
    for(auto i = 0;i<n;++i)st[i][0] = h[i];
    for(int j = 0;j<l;++j) {
        for(int i = 0;i<(1 + n - (1 << j));++i) {
            st[i][j+1] = max(st[i][j],st[i + (1 << j)][j]);
        }
    }
}

int rmq(int l,int r)
{
    int k = 31 - __builtin_clz(r - l + 1);
    return max(st[l][k], st[r - (1 << k) + 1][k]);
}

int first_greater_than_after(int pos,int val)
{
    int l = pos + 1,r = n,mid;
    while(l < r) {
        mid = (l + r ) >> 1;
        if (rmq(pos + 1, mid) <= val) l = mid + 1;
        else r = mid;
    }
    return l;
}

void prepare() 
{
    int _cnt = 1;
    dp[n] = 0;
    for(int i = n - 1;i >= 0;--i) {
        int pos = first_greater_than_after(i,h[i]);
        dp[i] = dp[pos] + 1;
    }
    select[0] = true;
    pre[0] = -1;
    cnt[0] = 1;
    int last = 0,prevh = h[0];
    for(int i = 1;i<n;++i) {
        pre[i] = last;
        if (h[i] > prevh) {
            select[i] = true;
            last = i;
            prevh = h[i];
            ++_cnt;
        }
        else {
            select[i] = false;
        }
        cnt[i] = _cnt;
    }
    /*
    for(int i = 0;i<n;++i)
    {
        cout << "select["<<i<<"]="<<select[i]<<endl;
    }
    */
    tot = _cnt;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--)
    {
        cin >> n >> m;
        for(int i = 0;i<n;++i) cin >> h[i];
        init_st();
        prepare();
        /*
        for(int i = 0;i<n;++i)cout << "dp["<<i<<"]="<<dp[i]<<endl;
        for(int i = 0;i<n;++i)cout << "cnt["<<i<<"]="<<cnt[i]<<endl;
        */
        for(int i = 0;i<m;++i)
        {
            int p,q;
            cin >> p >> q;
            --p;
            if(select[p])
            {
                if(p == 0)
                {
                    // change first element
                    int ans = 1;
                    ans += dp[first_greater_than_after(p,q)];
                    cout << ans << '\n';
                }
                else
                {
                    // not first element
                    if(h[pre[p]] >= q)
                    {
                        //change value to smaller and 
                        //prev high is greater than or equal q
                        int ans = cnt[pre[p]];//ans from start to prev
                        int pos = first_greater_than_after(p,h[pre[p]]);
                        // first element greater than pos
                        cout << ans + dp[pos] << '\n';
                    }
                    else
                    {
                        //change value not smaller or equal than prev
                        //check if there exists at least one element is greater than current modify value but smaller than prev value
                        int ans = cnt[p];
                        int pos = first_greater_than_after(p,q);
                        cout << ans + dp[pos] << '\n';
                    }
                }
            }
            else
            {
                // the element has not been selected
                if(h[pre[p]] >= q)
                {
                    // if prev element is greater or equal than current modify value
                    // it doesn't change the answer.
                    cout << tot << '\n';
                }
                else
                {
                    //cout << "came here" << endl;

                    // q is greater than prev element,may have effected to next element(s)
                    // search first element which greater than q
                    int ans = cnt[pre[p]] + 1;//select this value,so plus one
                    //cout << ans << endl;
                    int pos = first_greater_than_after(p,q);
                    //cout << pos << endl;
                    cout << ans + dp[pos] << '\n';
                }
            }
        }
    }
}

