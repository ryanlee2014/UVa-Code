#include <iostream>
#include <cstring>
using namespace std;
#define in(x) scanf("%d",&x)
#define ins(x) scanf("%s",x)
#define inf(x) scanf("%lf",&x)
#define inc(x) scanf("%c",&x)
#define gc() getchar()
#define out(x) printf("%d\n",x)
#define od(x, y) printf("%d %d\n",x,y)
#define ms(x) memset(x,0,sizeof(x))
#define msc(x, n) memset(x,n,sizeof(x))
#define cp(x) while(!x.empty())x.pop()
#define rep(i, a, b) for(int i=a;i<b;++i)
#define rvep(i, a, b) for(int i=a;i>=b;--i)
int tr[32320];

inline int lowbit(int k)
{
    return k & -k;
}

inline void add(int num, int k)
{
    while (k < 32010)
    {
        tr[k] += num;
        k += lowbit(k);
    }
}

inline int sum(int k)
{
    int s = 0;
    while (k)
    {
        s += tr[k];
        k -= lowbit(k);
    }
    return s;
}

int main(void)
{
    int n;
    int w[32120];
    while (~in(n))
    {
        ms(w), ms(tr);
        rep(i, 0, n)
        {
            int x, y;
            in(x), in(y);
            int s = sum(x + 1);
            ++w[s];
            add(1, x + 1);
        }
        rep(i, 0, n) out(w[i]);
    }
    return 0;
}