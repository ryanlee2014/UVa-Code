#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn=2010;
int dp[maxn];
int one[maxn];
int two[maxn];
int main(void)
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(dp,0, sizeof(dp));
        memset(one,0, sizeof(one));
        memset(two,0, sizeof(two));
        int people;
        scanf("%d",&people);
        for (int i = 1; i <=people ; ++i)
        {
            scanf("%d",&one[i]);
        }
        for (int i = 2; i <=people ; ++i)
        {
            scanf("%d",&two[i]);
        }
        dp[1]=one[1];
        for (int i = 2; i <=people ; ++i)
        {
            dp[i]=min(dp[i-1]+one[i],dp[i-2]+two[i]);
        }
        int hour=dp[people]/3600+8;
        int minute=dp[people]/60%60;
        int second=dp[people]%60;
        printf("%02d:%02d:%02d am\n", hour, minute, second);
    }
    return 0;
}