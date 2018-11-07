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
    char name[30];
    int cnt;
    int per[20];
    int sum;
    Node(){}
    bool operator<(cst Node&v)cst
    {
        if(sum!=v.sum)return sum>v.sum;
        return strcmp(name,v.name)<0;
    }
};
Node node[2010];
int num[20];

int main(void)
{
    int n,m,line;
    while(ein(n)&&n)
    {
        in(m),in(line);
        rep(i,0,m)in(num[i]);
        ms(node);
        rep(i,0,n)
        {
            ins(node[i].name);
            in(node[i].cnt);
            rep(j,0,node[i].cnt)in(node[i].per[j]);
        }
        int sumn=0;
        rep(i,0,n)
        {
            rep(j,0,node[i].cnt)
            {
                node[i].sum+=num[node[i].per[j]-1];
            }
            if(node[i].sum>=line)++sumn;
        }
        sort(node,node+n);
        out(sumn);
        rep(i,0,n)
        {
            if(node[i].sum>=line)
                printf("%s %d\n",node[i].name,node[i].sum);
        }
    }
    return 0;
}