#include <bits/stdc++.h>
#define in(x) scanf("%d",&x)
#define ein(x) ~scanf("%d",&x)
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
#define mp make_pair
#define pii pair<int,int>
#define rtn return
#define ope operator
#define cst const
#define it int
#define cr char
#define ctn continue
#define stt struct
#define il inline
#define tpl template
#define cl class
#define db double
#define sf(x) sizeof(x)
#define vt void
#define pf printf
typedef long long ll;
using namespace std;
const int maxn=1e4+1e2;
vector<int>a;
int main(void)
{
    int n;
    while(ein(n))
    {
        a.clear();
        rep(i,0,n)
        {
            it tmp;
            in(tmp);
            a.push_back(tmp);
        }
        sort(a.begin(),a.end());
        deque<int>d(a.begin(),a.end());
        while(!d.empty())
        {
            printf("%d%c",d.back()," \n"[d.size()==1]);
            d.pop_back();
            if(!d.empty())
            {
                printf("%d%c",d.front()," \n"[d.size()==1]);
                d.pop_front();
            }
        }
    }
    return 0;
}