#include <iostream>
#include <cstdio>
#include <cstring>
#include <list>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <complex>
#define in(x) scanf("%d",&x)
#define ein(x) ~scanf("%d",&x)
#define inl(x) scanf("%lld",&x)
#define ins(x) scanf("%s",x)
#define inf(x) scanf("%lf",&x)
#define inc(x) scanf("%c",&x)
#define gc() getchar()
#define out(x) printf("%d\n",x)
#define outl(x) printf("%lld\n",x)
#define od(x, y) printf("%d %d\n",x,y)
#define ms(x) memset(x,0,sizeof(x))
#define msc(x, n) memset(x,n,sizeof(x))
#define cp(x) while(!x.empty())x.pop()
#define rep(i, a, b) for(int i=a;i<b;++i)
#define rvep(i, a, b) for(int i=a;i>=b;--i)
#define elif else if
#define el else
#define wl(x) while(x)
#define sn scanf
#define bl bool
#define mp make_pair
#define pii pair<int,int>
#define rtn return
#define ope operator
#define cst const
#define it int
#define cr char
#define ctn continue
#define stt struct
#define il inline
#define tpl template
#define cl class
#define db double
#define sf(x) sizeof(x)
#define vt void
#define pf printf
typedef long long ll;
using namespace std;
const int maxn = 150*75;
const int SIGMA_SIZE = 26;
struct ACAutomata
{
	int nxt[maxn][SIGMA_SIZE];    //节点
	int fail[maxn]; //失配指针
	int end[maxn]; //end[i]记录以i结尾的字符串个数
	int _max;
	map<int,int>count_arr;
	map<string, int> vis;
	int root, L;
	int newnode()
	{
		for (int i = 0; i < SIGMA_SIZE; i++)
			nxt[L][i] = -1;
		end[L++] = 0;
		return L - 1;
	}
	int idx(char ch)
	{
		return ch - 'a';
	}
	void init()
	{
		L = 0;
		root = newnode();
		count_arr.clear();
		vis.clear();
		_max=0;
	}
	void insert(char buf[])
	{
		int len = strlen(buf);
		int now = root;
		for (int i = 0; i < len; i++)
		{
			char ch = idx(buf[i]);
			if (nxt[now][ch] == -1)
				nxt[now][ch] = newnode();
			now = nxt[now][ch];
		}
		vis[string(buf)] = now;
		end[now]++;
	}
	void build()
	{
		queue<int> q;
		fail[root] = root;
		for (int i = 0; i < SIGMA_SIZE; i++)
			if (nxt[root][i] == -1)
				nxt[root][i] = root;
			else
			{
				fail[nxt[root][i]] = root;
				q.push(nxt[root][i]);
			}
		while (!q.empty())
		{
			int now = q.front();
			q.pop();
			for (int i = 0; i < SIGMA_SIZE; i++)
				if (nxt[now][i] == -1)//若该点不存在，直接将该位置指向失配指针的下一位
					nxt[now][i] = nxt[fail[now]][i];
				else
				{
					fail[nxt[now][i]] = nxt[fail[now]][i];
					q.push(nxt[now][i]);
				}
		}
	}

	il bl find(char *t)
	{
		it n = strlen(t);
		it j = 0;
		rep(i, 0, n)
		{
			it c = idx(t[i]);
			wl(j && !nxt[j][c])j = fail[j];
			j = nxt[j][c];
			if (end[j])return true;
		}
	}
	int query(char buf[])
	{
		int len = strlen(buf);
		int now = root;
		int res = 0;
		for (int i = 0; i < len; i++)
		{
			now = nxt[now][idx(buf[i])];
			int tmp = now;
			while (tmp != root)
			{
				res += end[tmp];
				end[tmp] = 0;   //防止重复，如考虑重复情况请注释掉本行，如Hdu5384
				tmp = fail[tmp];
			}
		}
		return res;
	}

	void count(char *s)
	{
		int n = strlen(s);
		int u = root;
		for (int i = 0; i < n; ++i)
		{
			u = nxt[u][idx(s[i])];
			int temp = u;
			while (temp != root)
			{
				if (end[temp])
				{
					count_arr[temp]++;
					_max = max(_max, count_arr[temp]);
				}
				temp = fail[temp];
			}
		}
	}

	void Debug()
	{
		for (int i = 0; i < L; i++)
		{
			printf("id = %3d,fail = %3d,end = %3d,chi = [", i, fail[i], end[i]);
			for (int j = 0; j < SIGMA_SIZE; j++)
				printf("%2d", nxt[i][j]);
			printf("]\n");
		}
	}
};
char buf[1000][200];
char module[(it)(1e6+1e4)];
ACAutomata ac;
int main()
{
	int n;
	while (ein(n)&&n)
	{
		ac.init();
		for (int i = 0; i < n; i++)
		{
			scanf("%s", buf[i]);
			ac.insert(buf[i]);
		}
		ac.build();
		scanf("%s",module);
		ac.count(module);
		out(ac._max);
		rep(i,0,n)
		{
			if(ac.count_arr[ac.vis[string(buf[i])]] == ac._max)
				puts(buf[i]);
		}
	}
	return 0;
}