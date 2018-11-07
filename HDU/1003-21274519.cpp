#include <iostream>
#include <cstdio>
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
using namespace std;
int main(void)
{
    int z,n,max,sum;
    int a,b,A,B,t;
    in(z);
    rep(k,1,z+1)
    {
        in(n);
        sum = max = -1001;
        rep(i,1,n+1)
        {
            in(t);
            if(sum+t < t)
                sum = t , a = b = i;    
            else
                sum += t , ++b;
            if(max < sum)
                max = sum , A = a , B = b;
        }
        printf("Case %d:\n%d %d %d\n",k,max,A,B);
        if(k-z) puts("");
    }
    return 0;
}