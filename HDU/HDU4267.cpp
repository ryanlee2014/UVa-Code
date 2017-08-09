#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define in(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define ms(x) memset(x,0,sizeof(x))
using namespace std;
const int maxn=50005;
int arr[maxn][11][11];
int n,num[maxn];

inline int lowbit(int x)
{
	return x& (-x);
}

inline void add(int x,int y,int mod,int c)
{
	while(x>0)arr[x][y][mod]+=c,x-=lowbit(x);
}

inline int sum(int x,int a)
{
	int ans=0;
	while(x<maxn)
	{
		for(int i=1;i<=10;++i)ans+=arr[x][i][a%i];
		x+=lowbit(x);
	}
	return ans;
}

int main(void)
{
	while(~in(n))
	{
		for (int i = 1; i <=n ; ++i)in(num[i]);
		ms(arr);
		int t;
		in(t);
		while(t--)
		{
			int op,a,b,k,c;
			in(op);
			if(op==1)
			{
				in(a),in(b),in(k),in(c);
				add(b,k,a%k,c);
				add(a-1,k,a%k,-c);
			}
			else
			{
				in(a);
				int ans=sum(a,a);
				out(ans+num[a]);
			}
		}
	}
	return 0;
}