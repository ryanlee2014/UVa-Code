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
stt Node
{
    it l,r;
    Node(){}
    Node(it l,it r):l(l),r(r){}
    bool operator<(const Node&rhs)const
    {
        if(r!=rhs.r)return r<rhs.r;
        return l<rhs.l;
    }
};
Node node[110];
int main(void)
{
    int num;
    wl(ein(num)&&num)
    {

        rep(i,0,num)
        {
            in(node[i].l),in(node[i].r);
        }
        sort(node,node+num);
        int cnt=0,pos=0;
        rep(i,0,num)
        {
            if(pos<=node[i].l)
            {
                pos=node[i].r;
                ++cnt;
            }
            
        }
        out(cnt);
    }
    return 0;
}