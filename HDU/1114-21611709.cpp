#include <iostream>
#include <cstring>
#include <algorithm>
#define in(x) scanf("%d",&x)
using namespace std;

int dp[10010];
int v[1001];
int w[1001];
int N,V;
const int inf=0x3f3f3f3f;
void solve()
{
    for(int i=0;i<=V;i++)
        dp[i]=inf;
    dp[0]=0;
    for(int i=0;i<N;i++)
        for(int j=w[i];j<=V;j++)
            dp[j]=min(dp[j],dp[j-w[i]]+v[i]);
}
int main(void)
{
    int t;
    in(t);
    while(t--)
    {
        int a,b;
        in(a);
        in(b);
        V=b-a;
        in(N);
        for(int i=0;i<N;i++)
            in(v[i]),in(w[i]);
        solve();
        if(dp[V]!=inf)
            printf("The minimum amount of money in the piggy-bank is %d.\n",dp[V]);
        else
            puts("This is impossible.");
    }
    return 0;
}