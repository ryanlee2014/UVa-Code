#include <iostream>
#include <algorithm>
using namespace std;
const int N = 50005;
int tr[12 * N];

void build(int i, int l, int r)
{
	if (l == r)
	{
		scanf("%d", &tr[i]);
		return;
	}
	int mid = (l + r) >> 1;
	build(i * 2, l, mid);
	build(i * 2 + 1, mid + 1, r);
	tr[i]=max( tr[2 * i] ,tr[2 * i + 1]);
}

void update(int i, int l, int r, int x, int y)
{
	if (l == r)
	{
		tr[i] = y;
		return;
	}
	int mid = (l + r) >> 1;
	if (x <= mid)update(i * 2, l, mid, x, y);
	else update(i * 2 + 1, mid + 1, r, x, y);
	tr[i] = max(tr[2 * i] , tr[2 * i + 1]);
}

int query(int i, int l, int r, int x, int y)
{
	int sum = 0;
	if (x <= l && r <= y)
	{
		sum = tr[i];
		return sum;
	}
	int mid = (l + r) >> 1;
	if (x <= mid) sum = max(sum,query(2 * i, l, mid, x, y));
	if (y > mid) sum = max(sum,query(2 * i + 1, mid + 1, r, x, y));
	return sum;
}

int main(void)
{
	int n,q;
	while(~scanf("%d%d", &n,&q))
	{
		build(1, 1, n);
		while (q--)
		{
			char s[10];
			scanf("%s", s);
			int x, y;
			scanf("%d%d", &x, &y);
			if (s[0] == 'U')update(1, 1, n, x, y);
			else printf("%d\n", query(1, 1, n, x, y));
		}
	}
	return 0;
}