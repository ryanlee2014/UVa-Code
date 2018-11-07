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
typedef long long ll;
#define MAXN 100010
#define INF 0x3f3f3f3f
#define LL long long
cst it maxn=1e5+6;
ll prime[maxn<<1]={1};
int pcnt=0;//素数下标1~pcnt-1
int factor[maxn<<1]={1,1}; //factor[i]表示i的最小质因子
void Init_Prime(){
    pcnt=1;
    for(ll i = 2 ; i < maxn ; i ++){
        if(!factor[i]) {
            prime[pcnt++]=i;
            factor[i]=i;
        }
        for(ll j = 1 ; j < pcnt && i * prime[j] <  maxn ; j ++)
        {
            factor[i * prime[j]] = prime[j];
            if( !(i % prime[j] ) )
                break;
        }
    }
}
 
ll a[maxn];
ll b[maxn];
int x;
 
int cmp(int a,int b)
{
    return abs(x-a)<abs(x-b);
}
 
int main(void)
{
    Init_Prime();
    it T;
    in(T);
    wl(T--)
    {
        it primecm[30];
        it num;
        in(num);
        ll sum=0;
        ll mx=0;
        rep(i,0,num)
        {
            in(a[i]);
            sum+=a[i];
            mx=max(mx,a[i]);
        }
        ll tmp=sum;
        it cnt=0;
        for(int i=1;tmp!=1&&i<pcnt;++i)
        {
            bool flag=false;
            while(tmp%prime[i]==0)
            {
                flag=true;
                primecm[cnt]=prime[i];
                tmp/=prime[i];
            }
            if(flag)++cnt;
        }
        if(cnt==0)
        {
            outl(sum-mx);
            ctn;
        }
        LL ans=INF;
        for(int p=0;p!=cnt;++p)
        {
            x=primecm[p];
            LL tot=0;
            for(int i=0;i!=num;++i)
            {
                b[i]=a[i]%x;
                tot+=b[i];
            }
            tot/=x;
            sort(b,b+num,cmp);
            LL temp=0;
            for(ll i=0;i!=tot;++i)
                temp+=abs(x-b[i]);
            ans=min(ans,temp);
        }
        printf("%lld\n",ans);
    }
    return 0;
}