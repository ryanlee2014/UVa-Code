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
it n,m;
cst it maxn=5005;
it a[maxn];
it hsh[maxn<<1];
it num[maxn<<1];
int main(void)
{
    wl(ein(n)&&ein(m))
    {
        rep(i,0,n)in(a[i]);
        ms(num);
        ms(hsh);
        rep(i,0,n)
        {
            rep(j,i+1,n)
            {
                hsh[a[i]+a[j]]=1;
                num[a[i]+a[j]]++;
            }
        }
        for(int i=1e4,j=0;j!=m&&i>=0;i--)
        {
            if(hsh[i])
            {
                wl(num[i]--&&j<m)
                {
                    printf("%d%c",i," \n"[++j==m]);
                }
            }
        }
    }
    return 0;
}