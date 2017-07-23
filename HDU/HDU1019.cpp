#include <cstdio>
#include <regex>
#include <algorithm>
using namespace std;
#define in(x) scanf("%d",&x)
#define ins(x) scanf("%s",x)
#define inf(x) scanf("%lf",&x)
#define inc(x) scanf("%c",&x)
#define gc() getchar()
#define out(x) printf("%d\n",x)
#define od(x,y) printf("%d %d\n",x,y)
#define ms(x) memset(x,0,sizeof(x))
#define msc(x,n) memset(x,n,sizeof(x))
#define cp(x) while(!x.empty())x.pop()
#define rep(i, a, b) for(int i=a;i<b;++i)
#define rvep(i, a, b) for(int i=a;i>=b;--i)
typedef long long ll;
int main(void)
{
	int T;
	in(T);
	while(T--)
	{
		int num;
		in(num);
		ll ans;
		ll tmp;
		rep(i,0,num)
		{
			in(tmp);
			if(i==0)ans=tmp;
			ans=ans*tmp/__gcd(ans,tmp);
		}
		printf("%lld\n",ans);
	}
	return 0;
}