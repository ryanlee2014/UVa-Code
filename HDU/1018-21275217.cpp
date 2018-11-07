#include <stdio.h>
#include <math.h>
#define in(x) scanf("%d",&x)
#define ins(x) scanf("%s",x)
#define inf(x) scanf("%lf",&x)
#define inc(x) scanf("%c",&x)
#define gc() getchar()
#define out(x) printf("%d\n",x)
#define od(x,y) printf("%d %d\n",x,y)
#define ms(x) memset(x,0,sizeof(x))
#define msc(x,n) memset(x,n,sizeof(x))
#define cp(x) while(!x.empty())x.pop()
#define rep(i, a, b) for(int i=a;i<b;++i)
#define rvep(i, a, b) for(int i=a;i>=b;--i)
int main(void)
{
    int T;
    in(T);
    while(T--)
    {
        int num;
        in(num);
        double sum=0;
        rep(i,1,num+1)
        {
            sum+=log10(i);
        }
        out((int)ceil(sum));
    }
    return 0;
}