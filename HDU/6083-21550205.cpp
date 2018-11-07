#include <iostream>
#include <cstring>
#define in(x) scanf("%d",&x)
#define inl(x) scanf("%lld",&x)
#define ins(x) scanf("%s",x)
#define inf(x) scanf("%lf",&x)
#define inc(x) scanf("%c",&x)
#define gc() getchar()
#define out(x) printf("%d\n",x)
#define outl(x) printf("%lld\n",x)
#define od(x, y) printf("%d %d",x,y)
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
#define stt struct
#define il inline
#define db double
#define pf printf
typedef long long ll;
typedef void vt;
using namespace std;
cst it INF = 0x3f3f3f3f;
int n, c, bestp, bestw;//物品的个数，背包的容量，最大价值
int p[10000], w[10000], x[10000], bestx[10000];//物品的价值，物品的重量，x[i]暂存物品的选中情况,物品的选中情况
int tmp1[10100],tmp2[10100];
void Backtrack(int i, int cp, int cw)
{ //cw当前包内物品重量，cp当前包内物品价值
    int j;
    if (i > n)//回溯结束
    {
        if (cp > bestp)
        {
            bestp = cp;
            bestw = cw;
            for (int l = 0; l <= n; l++) bestx[l] = x[l];
        }
        else if(cp==bestp)
        {
            ms(tmp1),ms(tmp2);
            it cnt=0;
            it sum1,sum2;
            sum1=sum2=0;
            rep(l,1,n+1)
            {
                if(x[l]){
                    tmp1[cnt++]=l;
                    sum1+=l;
                }
            }
            cnt=0;
            rep(l,1,n+1)
            {
                if(bestx[l]){
                    tmp2[cnt++]=l;
                    sum2+=l;
                }
            }
            if(sum1<sum2)
            {
                bestp = cp;
                bestw = cw;
                for (int l = 0; l <= n; l++) bestx[l] = x[l];
                return;
            }
            if(sum1>sum2)
            {
                return;
            }
            bool f=false;
            for(int l=0;;++l)
            {
                if(tmp1[l]==0&&tmp2[l]!=0)
                {
                    f=true;
                    break;
                }
                if(tmp1[l]==tmp2[l])continue;
                if(tmp1[l]!=0&&tmp2[l]==0)break;
                if(tmp1[l]<tmp2[l])
                {
                    f=true;
                    break;
                }
                if(tmp1[l]>tmp2[l])continue;
            }
            if(f)
            {
                bestp = cp;
                bestw = cw;
                for (int l = 0; l <= n; l++) bestx[l] = x[l];
            }
        }
    }
    else
    {
        for (j = 0; j <= 1; j++)
        {
            x[i] = j;
            if (cw + x[i] * w[i] <= c)
            {
                cw += w[i] * x[i];
                cp += p[i] * x[i];
                Backtrack(i + 1, cp, cw);
                cw -= w[i] * x[i];
                cp -= p[i] * x[i];
            }
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1001.in","r",stdin);
    freopen("test.out","w",stdout);
#endif
    it T;
    in(T);
    rep(kase, 1, T + 1)
    {
        ms(p),ms(w),ms(x);
        ms(bestx);
        bestp = 0;
        bestw = 0;
        in(c), in(n);
        rep(i, 1, n + 1)
        {
            in(p[i]);
            in(w[i]);
        };
        Backtrack(1, 0, 0);
        printf("Case #%d:\n", kase);
        printf("%d %d\n",bestp,bestw);
        bool f = false;
        rep(i, 1, n + 1)
        {
            if (f)
            {
                if (bestx[i])printf(" %d", i);
            }
            el
            {
                if (bestx[i])
                {
                    f = true;
                    printf("%d", i);
                }
            }
            if(i==n&&f)puts("");
        }
    }
    return 0;
}