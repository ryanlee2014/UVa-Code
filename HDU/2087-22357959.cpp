#include <iostream>
#include <cstdio>
#include <cstring>
#include <list>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <complex>
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
cst it maxn=1e3+50;
it nxt[maxn];
cr s1[maxn],s2[maxn];

il vt getNext()
{
    it len=strlen(s2);
    nxt[0]=-1;
    it k=-1,j=0;
    wl(j<len-1)
    {
        if(!~k||s2[j]==s2[k])
        {
            ++k,++j;
            if(s2[j]!=s2[k])
                nxt[j]=k;
            else
                nxt[j]=nxt[k];
        }
        else
            k=nxt[k];
    }
}

il it kmp()
{
    it cnt=0;
    it i=0,j=0;
    it slen=strlen(s1);
    it tlen=strlen(s2);
    while(i<slen)
    {
        if(!~j||s1[i]==s2[j])
            ++i,++j;
        else j=nxt[j];
        if(j==tlen)++cnt,j=0;
    }
    rtn cnt;
}

int main(void)
{
    while(~scanf("%s",s1)&&s1[0]!='#')
    {
        scanf("%s",s2);
        getNext();
        out(kmp());
    }
    return 0;
}