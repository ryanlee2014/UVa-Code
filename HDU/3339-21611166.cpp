#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
const int inf=0x3f3f3f3f;
#define in(x) scanf("%d",&x)
#define ins(x) scanf("%s",&x)
#define inf(x) scanf("%lf",&x)
#define inc(x) scanf("%c",&x)
#define c() getchar()
#define out(x) printf("%d\n",x)
#define od(x,y) printf("%d %d\n",x,y)
#define ms(x) memset(x,0,sizeof(x))
#define cp(x) while(!x.empty())x.pop()
#define rep(i, a, b) for(int i=a;i<b;++i)
#define rvep(i, a, b) for(int i=a;i>=b;--i)
using namespace std;
int n;
int mp[110][110],vis[110],dis[110];
int dp[10010],backpack[110];
void dijkstra()
{
    int pos,min;
    ms(vis);
    rep(i,0,n+1)dis[i]=mp[0][i];
    rep(i,0,n+1)
    {
        min=inf;
        rep(j,0,n+1)
            if(!vis[j]&&min>dis[j])
            {
                pos=j;
                min=dis[j];
            }
        vis[pos]=1;
        rep(j,0,n+1)(!vis[j]&&dis[j]>dis[pos]+mp[pos][j])&&(dis[j]=dis[pos]+mp[pos][j]);
    }
}
int main(void)
{
    int T,m;
    in(T);
    while(T--)
    {
        in(n),in(m);
        rep(i,0,n+1)rep(j,0,n+1)mp[i][j]=inf;
        int u,v,w;
        rep(i,0,m)
        {
            in(u),in(v),in(w);
            mp[v][u]=mp[u][v]=min(mp[u][v],w);
        }
        dijkstra();
        int sum=0;
        rep(i,1,n+1)
        {
            in(backpack[i]);
            sum+=backpack[i];
        }
        rep(i,1,sum+1)dp[i]=inf;
        dp[0]=0;
        rep(i,1,n+1)rvep(j,sum,backpack[i])dp[j]=min(dp[j],dp[j-backpack[i]]+dis[i]);
        int tmp=sum/2+1;
        int sm=inf;
        rep(i,tmp,sum+1)dp[i]<sm&&(sm=dp[i]);
        if(sm==inf)
            puts("impossible");
        else
            out(sm);
    }
    return 0;
}