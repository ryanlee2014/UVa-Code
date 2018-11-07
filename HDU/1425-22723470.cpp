#include <bits/stdc++.h>
#define it int
#define db double
#define in(x) scanf("%d",&x)
#define out(x) printf("%d",x)
#define rep(i,j,k) for(int i=j;i<k;++i)
#define wl(x) while(x)
#define ms(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long ll;
const int maxn=500500;
it a[maxn<<1];
int main(int argc, char const *argv[])
{
    int n,m;
    while(~in(n)&&~in(m))
    {
        ms(a);
        int tmp;
        it mx=0;
        rep(i,0,n)
        {
            in(tmp);
            a[maxn+tmp]=1;
            mx=max(mx,maxn+tmp);
        }
        for(int i=mx;i>=0&&m;--i)
        {
            if(a[i])
            {
                printf("%d%c",i-maxn," \n"[--m==0]);
            }
        }
    }
    return 0;
}