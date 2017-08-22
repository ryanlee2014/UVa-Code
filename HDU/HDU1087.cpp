#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int arr[1111],dp[1111];
int main(void)
{
    int t,temp;
    while(~scanf("%d",&t)&&t)
    {
        for (int i = 1; i <= t; ++i)
        {
            scanf("%d",&arr[i]);
        }
        memset(dp,0, sizeof(dp));
        dp[1]=arr[1];
        for (int i = 2; i <=t ; ++i)
        {
            temp=0;
            for (int j = 1; j < i; ++j)
            {
                if(arr[i]>arr[j]&&dp[j]>temp)temp=dp[j];
            }
            dp[i]=arr[i]+temp;
        }
        temp=0;
        for (int i = 1; i <=t ; ++i)
        {
            if(dp[i]>temp)temp=dp[i];
        }
        printf("%d\n",temp);
    }
    return 0;
}
