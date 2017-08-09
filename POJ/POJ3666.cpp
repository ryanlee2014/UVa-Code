#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 2010;
const int INF = 0x3f3f3f3f;
LL dp[maxn],A[maxn],B[maxn];
inline LL abs(LL a)
{
	return a<0?-a:a;
}
int main(void)
{
	int n;
	while(~scanf("%d",&n))
	{
		memset(dp,0,sizeof(dp));
		for(int i = 0; i < n; ++i)
		{
			scanf("%lld",&A[i]);
			B[i] = A[i];
		}
		sort(B,B+n);
		LL ans = INF;
		for(int i = 0; i < n; ++i)
		{
			LL minV = INF;
			for(int j = 0; j < n; ++j)
			{
				minV = min(minV,dp[j]);
				dp[j] = abs(B[j] - A[i]) + minV;
				if(i + 1 == n)
					ans = min(ans,dp[j]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}