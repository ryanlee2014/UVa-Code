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
#define elif else if
#define el else
#define wl(x) while(x)
#define pf printf
typedef long long ll;
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 50100;
struct Node
{
    int u,v,w;
    Node(){}
    Node(int u,int v,int w):u(u),v(v),w(w){}
    bool operator<(const Node & v)const
    {
        return u<v.u;
    }
};
int main(void)
{
    int a;
    wl(~in(a))
    {
        int b,c;
        b=c=0;
        rep(i,0,a)
        {
            in(b);
            b<36&&c++;
        }
        out(c);
    }
    return 0;
}