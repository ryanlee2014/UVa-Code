#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#define in(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define ms(x) memset(x,0,sizeof(x))
using namespace std;
const int maxn=1e6+100;
char str[maxn];
int dict[maxn];
void init()
{
	int len=strlen(str);
	int i=0;
	int j=-1;
	dict[0]=-1;
	while(i<len)
	{
		if(j==-1||str[i]==str[j])
		{
			++i,++j;
			dict[i]=j;
		}
		else
		{
			j=dict[j];
		}
	}
}

void kmp()
{
	int i=1;
	int len=strlen(str);
	while(i<len)
	{
		++i;
		int cmp=i-dict[i];
		if(i%cmp==0&&i/cmp>1)
		{
			printf("%d %d\n",i,i/cmp);
		}
	}
}

int main(void)
{
	int t;
	int f=0;
	while(~in(t)&&t)
	{
		printf("Test case #%d\n",++f);
		getchar();
		scanf("%s",str);
		init();
		kmp();
		puts("");
	}
	return 0;
}