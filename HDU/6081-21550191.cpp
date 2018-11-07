#include <iostream>
#include <cstring>
#include <map>
#include <vector>
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
#define rvep(i, a, b) for(int i=a;i>=b;--i)
#define elif else if
#define el else
#define wl(x) while(x)
#define sn scanf
#define bl bool
#define pii pair<int,int>
#define rtn return
#define ope operator
#define cst const
#define it int
#define stt struct
#define il inline
#define db double
#define pf printf
#define vt void
typedef long long ll;
using namespace std;
cst it INF = 0x3f3f3f3f;
using namespace std;
const int maxn = 1e5 + 10;
vector<int> G[maxn];
map<int, int> mp1, mp2;
int fa[2 * maxn];
il it find(int x)
{
    if (x != fa[x])fa[x] = find(fa[x]);
    return fa[x];
}
it mat[3010][3010];

il vt merge(it x, it y)
{
    it fx = find(x);
    it fy = find(y);
    if (fx != fy)fa[fx] = fy;
}
it n, m;
it main(vt)
{
    while (~in(n) && ~in(m))
    {
        ms(mat);
        mp1.clear();
        mp2.clear();
        rep(i, 1, n + 1)G[i].clear();
        rep(i, 1, n + 1)fa[i] = i;
        rep(i, 1, m + 1)
        {
            it u, v, w;
            in(u), in(v), in(w);
            if (mat[u][v])
            {
                mat[u][v] += w;
                mat[v][u] += w;
            }
            else
            {
                mat[u][v] = w;
                mat[v][u] = w;
            }
            merge(u, v);
        }
        rep(i, 1, n + 1)
            rep(j, 1, n + 1)
            {
                if (i == j) continue;
                mp1[i] += (mat[i][j]);
            }
        rep(i,1,n+1)
        {
            mp2[find(i)]=(mp2[find(i)]?min(mp2[find(i)], mp1[i]):mp2[find(i)] = mp1[i]);
            G[find(i)].push_back(i);
        }
        ll sum=0;
        rep(i,1,n+1)
        {
            find(i)==i&&G[i].size()>1&&(sum+=mp2[i]);
        }
        outl(sum);
    }
    return 0;
}