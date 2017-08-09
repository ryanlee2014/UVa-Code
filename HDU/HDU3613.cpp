#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define in(x) scanf("%d",&x)
#define ins(x) scanf("%s",&x)
#define inf(x) scanf("%lf",&x)
#define inc(x) scanf("%c",&x)
#define c() getchar()
#define out(x) printf("%d\n",x)
#define od(x,y) printf("%d %d\n",x,y)
#define ms(x) memset(x,0,sizeof(x))
#define cp(x) while(!x.empty())x.pop()
#define rep(i, a, b) for(int i=a;i<b;++i)
#define rvep(i, a, b) for(int i=a;i>=b;--i)
using namespace std;
int const maxn = 500005;
char str[maxn << 1];
int loop[maxn << 1], val[27], sum[maxn], len;
bool pre[maxn],suf[maxn];

inline void init()
{
	ms(suf),ms(pre),ms(sum);
	len = strlen(str);
	rep(i,1,len+1)sum[i] = sum[i - 1] + val[str[i - 1] - 'a'];
}

inline void input()
{
	rep(i,0,26)in(val[i]);
	ins(str);
}

void solve()
{
	int ans = -0xfffffff;
	rep(i,1,len)
	{
		int tmp = 0;
		if(pre[i])
			tmp += sum[i];
		if(suf[len - i])
			tmp += sum[len] - sum[i];
		ans = tmp > ans ? tmp : ans;
	}
	out(ans);
}

void Manacher()
{
	int maxp = 0;
	rvep(i,len,0)
	{
		str[i * 2 + 2] = str[i];
		str[i * 2 + 1] = '#';
	}
	str[0] = '*';
	rep(i,2,2*len+1)
	{
		if(loop[maxp] + maxp > i)
			loop[i] = min(loop[2 * maxp - i], loop[maxp] + maxp - i);
		else
			loop[i] = 1;
		while(str[i - loop[i]] == str[i + loop[i]])
			++loop[i];
		if(loop[maxp] + maxp < i + loop[i])
			maxp = i;
		if(i - loop[i] == 0)
			pre[loop[i] - 1] = true;
		if(i + loop[i] == 2 * len + 2)
			suf[loop[i] - 1] = true;
	}
	solve();
}

int main(void)
{
	int T;
	in(T);
	while(T--)
	{
		input();
		init();
		Manacher();
	}
}