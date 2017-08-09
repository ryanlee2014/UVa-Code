#include <cstdio>
using namespace std;
const int maxn = 50005;
int n, k, fa[maxn], pai[maxn];
inline void init()
{
	for (int i = 0; i <= n; ++i)
		fa[i] = i, pai[i] = 0;
}

int find(int x)
{
	if (x == fa[x])return x;
	int fx = fa[x];
	fa[x] = find(fa[x]);
	pai[x] = (pai[x] + pai[fx]) % 3;
	return fa[x];
}

inline bool combine(int x, int y, int d)
{
	int a = find(x);
	int b = find(y);
	if (a == b)
	{
		if (d == 1 && pai[x] != pai[y])return false;
		if (d == 2)
		{
			if (pai[x] == 2 && pai[y] != 1)return false;
			if (pai[x] == 1 && pai[y] != 0)return false;
			if (pai[x] == 0 && pai[y] != 2)return false;
		}
		return true;
	}
	fa[a] = b;
	if (d == 2)
		pai[a] = (pai[y] - pai[x] + 4) % 3;
	else
		pai[a] = (pai[y] - pai[x] + 3) % 3;
	return true;
}
int main(void)
{
	int x, y, d;
	scanf("%d%d", &n, &k);
	init();
	int cnt = 0;
	for (int i = 0; i < k; ++i)
	{
		scanf("%d%d%d", &d, &x, &y);
		if (x > n || y > n || d == 2 && x == y)
		{
			++cnt;
			continue;
		}
		if (!combine(x, y, d))++cnt;
	}
	printf("%d\n", cnt);
	return 0;
}