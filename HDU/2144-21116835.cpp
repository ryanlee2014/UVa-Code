#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define in(x) scanf("%d",&x)
#define ins(x) scanf("%s",&x)
#define inf(x) scanf("%lf",&x)
#define ms(x) memset(x,0,sizeof(x))
#define rep(i, a, b) for(int i=a;i<b;++i)
const int maxn=199;
int fa[maxn],dp[maxn][maxn],len[maxn];
char str[maxn][maxn];
int find(int x)
{
    if(x==fa[x])return x;
    else return fa[x]=find(fa[x]);
}

int max_len(int x,int y)
{
    int max=0;
    ms(dp);
    rep(i,1,len[x]+1)
    {
        dp[i][0]=0;
        rep(j,1,len[y]+1)
        {
            if(str[x][i]==str[y][j])dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=0;
            if(dp[i][j]>max)max=dp[i][j];
        }
    }
    return max;
}


int main(void)
{
    int kase=0;
    int a,b,n;
    double p;
    while(~in(n)&&~inf(p))
    {
        rep(i,0,n)fa[i]=i;
        rep(i,0,n)
        {
            scanf("%s",str[i]+1);
            str[i][0]=' ';
            len[i]=strlen(str[i])-1;
            rep(j,0,i)
            {
                a=find(i);
                b=find(j);
                if(a==b)continue;
                int t=max_len(i,j);
                if(t*100.0/len[i]>p&&t*100.0/len[j]>p)
                    fa[a]=b;
            }
        }
        int ans=0;
        rep(i,0,n)if(fa[i]==i)++ans;
        printf("Case %d:\n%d\n",++kase,ans);
    }
    return 0;
}