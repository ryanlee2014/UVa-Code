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
    int t;
    int sum=-1001;
    int start,target;
    int num;
    int big=-1001;
    int cura,curb;
    int temp;
    in(t);
    rep(i,1,t+1)
    {
        in(num);
        sum=big=-1001;
        rep(j,1,num+1)
        {
            in(temp);
            if(sum+temp < temp)
                sum = temp , cura = curb = j;
            else
                sum += temp , ++curb;
            if(sum>big)
                big = sum , start = cura , target = curb;
        }
        printf("Case %d:\n%d %d %d\n",i,big,start,target);
        if(i<t)puts("");
    }
    return 0;
}