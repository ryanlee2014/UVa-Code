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
stt Time
{
    int hour,min;
    double diff;
    bool operator<(cst Time&v)cst
    {
        if(diff<v.diff)
            return true;
        if(diff>v.diff)
            return false;
        return hour<=v.hour;
    }
};

Time times[10];
int main(void)
{
    int T,i;
    char ch;
    while(ein(T))
    {
        while(T--)
        {
            rep(i,0,5)
            {
                cin>>times[i].hour>>ch>>times[i].min;
                if(times[i].hour>12)
                    times[i].diff=abs(30*(times[i].hour-12)+times[i].min/2.0-6*times[i].min);
                else
                    times[i].diff=abs(30*times[i].hour+times[i].min/2.0-6*times[i].min);
                if(times[i].diff>180)times[i].diff=360-times[i].diff;
            }
            sort(times,times+5);
            printf("%02d:%02d\n",times[2].hour,times[2].min);
        }
    }
    return 0;
}