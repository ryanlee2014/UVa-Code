#include <cstdio>
#include <algorithm>
using namespace std;
int dan[1010],dp[1010];
int main(void)
{
    int t,ans;
    while(ans=0,~scanf("%d",&t))
    {
        for (int i = 0; i < t; ++i)scanf("%d",&dan[i]),dp[i]=1;
        for (int i = 0; i < t; ++i)for (int j = 0; j < i; ++j)dan[i]>dan[j]&&(dp[i]=max(dp[i],dp[j]+1));
        for (int i = 0; i < t; ++i)    ans=max(ans,dp[i]);
        printf("%d\n",ans);
    }
    return 0;
}