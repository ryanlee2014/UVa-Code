#include <bits/stdc++.h>
#define it int
#define db double
#define in(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define rep(i,j,k) for(int i=j;i<k;++i)
#define wl(x) while(x)
#define ms(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long ll;
const int maxn=2e6+1e2;
int hsh[maxn];
int p[maxn];
int main(int argc, char const *argv[])
{
    rep(i,1,300)p[i]=i*i;
    int a,b,c,d;
    while(~in(a)&&~in(b)&&~in(c)&&~in(d))
    {
        if(a>0&&b>0&&c>0&&d>0||a<0&&b<0&&c<0&&d<0)
        {
            out(0);
            continue;
        }
        ms(hsh);
        int sum=0;
        rep(i,1,101)
        {
            rep(j,1,101)
            {
                hsh[a*p[i]+b*p[j]+(maxn>>1)]++;
            }
        }
        rep(i,1,101)
        {
            rep(j,1,101)
            {
                sum+=hsh[-(c*p[i]+d*p[j])+(maxn>>1)];
            }
        }
        out(sum<<4);
    }
    return 0;
}