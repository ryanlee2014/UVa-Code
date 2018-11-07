#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define in(x) scanf("%d",&x)
#define inl(x) scanf("%lld",&x)
#define ins(x) scanf("%s",x)
#define inf(x) scanf("%lf",&x)
#define inc(x) scanf("%c",&x)
#define gc() getchar()
#define out(x) printf("%d\n",x)
#define outl(x) printf("%lld\n",x)
#define od(x, y) printf("%d %d\n",x,y)
#define ms(x) memset(x,0,sizeof(x))
#define msc(x, n) memset(x,n,sizeof(x))
#define cp(x) while(!x.empty())x.pop()
#define rep(i, a, b) for(int i=a;i<b;++i)
#define repl(i, a, b) for(ll i=a;i<b;++i)
#define rvep(i, a, b) for(int i=a;i>=b;--i)
#define elif else if
#define el else
#define wl(x) while(x)
#define sn scanf
#define bl bool
#define mp make_pair
#define pii pair<int,int>
#define rtn return
#define ope operator
#define cst const
#define it int
#define stt struct
#define pf printf
typedef long long ll;
typedef void vt;
ll MOD = 998244353;
it cnt[1000010][30];
ll tmp[1000010];
it size[1000010];
ll p[1000010];
bl isprime[1000010];
int pt = 0;

int main(void)
{
    it t;
    in(t);
    memset(isprime, 1, sizeof(isprime));
    pt = 0;
    for (int i = 2; i < 1000010; ++i)
    {
        if (isprime[i])
            p[pt++] = i;
        for (int j = 0; j < pt; ++j)
        {
            if (i * p[j] >= 1000010)
                break;
            isprime[i * p[j]] = 0;
            if (i % p[j] == 0) break;
        }
    }
    ll l, r, k;
    wl (t--)
    {
        inl(l), inl(r), inl(k);
        ms(size);
        repl(i, l, r + 1)
        {
            tmp[i - l] = i;
        }
        for (ll i = p[0], q = 0; q < pt; i = p[++q])
        {
            for (ll j = l / i * i; j <= r; j += i)
            {
                if (j >= l && j <= r)
                {
                    cnt[j - l][++size[j - l]] = 0;
                    wl (!(tmp[j - l] % i))
                    {
                        if (!tmp[j - l])
                            exit(0);
                        tmp[j - l] /= i;
                        cnt[j - l][size[j - l]]++;
                    }
                }
            }
        }

        ll d = 0;
        repl(i, l, r + 1)
        {
            ll res = 1;
            rep(j, 1, size[i - l] + 1)
            {
                res = (res * ((k * (cnt[i - l][j]) + 1) % MOD)) % MOD;
            }
            if (tmp[i - l] != 1)
            {
                res = res * (k + 1) % MOD;
            }
            d = (d + res) % MOD;
        }
        outl(d);
    }
    return 0;
}