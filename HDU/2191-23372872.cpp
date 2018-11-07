#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+1e2;
const int maxm=1e3+1e2;
int dp[maxn],p[maxm],h[maxm],c[maxm];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        memset(dp,0, sizeof(dp));
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++)scanf("%d%d%d",&p[i],&h[i],&c[i]);
        for(int i=1;i<=m;i++)
            for(int j=1;j<=c[i];j++)
                for(int k=n;k>=p[i];k--)
                    dp[k]=max(dp[k-p[i]]+h[i],dp[k]);
        printf("%d\n",dp[n]);
    }
}