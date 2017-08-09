#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define in(x) scanf("%d",&x)
#define ins(x) scanf("%s",&x)
#define inf(x) scanf("%lf",&x)
#define inc(x) scanf("%c",&x)
#define gc() getchar()
#define out(x) printf("%d\n",x)
#define od(x, y) printf("%d %d\n",x,y)
#define ms(x) memset(x,0,sizeof(x))
#define msc(x, n) memset(x,n,sizeof(x))
#define cp(x) while(!x.empty())x.pop()
#define rep(i, a, b) for(int i=a;i<b;++i)
#define rvep(i, a, b) for(int i=a;i>=b;--i)
#define SWAP(a, b)  (a ^= b,b ^= a,a ^= b,1);
using namespace std;

struct Node
{
	int l, r;
	int num;
};
Node node[400010];

int vis[50];

void init(int l, int r, int k)
{
	node[k].l = l;
	node[k].r = r;
	node[k].num = 1;
	int mid = (l + r) >> 1;
	if (l == r)
		return;
	init(l, mid, k << 1);
	init(mid + 1, r, k << 1 | 1);
}

void update(int l, int r, int c, int k)
{
	if (node[k].l == l && node[k].r == r)
	{
		node[k].num = c;
		return;
	}
	if (node[k].num == c)
		return;
	if (node[k].num != -1)
	{
		node[k<<1].num = node[k].num;
		node[k<<1|1].num = node[k].num;
		node[k].num = -1;
	}
	int mid = (node[k].l + node[k].r) >> 1;
	if (l > mid)
		update(l, r, c, k << 1 | 1);
	else if (r <= mid)
		update(l, r, c, k << 1);
	else
	{
		update(l, mid, c, k << 1);
		update(mid + 1, r, c, k << 1 | 1);
	}
}

void query(int l, int r, int k)
{
	if (node[k].num != -1)
	{
		vis[node[k].num] = 1;
		return;
	}
	int mid = (node[k].l + node[k].r) >> 1;
	if (r <= mid)
		query(l, r, k << 1);
	else if (l > mid)
		query(l, r, k << 1 | 1);
	else
	{
		query(l, mid, k << 1);
		query(mid + 1, r, k << 1 | 1);
	}
}

int main(void)
{
	int l, t, o, ans;
	while (~in(l) && ~in(t) && ~in(o))
	{
		init(1, l, 1);
		while (o--)
		{
			char ch;
			int a, b, c;
			getchar();
			inc(ch);
			in(a), in(b);
			if (ch == 'C')
			{
				in(c);
				a > b && SWAP(a, b);
				update(a, b, c, 1);
			}
			else
			{
				a > b && SWAP(a, b);
				ms(vis);
				query(a, b, 1);
				ans = 0;
				rep(i, 1, t + 1) vis[i] == 1 && ++ans;
				out(ans);
			}
		}
	}
	return 0;
}