#include <cstdio>
using namespace std;
int main(void)
{
	int n;
	while(~scanf("%d",&n)&&n)printf("%d\n",n&-n);
	return 0;
}