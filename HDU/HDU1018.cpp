#include <stdio.h>
#include <math.h>
#define in(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define rep(i, a, b) for(int i=a;i<b;++i)
int main(void)
{
	int T;
	in(T);
	while(T--)
	{
		int num;
		in(num);
		double sum=0;
		rep(i,1,num+1)
		{
			sum+=log10(i);
		}
		out((int)ceil(sum));
	}
	return 0;
}