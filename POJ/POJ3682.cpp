#include <cstdio>
using namespace std;
#define in(x) scanf("%d",&x)
#define inf(x) scanf("%lf",&x)
#define rep(i, a, b) for(int i=a;i<b;++i)
const int maxn=1024;
double arr[maxn],brr[maxn];
int main(void)
{
	int a;
	double b;
	while(~in(a)&&a&&~inf(b))
	{
		arr[0]=brr[0]=0;
		rep(i,1,a+1)
		{
			arr[i]=arr[i-1]+1/b;
			brr[i]=brr[i-1]+2*arr[i-1]-2*arr[i]+(1+2*arr[i])/b;
		}
		printf("%.3f %.3f\n",arr[a],brr[a]);
	}
	return 0;
}