#include <iostream>
#include <algorithm>
#include <cstring>
#define in(x) scanf("%d",&x)
#define ins(x) scanf("%s",&x)
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
using namespace std;
typedef long long ll;
const int maxn = 1000100;
struct Node
{
    int num, id;
    bool operator<(const Node &v) const
    {
        return num < v.num;
    }
};
Node node[maxn];
int arr[maxn];
inline int lowbit(int &t)
{
    return t & -t;
}
ll query(int p)
{
    ll _sum = 0;
    while (p > 0)
    {
        _sum += arr[p];
        p -= lowbit(p);
    }
    return _sum;
}

void modify(int pos, int val)
{
    while (pos <= maxn - 3)
    {
        arr[pos] += val;
        pos += lowbit(pos);
    }
}

int main(void)
{
    int n;
    ll ans;
    while (~in(n))
    {
        rep(i, 1, n + 1)
        {
            in(node[i].num);
            node[i].id = i;
        }
        ms(arr);
        ans = 0;
        sort(node + 1, node + n + 1);
        rep(i, 1, n + 1)
        {
            ans += query(n) - query(node[i].id);
            modify(node[i].id, 1);
        }
        outl(ans);
    }
    return 0;
}