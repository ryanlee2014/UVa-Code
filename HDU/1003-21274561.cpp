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
    int T,num,max,sum;
    int a,b,start,target,temp;
    in(T);
    rep(i,1,T+1)
    {
        in(num);
        sum = max = -1001;
        rep(j,1,num+1)
        {
            in(temp);
            if(sum+temp < temp)
                sum = temp , a = b = j;
            else
                sum += temp , ++b;
            if(max < sum)
                max = sum , start = a , target = b;
        }
        printf("Case %d:\n%d %d %d\n",i,max,start,target);
        if(i-T) puts("");
    }
    return 0;
}