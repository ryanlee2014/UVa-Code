#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
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
int work(int k)
{
    int cnt=0;
    while(k!=1)
    {
        if(k&1)
        {
            k*=3;
            k+=1;
        }
        else
        {
            k>>=1;
        }
        ++cnt;
    }
    return cnt;
}
int main(void)
{
    int a,b;
    int big;
    while(~in(a)&&~in(b))
    {
        int s,e;
        s=a,e=b;
        if(a>b)swap(a,b);
        big=-1;
        rep(i,a,b+1)
        {
            big=max(big,work(i));
        }
        printf("%d %d %d\n",s,e,big+1);
    }
    return 0;
}